	//цр
    gAreas[arCentralRinok] = CreateDynamicSphere(1124.3383,-1472.4784,16.1252,100.0);

    palatki[41] = CreateDynamicObject(18663, 2216.960693, -1701.421509, 13.558271, 0.000000, 0.000000, 354.299774, -1, -1, -1, STREAMER_OBJECT_SD, 50.0); // 1
    SetDynamicObjectMaterialText(palatki[41], 0, "Номер 41. {30A332}Свободная!", 130, "Georgia", 19, 1, 0xFFFFFFFF, 0, 1);
    palatki[42] = CreateDynamicObject(18663, 2217.942139, -1694.790405, 13.729736, 0.000000, 0.000000, 347.999817, -1, -1, -1, STREAMER_OBJECT_SD, 50.0); // 1
    SetDynamicObjectMaterialText(palatki[42], 0, "Номер 42. {30A332}Свободная!", 130, "Georgia", 19, 1, 0xFFFFFFFF, 0, 1);
    palatki[43] = CreateDynamicObject(18663, 2219.010742, -1690.188477, 13.788406, 0.000000, 0.000000, 346.899841, -1, -1, -1, STREAMER_OBJECT_SD, 50.0); // 1
    SetDynamicObjectMaterialText(palatki[43], 0, "Номер 43. {30A332}Свободная!", 130, "Georgia", 19, 1, 0xFFFFFFFF, 0, 1);
    palatki[44] = CreateDynamicObject(18663, 2220.106201, -1685.490234, 14.016439, 0.000000, 0.000000, 346.899841, -1, -1, -1, STREAMER_OBJECT_SD, 50.0); // 1
    SetDynamicObjectMaterialText(palatki[44], 0, "Номер 44. {30A332}Свободная!", 130, "Georgia", 19, 1, 0xFFFFFFFF, 0, 1);
    palatki[45] = CreateDynamicObject(18663, 2221.564697, -1679.226074, 14.352262, 0.000000, 0.000000, 346.899841, -1, -1, -1, STREAMER_OBJECT_SD, 50.0); // 1
    SetDynamicObjectMaterialText(palatki[45], 0, "Номер 45. {30A332}Свободная!", 130, "Georgia", 19, 1, 0xFFFFFFFF, 0, 1);
    palatki[46] = CreateDynamicObject(18663, 2223.712891, -1669.995239, 14.832420, 0.000000, 0.000000, 346.899841, -1, -1, -1, STREAMER_OBJECT_SD, 50.0); // 1
    SetDynamicObjectMaterialText(palatki[46], 0, "Номер 46. {30A332}Свободная!", 130, "Georgia", 19, 1, 0xFFFFFFFF, 0, 1);
	for(new i; i < 46; i++)
	{
		CreateDynamic3DTextLabel(!"{FFFFFF}Лавка:\n{FAAC58}ALT", COLOR_WHITE, LavkaPos[i][0],LavkaPos[i][1],LavkaPos[i][2], 3.0);
	}
    ///counts
    gPremiumContDor[0] = CreateDynamicObject(19426, -1733.967407, 156.626068, 5.192699, -0.000052, 540.000000, -89.999847, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[0], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    gPremiumContDor[1] = CreateDynamicObject(19426, -1732.376587, 156.626068, 5.192699, 0.000059, 0.000000, 89.999817, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[1], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //2kont
    gPremiumContDor[2] = CreateDynamicObject(19426, -1723.385864, 186.246567, 5.178199, -0.000052, 540.000000, -89.999847, 0, 0, -1, 300.00, 300.00);
    gPremiumContDor[3] = CreateDynamicObject(19426, -1721.795044, 186.246567, 5.178199, 0.000059, 0.000000, 89.999817, 0, 0, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gPremiumContDor[2], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    SetDynamicObjectMaterial(gPremiumContDor[3], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //3kont
    gPremiumContDor[4] = CreateDynamicObject(19426, -1733.945435, 188.811066, 5.192699, -0.000052, 540.000000, -89.999847, 0, 0, -1, 300.00, 300.00);
    gPremiumContDor[5] = CreateDynamicObject(19426, -1732.354614, 188.811066, 5.192699, 0.000059, 0.000000, 89.999817, 0, 0, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gPremiumContDor[4], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    SetDynamicObjectMaterial(gPremiumContDor[5], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //4Kont
    gPremiumContDor[6] = CreateDynamicObject(19426, -1740.197998, 191.400772, 5.178199, -0.000052, 540.000000, -89.999847, 0, 0, -1, 300.00, 300.00);
    gPremiumContDor[7] = CreateDynamicObject(19426, -1738.607178, 191.400772, 5.178199, 0.000059, 0.000000, 89.999817, 0, 0, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gPremiumContDor[6], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    SetDynamicObjectMaterial(gPremiumContDor[7], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //5Kont
    gPremiumContDor[8] = CreateDynamicObject(19426, -1723.345703, 153.606674, 5.178199, -0.000052, 540.000000, -89.999847, 0, 0, -1, 300.00, 300.00);
    gPremiumContDor[9] = CreateDynamicObject(19426, -1721.754883, 153.606674, 5.178199, 0.000059, 0.000000, 89.999817, 0, 0, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gPremiumContDor[8], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    SetDynamicObjectMaterial(gPremiumContDor[9], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    /////
    //6kont
    gPremiumContDor[10] = CreateDynamicObject(19426, -1723.379028, 123.278084, 5.178199, -0.000052, 540.000000, -89.999847, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[10], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    gPremiumContDor[11] = CreateDynamicObject(19426, -1721.788208, 123.278084, 5.178199, 0.000059, 0.000000, 89.999817, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[11], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //7kont
    gPremiumContDor[12] = CreateDynamicObject(19426, -1729.997070, 137.012177, 5.192699, -0.000052, 540.000000, -89.999847, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[12], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    gPremiumContDor[13] = CreateDynamicObject(19426, -1728.406250, 137.012177, 5.192699, 0.000059, 0.000000, 89.999817, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[13], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //8kont
    gPremiumContDor[14] = CreateDynamicObject(19426, -1740.278564, 138.887177, 5.178199, -0.000052, 540.000000, -89.999847, 0, 0, -1, 300.00, 300.00);
    gPremiumContDor[15] = CreateDynamicObject(19426, -1738.687744, 138.887177, 5.178199, 0.000059, 0.000000, 89.999817, 0, 0, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gPremiumContDor[14], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    SetDynamicObjectMaterial(gPremiumContDor[15], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    //9kont
    gPremiumContDor[16] = CreateDynamicObject(19426, -1733.967896, 120.745483, 5.192699, -0.000052, 540.000000, -89.999847, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[16], 0, 3564, "dockcargo2_las", "lastrk5", 0);
    gPremiumContDor[17] = CreateDynamicObject(19426, -1732.377075, 120.745483, 5.192699, 0.000059, 0.000000, 89.999817, -1, -1);
    SetDynamicObjectMaterial(gPremiumContDor[17], 0, 3564, "dockcargo2_las", "lastrk5", 0);