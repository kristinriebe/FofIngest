/*  
 *  Copyright (c) 2016, Adrian M. Partl <apartl@aip.de>,
 *                      Kristin Riebe <kriebe@aip.de>,
 *                      E-Science team AIP Potsdam
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  See the NOTICE file distributed with this work for additional
 *  information regarding copyright ownership. You may obtain a copy
 *  of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // sqrt, pow
#include "fofingest_error.h"

#include "Fof_Reader.h"

namespace Fof {
    FofReader::FofReader() {
        //counter = 0;
        //currRow = -1;
    }
    
    FofReader::FofReader(std::string newFileName, int newSwap, int newSnapnum, float newAexpn, int newLevel, float newBox, int newNlimit, int newNgrid, int newStartRow, int newMaxRows, double newIdfactor) {          
        // this->box = box;     
        swap = newSwap;
        snapnum = newSnapnum;
        aexpn = newAexpn;
        level = newLevel - 1;  // want to start with 0!!
        box = newBox;
        nlimit = newNlimit;
        ngrid = newNgrid;
        startRow = newStartRow;
        maxRows = newMaxRows;
        idfactor = newIdfactor;
        
        currRow = 0;
        
        numBytesPerRow = 2*sizeof(int)+28*sizeof(float)+6*sizeof(int)+2*sizeof(int); // 36 values in total; + two fortran-binary-specific intermediate numbers
        
        openFile(newFileName);
        offsetFileStream();
    }
    
    
    FofReader::~FofReader() {
        closeFile();
    }
    
    void FofReader::openFile(string newFileName) {
        if (fileStream.is_open())
            fileStream.close();

        // open binary file
        fileStream.open(newFileName.c_str(), ios::in | ios::binary);
        
        if (!(fileStream.is_open())) {
            FofIngest_error("FofReader: Error in opening file.\n");
        }
        
        fileName = newFileName;
    }
    
    void FofReader::closeFile() {
        if (fileStream.is_open())
            fileStream.close();
    }
    
    void FofReader::offsetFileStream() {
        int irow;
        streamoff ipos;
        
        assert(fileStream.is_open());
        
        // position pointer at beginning of the row where ingestion should start
        //numBytesPerRow = 2*sizeof(int)+28*sizeof(float)+6*sizeof(int)+2*sizeof(int); // 36 values in total;  
        ipos = (streamoff) ( (long) startRow * (long) numBytesPerRow );
        fileStream.seekg(ipos, ios::beg);
        
        // update currow
        currRow = startRow;
        
        cout<<"offset currRow: "<<currRow<<endl;
    }
    
    int FofReader::getNextRow() {
        assert(fileStream.is_open());
        
        // read one line
        char memchunk[numBytesPerRow];
        
        //cout<<"reader: currRow: "<<currRow<<endl;

        //read the line (one halo) at once
        if (!fileStream.read(memchunk,numBytesPerRow)) {
            return 0;
        }
        
        // now parse the line and assign it to the proper variables using memcpy
        assignInt(  &lkl, &memchunk[0], swap);
        assignInt(  &iadr, &memchunk[sizeof(int)], swap);
        assignFloat(&rc1, &memchunk[2*sizeof(int)], swap);
        assignFloat(&rc2, &memchunk[2*sizeof(int)+1*sizeof(float)], swap);
        assignFloat(&rc3, &memchunk[2*sizeof(int)+2*sizeof(float)], swap);
        assignFloat(&vc1, &memchunk[2*sizeof(int)+3*sizeof(float)], swap);
        assignFloat(&vc2, &memchunk[2*sizeof(int)+4*sizeof(float)], swap);
        assignFloat(&vc3, &memchunk[2*sizeof(int)+5*sizeof(float)], swap);
        assignFloat(&total_mass, &memchunk[2*sizeof(int)+6*sizeof(float)], swap);
        assignFloat(&xv1, &memchunk[2*sizeof(int)+7*sizeof(float)], swap);
        assignFloat(&xv2, &memchunk[2*sizeof(int)+8*sizeof(float)], swap);
        assignFloat(&xv3, &memchunk[2*sizeof(int)+9*sizeof(float)], swap);
        assignFloat(&xlambda, &memchunk[2*sizeof(int)+10*sizeof(float)], swap);
        assignFloat(&disp, &memchunk[2*sizeof(int)+11*sizeof(float)], swap);
        assignFloat(&vdisp, &memchunk[2*sizeof(int)+12*sizeof(float)], swap);
        assignFloat(&root1, &memchunk[2*sizeof(int)+13*sizeof(float)], swap);
        assignFloat(&root2, &memchunk[2*sizeof(int)+14*sizeof(float)], swap);
        assignFloat(&root3, &memchunk[2*sizeof(int)+15*sizeof(float)], swap);
        assignFloat(&vol8, &memchunk[2*sizeof(int)+16*sizeof(float)], swap);
        assignFloat(&delta, &memchunk[2*sizeof(int)+17*sizeof(float)], swap);
        assignFloat(&e_kin, &memchunk[2*sizeof(int)+18*sizeof(float)], swap);
        assignFloat(&vect[0], &memchunk[2*sizeof(int)+19*sizeof(float)], swap);
        assignFloat(&vect[1], &memchunk[2*sizeof(int)+20*sizeof(float)], swap);
        assignFloat(&vect[2], &memchunk[2*sizeof(int)+21*sizeof(float)], swap);
        assignFloat(&vect[3], &memchunk[2*sizeof(int)+22*sizeof(float)], swap);
        assignFloat(&vect[4], &memchunk[2*sizeof(int)+23*sizeof(float)], swap);
        assignFloat(&vect[5], &memchunk[2*sizeof(int)+24*sizeof(float)], swap);
        assignFloat(&vect[6], &memchunk[2*sizeof(int)+25*sizeof(float)], swap);
        assignFloat(&vect[7], &memchunk[2*sizeof(int)+26*sizeof(float)], swap);
        assignFloat(&vect[8], &memchunk[2*sizeof(int)+27*sizeof(float)], swap);
        assignInt(  &ispecies[0], &memchunk[2*sizeof(int)+28*sizeof(float)], swap);
        assignInt(  &ispecies[1], &memchunk[2*sizeof(int)+28*sizeof(float)+1*sizeof(int)], swap);
        assignInt(  &ispecies[2], &memchunk[2*sizeof(int)+28*sizeof(float)+2*sizeof(int)], swap);
        assignInt(  &ispecies[3], &memchunk[2*sizeof(int)+28*sizeof(float)+3*sizeof(int)], swap);
        assignInt(  &ispecies[4], &memchunk[2*sizeof(int)+28*sizeof(float)+4*sizeof(int)], swap);
        assignInt(  &ispecies[5], &memchunk[2*sizeof(int)+28*sizeof(float)+5*sizeof(int)], swap);
               
        currRow++;

        // stop reading/ingesting, if number of particles (lkl) gets smaller than 20
        // Note: This only works like this, if halos are sorted by mass desc!
        if (lkl < nlimit) {
            printf("Limiting number of particles in FOF group is reached (%d < %d).\n", lkl, nlimit);
            return 0;
        }
        
        // stop after reading maxRows, but only if it is not -1
        // Note: Could this be accelerated? It's unnecessary most of the time,
        // but now it is evaluated for each row ...
        if (maxRows != -1) {
            if (currRow-startRow > maxRows) {
                printf("Maximum number of rows to be ingested is reached (%d).\n", maxRows);
                return 0;
            }
        }

        return 1;       
    }
    
    // write part from memoryblock to integer; byteswap, if necessary (TODO: use global 'swap' or locally submit?)
    int FofReader::assignInt(int *n, char *memblock, int swap) {
        
        unsigned char *cptr,tmp;

        if (sizeof(int) != 4) {
            fprintf(stderr,"assignInt: sizeof(int)=%ld and not 4. Can't handle that.\n",sizeof(int));
            return 0;
        }

        if (!memcpy(n,  memblock, sizeof(int))) {
            fprintf(stderr,"Error: Encountered end of memory block or other trouble when reading the memory block.\n");
            return 0;
        }

        if (swap) {
            cptr = (unsigned char *) n;
            tmp     = cptr[0];
            cptr[0] = cptr[3];    
            cptr[3] = tmp;
            tmp     = cptr[1];
            cptr[1] = cptr[2];
            cptr[2] = tmp;
        }
    }

    // write part from memoryblock to float; byteswap, if necessary (TODO: use global 'swap' or locally submit?)
    int FofReader::assignFloat(float *n, char *memblock, int swap) {
        
        unsigned char *cptr,tmp;
        
        if (sizeof(float) != 4) {
            fprintf(stderr,"assignFloat: sizeof(float)=%ld and not 4. Can't handle that.\n",sizeof(float));
            return 0;
        }
        
        if (!memcpy(n, memblock, sizeof(float))) {
            printf("Error: Encountered end of memory block or other trouble when reading the memory block.\n");
            return 0;
        }
        
        if (swap) {
            cptr = (unsigned char *) n;
            tmp     = cptr[0];
            cptr[0] = cptr[3];    
            cptr[3] = tmp;
            tmp     = cptr[1];
            cptr[1] = cptr[2];
            cptr[2] = tmp;
        }
    }

    
    bool FofReader::getItemInRow(DBDataSchema::DataObjDesc * thisItem, bool applyAsserters, bool applyConverters, void* result) {
        //reroute constant items:
        if(thisItem->getIsConstItem() == true) {
            getConstItem(thisItem, result);
        } else if (thisItem->getIsHeaderItem() == true) {
            printf("We never told you to read headers...\n");
            exit(EXIT_FAILURE);
        } else {
            getDataItem(thisItem, result);
        }
        
        //check assertions
        //checkAssertions(thisItem, result);
        
        //apply conversion
        //applyConversions(thisItem, result);

        return 0;
    }

// periodic macros:
// - shift from negative to positive (within [0,boxsize]) by adding + n*boxsize
#define PERIODICLEFT(X,BOX) ( (X) < 0 ? ( (X) + ( -1 * (int64_t)( (X) / (BOX) ) + 1 ) * (BOX) ) : (X) )
// - shift from beyond boxsize back to [0,boxsize] by adding - n*boxsize
#define PERIODICRIGHT(X,BOX) ( (X) > (BOX) ? ( (X) - ( (int64_t)( (X) / (BOX) ) ) * (BOX) ) : (X) )
    void FofReader::getDataItem(DBDataSchema::DataObjDesc * thisItem, void* result) {

        //check if this is "Col1" etc. and if yes, assign corresponding value
        //the variables are declared already in Fof_Reader.h 
        //and the values were read in getNextRow()
       
        NInFile = currRow-1;    // start counting rows with 0
        
        if(thisItem->getDataObjName().compare("Col1") == 0) {            
            *(int*)(result) = lkl;
        } else if (thisItem->getDataObjName().compare("Col2") == 0) {
            *(int*)(result) = iadr;
        } else if (thisItem->getDataObjName().compare("Col3") == 0) {
            //position may be negative for some reason, shift to box-range
            rc1 = PERIODICLEFT(rc1,box);
           x = rc1;
            *(float*)(result) = x;
        } else if (thisItem->getDataObjName().compare("Col4") == 0) {
            //position may be negative for some reason, shift to box-range
            rc2 = PERIODICLEFT(rc2,box);
            y = rc2;
            *(float*)(result) = y;
        } else if (thisItem->getDataObjName().compare("Col5") == 0) {
            //position may be negative for some reason, shift to box-range
            rc3 = PERIODICLEFT(rc3,box);
            z = rc3;         
            *(float*)(result) = z;
        } else if (thisItem->getDataObjName().compare("Col6") == 0) {
            *(float*)(result) = vc1;
        } else if (thisItem->getDataObjName().compare("Col7") == 0) {
            *(float*)(result) = vc2;
        } else if (thisItem->getDataObjName().compare("Col8") == 0) {
            *(float*)(result) = vc3;
        } else if (thisItem->getDataObjName().compare("Col9") == 0) {
            *(float*)(result) = total_mass;
        } else if (thisItem->getDataObjName().compare("Col10") == 0) {
            *(float*)(result) = xv1;
        } else if (thisItem->getDataObjName().compare("Col11") == 0) {
            *(float*)(result) = xv2;
        } else if (thisItem->getDataObjName().compare("Col12") == 0) {
            *(float*)(result) = xv3;
        } else if (thisItem->getDataObjName().compare("Col13") == 0) {
            *(float*)(result) = xlambda;
        } else if (thisItem->getDataObjName().compare("Col14") == 0) {
            *(float*)(result) = disp;
        } else if (thisItem->getDataObjName().compare("Col15") == 0) {
            *(float*)(result) = vdisp;
        } else if (thisItem->getDataObjName().compare("Col16") == 0) {
            *(float*)(result) = root1;
        } else if (thisItem->getDataObjName().compare("Col17") == 0) {
            *(float*)(result) = root2;
        } else if (thisItem->getDataObjName().compare("Col18") == 0) {
            *(float*)(result) = root3;
        } else if (thisItem->getDataObjName().compare("Col19") == 0) {
            *(float*)(result) = vol8;
        } else if (thisItem->getDataObjName().compare("Col20") == 0) {
            *(float*)(result) = delta;
        } else if (thisItem->getDataObjName().compare("Col21") == 0) {
            *(float*)(result) = e_kin;
        } else if (thisItem->getDataObjName().compare("Col22") == 0) {
            *(float*)(result) = vect[0];
        } else if (thisItem->getDataObjName().compare("Col23") == 0) {
            *(float*)(result) = vect[1];
        } else if (thisItem->getDataObjName().compare("Col24") == 0) {
            *(float*)(result) = vect[2];
        } else if (thisItem->getDataObjName().compare("Col25") == 0) {
            *(float*)(result) = vect[3];
        } else if (thisItem->getDataObjName().compare("Col26") == 0) {
            *(float*)(result) = vect[4];
        } else if (thisItem->getDataObjName().compare("Col27") == 0) {
            *(float*)(result) = vect[5];
        } else if (thisItem->getDataObjName().compare("Col28") == 0) {
            *(float*)(result) = vect[6];
        } else if (thisItem->getDataObjName().compare("Col29") == 0) {
            *(float*)(result) = vect[7];
        } else if (thisItem->getDataObjName().compare("Col30") == 0) {
            *(float*)(result) = vect[8];
        } else if (thisItem->getDataObjName().compare("Col31") == 0) {
            *(int*)(result) = ispecies[0];
        } else if (thisItem->getDataObjName().compare("Col32") == 0) {
            *(int*)(result) = ispecies[1];
        } else if (thisItem->getDataObjName().compare("Col33") == 0) {
            *(int*)(result) = ispecies[2];
        } else if (thisItem->getDataObjName().compare("Col34") == 0) {
            *(int*)(result) = ispecies[3];
        } else if (thisItem->getDataObjName().compare("Col35") == 0) {
            *(int*)(result) = ispecies[4];
        } else if (thisItem->getDataObjName().compare("Col36") == 0) {
            *(int*)(result) = ispecies[5];
        } else if (thisItem->getDataObjName().compare("Col37") == 0) {
            *(int*)(result) = snapnum;
        } else if (thisItem->getDataObjName().compare("Col38") == 0) {
            *(int*)(result) = level;
        } else if (thisItem->getDataObjName().compare("Col39") == 0) {
            *(int*)(result) = NInFile;
        } else if (thisItem->getDataObjName().compare("Col40") == 0) {
            fofId = (long int) ( (snapnum*10+level)*idfactor + NInFile );
            //printf("fofId: %ld\n", fofId);*1.e11
            *(long int*)(result) = fofId;
        } else if (thisItem->getDataObjName().compare("Col41") == 0) {
            ix = (int) floor(x/box*ngrid);
            *(int*)(result) = ix;
        } else if (thisItem->getDataObjName().compare("Col42") == 0) {
            iy = (int) floor(y/box*ngrid);
            *(int*)(result) = iy;
        } else if (thisItem->getDataObjName().compare("Col43") == 0) {
            iz = (int) floor(z/box*ngrid);
            //printf("ix,x,box,ngrid: %d %f %f %d\n", ix,x,box,ngrid);
            *(int*)(result) = iz;
        } else if (thisItem->getDataObjName().compare("Col44") == 0) {
            phkey = 0;
            *(int*)(result) = phkey;
        } else if (thisItem->getDataObjName().compare("Col45") == 0) {
            angMom = sqrt(xv1*xv1 + xv2*xv2 + xv3*xv3);
            *(float*)(result) = angMom;
        } else if (thisItem->getDataObjName().compare("Col46") == 0) {
            size = pow(vol8/(4./3*3.1415136), 0.333333);
            *(float*)(result) = size;
        } else if (thisItem->getDataObjName().compare("Col47") == 0) {
            if (xlambda > 0) xlambda *= sqrt(2.);
            if (xlambda < 0) xlambda = -xlambda;
            spin = xlambda * aexpn;
            *(float*)(result) = spin;
        } else {
            printf("Something went wrong...\n");
            exit(EXIT_FAILURE);
        }
    }

    void FofReader::getConstItem(DBDataSchema::DataObjDesc * thisItem, void* result) {
        memcpy(result, thisItem->getConstData(), DBDataSchema::getByteLenOfDType(thisItem->getDataObjDType()));
    }
}
