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

#include <Reader.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <assert.h>

#ifndef Fof_Fof_Reader_h
#define Fof_Fof_Reader_h

using namespace DBReader;
using namespace DBDataSchema;
using namespace std;

namespace Fof {
    
    class FofReader : public Reader {
    private:
        std::string fileName;
        
        std::ifstream fileStream;
        
        int currRow;
        unsigned long numFieldPerRow;
        
        std::string buffer;
        std::string oneLine;
        
        std::string endLineFlag;

        //this is here for performance reasons. used to be in getItemInRow, but is allocated statically here to get rid
        //of many frees
        std::string tmpStr;
              
        string fofString;
        int counter;

        int numBytesPerRow;	

        // items from file
        int lkl;
        int iadr;
        float rc1;
        float rc2;
        float rc3;
        float vc1;
        float vc2;
        float vc3;
        float total_mass;
        float xv1;
        float xv2;
        float xv3;
        float xlambda;
        float disp;
        float vdisp;
        float root1;
        float root2;
        float root3;
        float vol8;
        float delta;
        float e_kin;
        float vect[9];
        int   ispecies[6];
        
        //fields to be generated/converted/...
        int snapnum;
        int NInFile;
        int level;
        long int fofId;
        float size;
        float spin;
        float x;
        float y;
        float z;
        float angMom;
        int ix;
        int iy;
        int iz;
        int phkey;
        
        // to be passed on from main
        double idfactor; // factor to multiply snapnum with for getting the correct ids
        float box;	// box size for periodic boundary conditions
        float aexpn; 	// expansion factor of the universe
        int nlimit;     // minimum number of particles in halo/group (lkl)
        int swap;	// byte swap or not
        int ngrid;	// number of cells per dimension for ix,iy,iz
        int startRow;   // at which row should we start ingesting
        int maxRows;    // max. number of rows to ingest
          
    public:
        FofReader();
        FofReader(std::string newFileName, int swap, int snapnum, float aexpn, int level, float box, int nlimit, int ngrid, int startRow, int maxRows, double idfactor);
        ~FofReader();

        void openFile(std::string newFileName);

        void closeFile();

        void offsetFileStream();
        
        int getNextRow();
        
        int assignInt(int *n, char *memblock, int swap);
        int assignFloat(float *n, char *memblock, int swap);   
        
        bool getItemInRow(DBDataSchema::DataObjDesc * thisItem, bool applyAsserters, bool applyConverters, void* result);

        void getDataItem(DBDataSchema::DataObjDesc * thisItem, void* result);

        void getConstItem(DBDataSchema::DataObjDesc * thisItem, void* result);
    };
    
}

#endif
