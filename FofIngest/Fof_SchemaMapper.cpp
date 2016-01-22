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

#include "Fof_SchemaMapper.h"
#include <SchemaItem.h>
#include <DataObjDesc.h>
#include <DType.h>
#include <DBType.h>
#include <stdlib.h>

using namespace std;
using namespace DBDataSchema;

namespace Fof {
    
    FofSchemaMapper::FofSchemaMapper() {
        
    }

    FofSchemaMapper::FofSchemaMapper(DBAsserter::AsserterFactory * newAssertFac, DBConverter::ConverterFactory * newConvFac) {
        assertFac = newAssertFac;
        convFac = newConvFac;
    }

    FofSchemaMapper::~FofSchemaMapper() {
        
    }
    
    DBDataSchema::Schema * FofSchemaMapper::generateSchema(string dbName, string tblName) {
        DBDataSchema::Schema * returnSchema = new Schema();

        //set database and table name
        returnSchema->setDbName(dbName);
        returnSchema->setTableName(tblName);
        
        //setup schema items and add them to the schema
        
        //this is a string colum, where we will produce "Hello World"
        //first create the data object describing the input data:
        DataObjDesc * col1Obj = new DataObjDesc();
        col1Obj->setDataObjName("Col1");	// column name (data file)
        col1Obj->setDataObjDType(DT_INT4);	// data file type
        col1Obj->setIsConstItem(false, false); // not a constant
        col1Obj->setIsHeaderItem(false);	// not a header item
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem1 = new SchemaItem();
        schemaItem1->setColumnName("np"); //EMPTY_SCHEMAITEM_NAME);	// field name in Database
        schemaItem1->setColumnDBType(DBT_INTEGER);		// database field type
        schemaItem1->setDataDesc(col1Obj);		// link to data object
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem1);

        
        //this is the second column
        DataObjDesc * col2Obj = new DataObjDesc();
        col2Obj->setDataObjName("Col2");
        col2Obj->setDataObjDType(DT_INT4);
        col2Obj->setIsConstItem(false, false);
        col2Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem2 = new SchemaItem();
        schemaItem2->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem2->setColumnDBType(DBT_INTEGER);
        schemaItem2->setDataDesc(col2Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem2);
       
        
        //this is the 3. column
        DataObjDesc * col3Obj = new DataObjDesc();
        col3Obj->setDataObjName("Col3");
        col3Obj->setDataObjDType(DT_REAL4);
        col3Obj->setIsConstItem(false, false);
        col3Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem3 = new SchemaItem();
        schemaItem3->setColumnName("x");
        schemaItem3->setColumnDBType(DBT_FLOAT);
        schemaItem3->setDataDesc(col3Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem3);
       
        
        //this is the 4. column
        DataObjDesc * col4Obj = new DataObjDesc();
        col4Obj->setDataObjName("Col4");
        col4Obj->setDataObjDType(DT_REAL4);
        col4Obj->setIsConstItem(false, false);
        col4Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem4 = new SchemaItem();
        schemaItem4->setColumnName("y");
        schemaItem4->setColumnDBType(DBT_FLOAT);
        schemaItem4->setDataDesc(col4Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem4);
       
        
        //this is the 5. column
        DataObjDesc * col5Obj = new DataObjDesc();
        col5Obj->setDataObjName("Col5");
        col5Obj->setDataObjDType(DT_REAL4);
        col5Obj->setIsConstItem(false, false);
        col5Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem5 = new SchemaItem();
        schemaItem5->setColumnName("z");
        schemaItem5->setColumnDBType(DBT_FLOAT);
        schemaItem5->setDataDesc(col5Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem5);
       

        //this is the 6. column
        DataObjDesc * col6Obj = new DataObjDesc();
        col6Obj->setDataObjName("Col6");
        col6Obj->setDataObjDType(DT_REAL4);
        col6Obj->setIsConstItem(false, false);
        col6Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem6 = new SchemaItem();
        schemaItem6->setColumnName("vx");
        schemaItem6->setColumnDBType(DBT_FLOAT);
        schemaItem6->setDataDesc(col6Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem6);
       

        //this is the 7. column
        DataObjDesc * col7Obj = new DataObjDesc();
        col7Obj->setDataObjName("Col7");
        col7Obj->setDataObjDType(DT_REAL4);
        col7Obj->setIsConstItem(false, false);
        col7Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem7 = new SchemaItem();
        schemaItem7->setColumnName("vy");
        schemaItem7->setColumnDBType(DBT_FLOAT);
        schemaItem7->setDataDesc(col7Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem7);
       

        //this is the 8. column
        DataObjDesc * col8Obj = new DataObjDesc();
        col8Obj->setDataObjName("Col8");
        col8Obj->setDataObjDType(DT_REAL4);
        col8Obj->setIsConstItem(false, false);
        col8Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem8 = new SchemaItem();
        schemaItem8->setColumnName("vz");
        schemaItem8->setColumnDBType(DBT_FLOAT);
        schemaItem8->setDataDesc(col8Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem8);
       

        //this is the 9. column
        DataObjDesc * col9Obj = new DataObjDesc();
        col9Obj->setDataObjName("Col9");
        col9Obj->setDataObjDType(DT_REAL4);
        col9Obj->setIsConstItem(false, false);
        col9Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem9 = new SchemaItem();
        schemaItem9->setColumnName("mass");
        schemaItem9->setColumnDBType(DBT_FLOAT);
        schemaItem9->setDataDesc(col9Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem9);
       

        //this is the 10. column
        DataObjDesc * col10Obj = new DataObjDesc();
        col10Obj->setDataObjName("Col10");
        col10Obj->setDataObjDType(DT_REAL4);
        col10Obj->setIsConstItem(false, false);
        col10Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem10 = new SchemaItem();
        schemaItem10->setColumnName("angMom_x");
        schemaItem10->setColumnDBType(DBT_FLOAT);
        schemaItem10->setDataDesc(col10Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem10);
       

        //this is the 11. column
        DataObjDesc * col11Obj = new DataObjDesc();
        col11Obj->setDataObjName("Col11");
        col11Obj->setDataObjDType(DT_REAL4);
        col11Obj->setIsConstItem(false, false);
        col11Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem11 = new SchemaItem();
        schemaItem11->setColumnName("angMom_y");
        schemaItem11->setColumnDBType(DBT_FLOAT);
        schemaItem11->setDataDesc(col11Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem11);
       

        //this is the 12. column
        DataObjDesc * col12Obj = new DataObjDesc();
        col12Obj->setDataObjName("Col12");
        col12Obj->setDataObjDType(DT_REAL4);
        col12Obj->setIsConstItem(false, false);
        col12Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem12 = new SchemaItem();
        schemaItem12->setColumnName("angMom_z");
        schemaItem12->setColumnDBType(DBT_FLOAT);
        schemaItem12->setDataDesc(col12Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem12);
       

        //this is the 13. column
        DataObjDesc * col13Obj = new DataObjDesc();
        col13Obj->setDataObjName("Col13");
        col13Obj->setDataObjDType(DT_REAL4);
        col13Obj->setIsConstItem(false, false);
        col13Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem13 = new SchemaItem();
        schemaItem13->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem13->setColumnDBType(DBT_FLOAT);
        schemaItem13->setDataDesc(col13Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem13);
       

        //this is the 14. column
        DataObjDesc * col14Obj = new DataObjDesc();
        col14Obj->setDataObjName("Col14");
        col14Obj->setDataObjDType(DT_REAL4);
        col14Obj->setIsConstItem(false, false);
        col14Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem14 = new SchemaItem();
        schemaItem14->setColumnName("disp");
        schemaItem14->setColumnDBType(DBT_FLOAT);
        schemaItem14->setDataDesc(col14Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem14);
       

        //this is the 15. column
        DataObjDesc * col15Obj = new DataObjDesc();
        col15Obj->setDataObjName("Col15");
        col15Obj->setDataObjDType(DT_REAL4);
        col15Obj->setIsConstItem(false, false);
        col15Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem15 = new SchemaItem();
        schemaItem15->setColumnName("disp_v");
        schemaItem15->setColumnDBType(DBT_FLOAT);
        schemaItem15->setDataDesc(col15Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem15);
       

        //this is the 16. column
        DataObjDesc * col16Obj = new DataObjDesc();
        col16Obj->setDataObjName("Col16");
        col16Obj->setDataObjDType(DT_REAL4);
        col16Obj->setIsConstItem(false, false);
        col16Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem16 = new SchemaItem();
        schemaItem16->setColumnName("axis1");
        schemaItem16->setColumnDBType(DBT_FLOAT);
        schemaItem16->setDataDesc(col16Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem16);
       

        //this is the 17. column
        DataObjDesc * col17Obj = new DataObjDesc();
        col17Obj->setDataObjName("Col17");
        col17Obj->setDataObjDType(DT_REAL4);
        col17Obj->setIsConstItem(false, false);
        col17Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem17 = new SchemaItem();
        schemaItem17->setColumnName("axis2");
        schemaItem17->setColumnDBType(DBT_FLOAT);
        schemaItem17->setDataDesc(col17Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem17);
       

        //this is the 18. column
        DataObjDesc * col18Obj = new DataObjDesc();
        col18Obj->setDataObjName("Col18");
        col18Obj->setDataObjDType(DT_REAL4);
        col18Obj->setIsConstItem(false, false);
        col18Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem18 = new SchemaItem();
        schemaItem18->setColumnName("axis3");
        schemaItem18->setColumnDBType(DBT_FLOAT);
        schemaItem18->setDataDesc(col18Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem18);
       

        //this is the 19. column
        DataObjDesc * col19Obj = new DataObjDesc();
        col19Obj->setDataObjName("Col19");
        col19Obj->setDataObjDType(DT_REAL4);
        col19Obj->setIsConstItem(false, false);
        col19Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem19 = new SchemaItem();
        schemaItem19->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem19->setColumnDBType(DBT_FLOAT);
        schemaItem19->setDataDesc(col19Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem19);
       

        //this is the 20. column
        DataObjDesc * col20Obj = new DataObjDesc();
        col20Obj->setDataObjName("Col20");
        col20Obj->setDataObjDType(DT_REAL4);
        col20Obj->setIsConstItem(false, false);
        col20Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem20 = new SchemaItem();
        schemaItem20->setColumnName("delta");
        schemaItem20->setColumnDBType(DBT_FLOAT);
        schemaItem20->setDataDesc(col20Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem20);


        //this is the 21. column
        DataObjDesc * col21Obj = new DataObjDesc();
        col21Obj->setDataObjName("Col21");
        col21Obj->setDataObjDType(DT_REAL4);
        col21Obj->setIsConstItem(false, false);
        col21Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem21 = new SchemaItem();
        schemaItem21->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem21->setColumnDBType(DBT_FLOAT);
        schemaItem21->setDataDesc(col21Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem21);
       

        //this is the 22. column
        DataObjDesc * col22Obj = new DataObjDesc();
        col22Obj->setDataObjName("Col22");
        col22Obj->setDataObjDType(DT_REAL4);
        col22Obj->setIsConstItem(false, false);
        col22Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem22 = new SchemaItem();
        schemaItem22->setColumnName("axis1_x");
        schemaItem22->setColumnDBType(DBT_FLOAT);
        schemaItem22->setDataDesc(col22Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem22);
       

        //this is the 23. column
        DataObjDesc * col23Obj = new DataObjDesc();
        col23Obj->setDataObjName("Col23");
        col23Obj->setDataObjDType(DT_REAL4);
        col23Obj->setIsConstItem(false, false);
        col23Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem23 = new SchemaItem();
        schemaItem23->setColumnName("axis1_y");
        schemaItem23->setColumnDBType(DBT_FLOAT);
        schemaItem23->setDataDesc(col23Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem23);
       

        //this is the 24. column
        DataObjDesc * col24Obj = new DataObjDesc();
        col24Obj->setDataObjName("Col24");
        col24Obj->setDataObjDType(DT_REAL4);
        col24Obj->setIsConstItem(false, false);
        col24Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem24 = new SchemaItem();
        schemaItem24->setColumnName("axis1_z");
        schemaItem24->setColumnDBType(DBT_FLOAT);
        schemaItem24->setDataDesc(col24Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem24);
       

        //this is the 25. column
        DataObjDesc * col25Obj = new DataObjDesc();
        col25Obj->setDataObjName("Col25");
        col25Obj->setDataObjDType(DT_REAL4);
        col25Obj->setIsConstItem(false, false);
        col25Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem25 = new SchemaItem();
        schemaItem25->setColumnName("axis2_x");
        schemaItem25->setColumnDBType(DBT_FLOAT);
        schemaItem25->setDataDesc(col25Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem25);
       

        //this is the 26. column
        DataObjDesc * col26Obj = new DataObjDesc();
        col26Obj->setDataObjName("Col26");
        col26Obj->setDataObjDType(DT_REAL4);
        col26Obj->setIsConstItem(false, false);
        col26Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem26 = new SchemaItem();
        schemaItem26->setColumnName("axis2_y");
        schemaItem26->setColumnDBType(DBT_FLOAT);
        schemaItem26->setDataDesc(col26Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem26);
       

        //this is the 27. column
        DataObjDesc * col27Obj = new DataObjDesc();
        col27Obj->setDataObjName("Col27");
        col27Obj->setDataObjDType(DT_REAL4);
        col27Obj->setIsConstItem(false, false);
        col27Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem27 = new SchemaItem();
        schemaItem27->setColumnName("axis2_z");
        schemaItem27->setColumnDBType(DBT_FLOAT);
        schemaItem27->setDataDesc(col27Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem27);
       

        //this is the 28. column
        DataObjDesc * col28Obj = new DataObjDesc();
        col28Obj->setDataObjName("Col28");
        col28Obj->setDataObjDType(DT_REAL4);
        col28Obj->setIsConstItem(false, false);
        col28Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem28 = new SchemaItem();
        schemaItem28->setColumnName("axis3_x");
        schemaItem28->setColumnDBType(DBT_FLOAT);
        schemaItem28->setDataDesc(col28Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem28);
       

        //this is the 29. column
        DataObjDesc * col29Obj = new DataObjDesc();
        col29Obj->setDataObjName("Col29");
        col29Obj->setDataObjDType(DT_REAL4);
        col29Obj->setIsConstItem(false, false);
        col29Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem29 = new SchemaItem();
        schemaItem29->setColumnName("axis3_y");
        schemaItem29->setColumnDBType(DBT_FLOAT);
        schemaItem29->setDataDesc(col29Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem29);
       

        //this is the 30. column
        DataObjDesc * col30Obj = new DataObjDesc();
        col30Obj->setDataObjName("Col30");
        col30Obj->setDataObjDType(DT_REAL4);
        col30Obj->setIsConstItem(false, false);
        col30Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem30 = new SchemaItem();
        schemaItem30->setColumnName("axis3_z");
        schemaItem30->setColumnDBType(DBT_FLOAT);
        schemaItem30->setDataDesc(col30Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem30);
        
        
        //this is the 31. column
        DataObjDesc * col31Obj = new DataObjDesc();
        col31Obj->setDataObjName("Col31");
        col31Obj->setDataObjDType(DT_INT4);
        col31Obj->setIsConstItem(false, false);
        col31Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem31 = new SchemaItem();
        schemaItem31->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem31->setColumnDBType(DBT_INTEGER);
        schemaItem31->setDataDesc(col31Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem31);
       

        //this is the 32. column
        DataObjDesc * col32Obj = new DataObjDesc();
        col32Obj->setDataObjName("Col32");
        col32Obj->setDataObjDType(DT_INT4);
        col32Obj->setIsConstItem(false, false);
        col32Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem32 = new SchemaItem();
        schemaItem32->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem32->setColumnDBType(DBT_INTEGER);
        schemaItem32->setDataDesc(col32Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem32);
       

        //this is the 33. column
        DataObjDesc * col33Obj = new DataObjDesc();
        col33Obj->setDataObjName("Col33");
        col33Obj->setDataObjDType(DT_INT4);
        col33Obj->setIsConstItem(false, false);
        col33Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem33 = new SchemaItem();
        schemaItem33->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem33->setColumnDBType(DBT_INTEGER);
        schemaItem33->setDataDesc(col33Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem33);
       

        //this is the 34. column
        DataObjDesc * col34Obj = new DataObjDesc();
        col34Obj->setDataObjName("Col34");
        col34Obj->setDataObjDType(DT_INT4);
        col34Obj->setIsConstItem(false, false);
        col34Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem34 = new SchemaItem();
        schemaItem34->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem34->setColumnDBType(DBT_INTEGER);
        schemaItem34->setDataDesc(col34Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem34);
       

        //this is the 35. column
        DataObjDesc * col35Obj = new DataObjDesc();
        col35Obj->setDataObjName("Col35");
        col35Obj->setDataObjDType(DT_INT4);
        col35Obj->setIsConstItem(false, false);
        col35Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem35 = new SchemaItem();
        schemaItem35->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem35->setColumnDBType(DBT_INTEGER);
        schemaItem35->setDataDesc(col35Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem35);
       

        //this is the 36. column
        DataObjDesc * col36Obj = new DataObjDesc();
        col36Obj->setDataObjName("Col36");
        col36Obj->setDataObjDType(DT_INT4);
        col36Obj->setIsConstItem(false, false);
        col36Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem36 = new SchemaItem();
        schemaItem36->setColumnName(EMPTY_SCHEMAITEM_NAME);
        schemaItem36->setColumnDBType(DBT_INTEGER);
        schemaItem36->setDataDesc(col36Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem36);
       

        //this is the 37. column
        DataObjDesc * col37Obj = new DataObjDesc();
        col37Obj->setDataObjName("Col37");
        col37Obj->setDataObjDType(DT_INT2);
        col37Obj->setIsConstItem(false, false);
        col37Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem37 = new SchemaItem();
        schemaItem37->setColumnName("snapnum");
        schemaItem37->setColumnDBType(DBT_SMALLINT);
        schemaItem37->setDataDesc(col37Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem37);
       

        //this is the 38. column
        DataObjDesc * col38Obj = new DataObjDesc();
        col38Obj->setDataObjName("Col38");
        col38Obj->setDataObjDType(DT_INT2);
        col38Obj->setIsConstItem(false, false);
        col38Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem38 = new SchemaItem();
        schemaItem38->setColumnName("level");
        schemaItem38->setColumnDBType(DBT_SMALLINT);
        schemaItem38->setDataDesc(col38Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem38);
       

        //this is the 39. column
        DataObjDesc * col39Obj = new DataObjDesc();
        col39Obj->setDataObjName("Col39");
        col39Obj->setDataObjDType(DT_INT4);
        col39Obj->setIsConstItem(false, false);
        col39Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem39 = new SchemaItem();
        schemaItem39->setColumnName("NInFile");
        schemaItem39->setColumnDBType(DBT_INTEGER);
        schemaItem39->setDataDesc(col39Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem39);
       

        //this is the 40. column
        DataObjDesc * col40Obj = new DataObjDesc();
        col40Obj->setDataObjName("Col40");
        col40Obj->setDataObjDType(DT_INT8);
        col40Obj->setIsConstItem(false, false);
        col40Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem40 = new SchemaItem();
        schemaItem40->setColumnName("fofId");
        schemaItem40->setColumnDBType(DBT_BIGINT);
        schemaItem40->setDataDesc(col40Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem40);
        
        
        //this is the 41. column
        DataObjDesc * col41Obj = new DataObjDesc();
        col41Obj->setDataObjName("Col41");
        col41Obj->setDataObjDType(DT_INT4);
        col41Obj->setIsConstItem(false, false);
        col41Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem41 = new SchemaItem();
        schemaItem41->setColumnName("ix");
        schemaItem41->setColumnDBType(DBT_INTEGER);
        schemaItem41->setDataDesc(col41Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem41);
       

        //this is the 42. column
        DataObjDesc * col42Obj = new DataObjDesc();
        col42Obj->setDataObjName("Col42");
        col42Obj->setDataObjDType(DT_INT4);
        col42Obj->setIsConstItem(false, false);
        col42Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem42 = new SchemaItem();
        schemaItem42->setColumnName("iy");
        schemaItem42->setColumnDBType(DBT_INTEGER);
        schemaItem42->setDataDesc(col42Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem42);
       

        //this is the 43. column
        DataObjDesc * col43Obj = new DataObjDesc();
        col43Obj->setDataObjName("Col43");
        col43Obj->setDataObjDType(DT_INT4);
        col43Obj->setIsConstItem(false, false);
        col43Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem43 = new SchemaItem();
        schemaItem43->setColumnName("iz");
        schemaItem43->setColumnDBType(DBT_INTEGER);
        schemaItem43->setDataDesc(col43Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem43);     
       

        //this is the 44. column
        DataObjDesc * col44Obj = new DataObjDesc();
        col44Obj->setDataObjName("Col44");
        col44Obj->setDataObjDType(DT_INT4);
        col44Obj->setIsConstItem(false, false);
        col44Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem44 = new SchemaItem();
        schemaItem44->setColumnName("phkey");
        schemaItem44->setColumnDBType(DBT_INTEGER);
        schemaItem44->setDataDesc(col44Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem44);
       

        //this is the 45. column
        DataObjDesc * col45Obj = new DataObjDesc();
        col45Obj->setDataObjName("Col45");
        col45Obj->setDataObjDType(DT_REAL4);
        col45Obj->setIsConstItem(false, false);
        col45Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem45 = new SchemaItem();
        schemaItem45->setColumnName("angMom");
        schemaItem45->setColumnDBType(DBT_FLOAT);
        schemaItem45->setDataDesc(col45Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem45);
       

        //this is the 46. column
        DataObjDesc * col46Obj = new DataObjDesc();
        col46Obj->setDataObjName("Col46");
        col46Obj->setDataObjDType(DT_REAL4);
        col46Obj->setIsConstItem(false, false);
        col46Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem46 = new SchemaItem();
        schemaItem46->setColumnName("size");
        schemaItem46->setColumnDBType(DBT_FLOAT);
        schemaItem46->setDataDesc(col46Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem46);
       

        //this is the 47. column
        DataObjDesc * col47Obj = new DataObjDesc();
        col47Obj->setDataObjName("Col47");
        col47Obj->setDataObjDType(DT_REAL4);
        col47Obj->setIsConstItem(false, false);
        col47Obj->setIsHeaderItem(false);
        
        //then describe the SchemaItem which represents the data on the server side
        SchemaItem * schemaItem47 = new SchemaItem();
        schemaItem47->setColumnName("spin");
        schemaItem47->setColumnDBType(DBT_FLOAT);
        schemaItem47->setDataDesc(col47Obj);
        
        //add schema item to the schema
        returnSchema->addItemToSchema(schemaItem47);
       

        
        
        
        return returnSchema;
    }
}
