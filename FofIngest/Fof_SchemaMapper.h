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

#include <SchemaDataMapGenerator.h>
#include <DBType.h>
#include <AsserterFactory.h>
#include <ConverterFactory.h>
#include <string>
#include <stdio.h>

#ifndef Fof_Fof_SchemaMapper_h
#define Fof_Fof_SchemaMapper_h

using namespace DBDataSchema;

namespace Fof {
    
    class FofSchemaMapper : public SchemaDataMapGenerator  {
        
    private:
        DBAsserter::AsserterFactory * assertFac;
        DBConverter::ConverterFactory * convFac;
        
    public:
        FofSchemaMapper();

        FofSchemaMapper(DBAsserter::AsserterFactory * newAssertFac, DBConverter::ConverterFactory * newConvFac);

        ~FofSchemaMapper();
        
        DBDataSchema::Schema * generateSchema(std::string dbName, std::string tblName);
    };
    
}


#endif
