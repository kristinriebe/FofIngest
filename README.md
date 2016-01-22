FofIngest
==========

This code uses the DBIngestor library (https://github.com/adrpar/DBIngestor) to ingest Friends-Of-Friends (FOF) catalogues into a database.

It assumes that these catalogues come in the binary format used by Stefan Gottl&ouml;ber. Thus it is very specific, but can serve as an example for how to use the DBIngestor library and write your own binary reader.

The code is based on the *HelloWord* program delivered with the DBIngestor.

For any questions, please contact me at
Kristin Riebe, kriebe@aip.de


Data files
-----------
The FOF catalogues were created by Stefan Gottloeber, who applied his FOF algorithm
to find groups of connected particles for a given linking length to cosmological 
simulations. These FOF groups resemble something similar to dark matter halos, but
no bounding criterion is applied. For more information on the basic method, 
see Davis et al. 1985 (http://adsabs.harvard.edu/abs/1985ApJ...292..371D) and for 
a description of the applied version, see Knebe et al. 2011 
(http://adsabs.harvard.edu/abs/2011MNRAS.415.2293K). 

The files were written with Fortran, option "unformatted", but direct access 
so each record is wrapped by a leading and trailing (4 byte) integer.

Each binary file is usually accompanied by an ascii-header file  (...info), 
which contains all the information about boxsize, redshift, etc. 
FofIngest won't read this file, but expects you to provide the necessary information
as command line arguments. See FofReader.cpp for options (or use the help flag) to get a list of options.

A data file structured as follows:

* one row per FOF group, containing following columns (4 byte int or 4 byte float each):

Name        |Type    | Description        
:-----------|:-------|:-------------------
lkl         |int     |number of particles 
iadr        |int     |                       
rc1         |float   |x coordinate  
rc2         |float   |y coordinate  
rc3         |float   |z coordinate of position in cosmological box
vc1         |float   |velocity components 
vc2         |float   |
vc3         |float   |
total_mass  |float   |mass of all group particles
xv1         |float   |components of angular momentum vector
xv2         |float   |
xv3         |float   |
xlambda     |float   |can be used to calculate the spin parameter
disp        |float   |dispersion
vdisp       |float   |velocity dispersion
root1       |float   |eigenvalues
root2       |float   |
root3       |float   |
vol8        |float   |spherical volume corresponding to FOF group
delta       |float   |overdensity (mass/volume) in terms of background density
e_kin       |float   |kinetic energy
vect[9]     |9\*float |eigenvectors of inertia tensor
ispecies[6] |6\*int   |number of particles per species, for dark matter only: ispecies[1...5] = 0

and two additional Fortran-specific integers.


Features
----------
* Read given datafile and ingest the data as following columns into a database table:
(see Fof_SchemaMapper.cpp)

Database column  |  Derived from file column
-----------------|:-------------------------
np          |lkl
x,y,z       |rc1, rc2, rc3 (shifted to box-range, if negative)
vx,vy,vz    |vrc1, vrc2, vrc3
mass        |total_mass
angmom_x    |xv1
angmom_y    |xv2
angmom_z    |xv3
angmom      |sqrt(xv1*xv1 + xv2*xv2 + xv3*xv3)
disp        |disp
disp_v      |vdisp
axis1       |root1
axis2       |root2
axis3       |root3
delta       |delta
axis1_x,... |vect[0:2]
axis2_x,... |vect[3:5]
axis3_x,... |vect[5:8]
snapnum     |[from command line parameters]
level       |[from command line parameters]
NInFile     |[row number in file]
fofId       |[snapnum*10+level)*idfactor + NInFile; idfactor from command line]
ix,iy,iz    |[floor(x/box*ngrid); box and ngrid from command line]
phkey       |[0, must be calculated database-wise]
size        |pow(vol8/(4./3*3.1415136), 0.333333)
spin        |derived from xlambda

`phkey` = Peano-Hilbert key for the grid cell in which the particle is located,   
		is just filled with 0's, values can be updated via the database 
        server using e.g. libhilbert (https://github.com/adrpar/libhilbert)

* If swap=1 is given, values will be byteswapped
* Accepts parameters startRow and maxRows for jumping to the specified row and reading only a certain (contiguous) chunk of rows.


Installation
--------------
see INSTALL


Example
--------
An example data file and create-table statement are given in the 
*Example* directory.
Data can be ingested with a command line like this:

```
FofIngest/build/FofIngest.x -s mysql -D TestDB -T FOF -U myusername -P mypassword -H 127.0.0.1 -O 3306 -M 50 -a 0.5 -l 2 -b 1000 -n 100 -g 1024 -i 5 -m 20 -I 1.e6 -d fof_example.DAT
```

Replace *myusername* and *mypassword* with your own credentials for your own database. 

The possible options are:  
`-s`: type of database (e.g. mysql, unix_sqlsrv_odbc)  
`-D`: database name  
`-T`: table name  
`-H`: host  
`-O`: port  
`-d`: data file  
`-M`: snapshot number (snapnum)  
`-a`: expansion factor  
`-l`: level  
`-b`: boxsize  
`-n`: min. number of particles in FOF group; NOTE: code assumes that FOF-groups are sorted by np in decreasing order, will stop reading if number of particles falls below this minimum   
`-g`: grid cells for ix,iy,iz, per dimension  
`-i`: start at this row  
`-m`: read at most this number of rows  
`-I`: idfactor for fofId calculation  

NOTE: One can also use `-R 1`. This would try to resume the connection, 
if something fails. But then be careful and check later on if all rows were 
ingested and contain meaningful values. Erroneous rows must be deleted manually. 
Missing rows can be inserted using startRow and maxRows. That's quite fast, since
the reader will just jump to the correct position. Finding out which rows are
missing takes the most time here.

The database table could have been created like this 
(see also *Example/createfoftable-mysql.sql*):

```mysql
mysql> use TestDB;

create table FOF (
    fofId bigint not null,      
    snapnum smallint not null,  
    `level` smallint not null,      
    NInFile int not null,        
    x float not null,
    y float not null,
    z float not null,
    vx float not null,
    vy float not null,
    vz float not null,
    np int not null,                
    mass float not null,
    `size` float not null,              
    disp float not null,
    disp_v float not null,
    delta float not null, 
    spin float not null,
    angMom_x float not null,
    angMom_y float not null, 
    angMom_z float not null,
    angMom float not null,
    axis1 float not null,
    axis2 float not null,
    axis3 float not null,
    axis1_x float not null,
    axis1_y float not null,
    axis1_z float not null,
    axis2_x float not null,
    axis2_y float not null,
    axis2_z float not null,
    axis3_x float not null,
    axis3_y float not null,
    axis3_z float not null,
    ix int not null,
    iy int not null,
    iz int not null,
    phkey int not null
)
```
An example data file is also given in the *Example* directory.