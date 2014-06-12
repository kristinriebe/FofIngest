use TestDB;

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
    spin float not null, -- 17
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
    ix int not null,	-- spatial index, maybe same as for density field
    iy int not null,
    iz int not null,
    phkey int not null	-- Peano-Hilbert-key, can be computed using Spatial3D library
)

