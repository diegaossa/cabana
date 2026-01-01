

public: UpdateEnchant(playerid, item, stone)
{
	if !IsPlayerLogged{playerid} || !EnchantWork{playerid} *then return KillTimer(EnchantTimer[playerid]);

	new progress = EnchantWorkProgress[playerid];

	if progress < 51 *then
		PlayerTextDrawTextSize(playerid, EnchantWorkTD[playerid][18], 2.730324 * progress, 6.469632),
		ShowPlayerTD(playerid, EnchantWorkTD[playerid][18]);

	else if progress == 51 *then
	{
		new status;
		if IsNashivka(Inventory[playerid][0][item]) *then status = (GetChanceNashivka(Inventory[playerid][2][item]) * (GetPlayerADDVIP(playerid) ? 2:1) * (Inventory[playerid][0][stone] == 1502 ? 2:1) < 1 + random(1000));
		else status = (GetChanceEnchant(Inventory[playerid][2][item]) * (GetPlayerADDVIP(playerid) ? 2:1) * (Inventory[playerid][0][stone] == 1502 ? 2:1) < 1 + random(1000));

		if status *then
			SCMF(playerid, COLOR_RED, "”вы, вам не удалось улучшить предмет %s с +%d на +%d", ItemsInfo[Inventory[playerid][0][item]][itemName], Inventory[playerid][2][item], Inventory[playerid][2][item] + 1);
		else 
			SCMF(playerid, COLOR_VALIK, "”спех! ¬ам удалось улучшить предмет %s с +%d на +%d", ItemsInfo[Inventory[playerid][0][item]][itemName], Inventory[playerid][2][item], Inventory[playerid][2][item] + 1),
			Inventory[playerid][2][item] ++,
			InvSlotUpdate(playerid, GetInvID(playerid, item, 1), item);
		
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][12], PI[playerid][pLanguage] ? (FixText("«ј“ќ„»“№")) : ("ENCHANT")), PlayerTextDrawTextSize(playerid, EnchantWorkTD[playerid][18], 0.0, 6.469632), ShowPlayerTD(playerid, EnchantWorkTD[playerid][18]);
		EnchantWorkProgress[playerid] += status ? 100:200;
		return ClearItem(playerid, stone, 1);
	}
	else
	{
		static const color[9][2] = 
		{
			{0xFF4D4D5A, 0x4DFF5A5A},
			{0xFF4D4D50, 0x4DFF5A50},
			{0xFF4D4D46, 0x4DFF5A46},
			{0xFF4D4D3C, 0x4DFF5A3C},
			{0xFF4D4D32, 0x4DFF5A32},
			{0xFF4D4D28, 0x4DFF5A28},
			{0xFF4D4D1E, 0x4DFF5A1E},
			{0xFF4D4D14, 0x4DFF5A14},
			{0xFF4D4D0A, 0x4DFF5A0A}
		};

		new color_mas_id = (progress > 200) ? 1:0, count = color_mas_id ? progress-251:progress-151;

		PlayerTextDrawBoxColor(playerid, EnchantWorkTD[playerid][23], color[count][color_mas_id]);
		PlayerTextDrawBoxColor(playerid, EnchantWorkTD[playerid][22], color[count][color_mas_id]);

		ShowPlayerTD(playerid, EnchantWorkTD[playerid][23]);
		ShowPlayerTD(playerid, EnchantWorkTD[playerid][22]);

		if count == 8 *then return
			PlayerTextDrawBoxColor(playerid, EnchantWorkTD[playerid][23], 0x00000000),
			PlayerTextDrawBoxColor(playerid, EnchantWorkTD[playerid][22], 0x00000000),
			ShowPlayerTD(playerid, EnchantWorkTD[playerid][23]),
			ShowPlayerTD(playerid, EnchantWorkTD[playerid][22]),
			EnchantWorkProgress[playerid] = 0,
			UpdateEnchantWork(playerid),
			KillTimer(EnchantTimer[playerid]);
	}

	return EnchantWorkProgress[playerid]++;
}

stock GetChanceEnchant(level)
{
	new result;

	switch level do
	{
		case 0: result = 500;
		case 1: result = 300;
		case 2: result = 255;
		case 3: result = 200;
		case 4: result = 155;
		case 5: result = 125;
		case 6: result = 90;
		case 7: result = 45;
		case 8: result = 22;
		case 9: result = 10;
		case 10: result = 10;
		case 11: result = 10;
		case 12: result = 10;
	}
	return result;
}

stock GetChanceNashivka(level)
{
	new result;

	switch level do
	{	
		case 0: result = 45;
		case 1: result = 22;
		case 2: result = 10;
	}
	return result;
}

stock UpdateEnchantWork(playerid)
{
	new slot = EnchantWorkItem[playerid][0] -1, kamen = EnchantWorkItem[playerid][1] -1, item;

	if BizEntered[playerid] == -1 *then
		return DestroyEnchantWork(playerid);
		
	else if slot >= 0 && IsAAks(Inventory[playerid][0][slot]) *then
	{
		item = Inventory[playerid][0][slot];
		

		PlayerTextDrawSetSelectable(playerid, EnchantWorkTD[playerid][0], true);
		PlayerTextDrawFont(playerid, EnchantWorkTD[playerid][0], ItemsInfo[item][itemCustom] == 2 ? 100 : 5);
		PlayerTextDrawSetPreviewModel(playerid, EnchantWorkTD[playerid][0], IsASkinInv(item) && ItemsInfo[item][itemModel] > 311 ? GetSkinInfo(ItemsInfo[item][itemModel]) : ItemsInfo[item][itemModel]);
		PlayerTextDrawSetPreviewRot(playerid, EnchantWorkTD[playerid][0], ItemsInfo[item][itemRotation][0], ItemsInfo[item][itemRotation][1], ItemsInfo[item][itemRotation][2], ItemsInfo[item][itemRotation][3]);
		PlayerTextDrawBackgroundColor(playerid, EnchantWorkTD[playerid][0], ItemsInfo[item][itemColor]);


		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][6], (str_f("+%d", Inventory[playerid][2][slot])));
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][5], (str_f("+%d", Inventory[playerid][2][slot] + 1)));

		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][7], kamen >= 0 ? (str_f("$%d", BizData[BizEntered[playerid]][bItem][0])):"");
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][2], kamen >= 0 ? (str_f("CHANCE: %0.1f", float(GetChanceEnchant( Inventory[playerid][2][slot]) * (PI[playerid][pAddVIP] > Global_Time ? 2:1) * (Inventory[playerid][0][kamen] == 1502 ? 2:1) )/10)):"");
	}
	else if slot >= 0 && IsNashivka(Inventory[playerid][0][slot]) *then
	{
		item = Inventory[playerid][0][slot];

		PlayerTextDrawBackgroundColor(playerid, EnchantWorkTD[playerid][0], ItemsInfo[item][itemColor]);
		PlayerTextDrawSetSelectable(playerid, EnchantWorkTD[playerid][0], true);
		PlayerTextDrawSetPreviewModel(playerid, EnchantWorkTD[playerid][0], ItemsInfo[item][itemModel]);
		PlayerTextDrawSetPreviewRot(playerid, EnchantWorkTD[playerid][0], ItemsInfo[item][itemRotation][0], ItemsInfo[item][itemRotation][1], ItemsInfo[item][itemRotation][2], ItemsInfo[item][itemRotation][3]);
		
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][6], (str_f("%d LVL", Inventory[playerid][2][slot])));
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][5], (str_f("%d LVL", Inventory[playerid][2][slot] + 1)));

		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][7], kamen >= 0 ? (str_f("$%d", BizData[BizEntered[playerid]][bItem][0])):"");
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][2], kamen >= 0 ? (str_f("CHANCE: %0.1f", float(GetChanceNashivka( Inventory[playerid][2][slot]) * (PI[playerid][pAddVIP] > Global_Time ? 2:1) * (Inventory[playerid][0][kamen] == 1502 ? 2:1) )/10)):"");
	}
	else
	{
		PlayerTextDrawBackgroundColor(playerid, EnchantWorkTD[playerid][0], 0x333333FF);
		PlayerTextDrawSetSelectable(playerid, EnchantWorkTD[playerid][0], false);
		PlayerTextDrawSetPreviewModel(playerid, EnchantWorkTD[playerid][0], 1649);
		PlayerTextDrawSetPreviewRot(playerid, EnchantWorkTD[playerid][0], 0.000000, 0.000000, 90.000000, 2.000000);
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][6], "");
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][5], "");
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][7], "");
		PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][2], "");
	}

	PlayerTextDrawBackgroundColor(playerid, EnchantWorkTD[playerid][1], 0x333333FF);
	PlayerTextDrawSetPreviewModel(playerid, EnchantWorkTD[playerid][1], 1649);
	PlayerTextDrawSetPreviewRot(playerid, EnchantWorkTD[playerid][1], 0.000000, 0.000000, 90.000000, 2.000000);

	if kamen >= 0 *then
	{
		PlayerTextDrawBackgroundColor(playerid, EnchantWorkTD[playerid][1], ItemsInfo[Inventory[playerid][0][kamen]][itemColor]);
		PlayerTextDrawSetSelectable(playerid, EnchantWorkTD[playerid][1], true);
		PlayerTextDrawSetPreviewModel(playerid, EnchantWorkTD[playerid][1], ItemsInfo[Inventory[playerid][0][kamen]][itemModel]);
		PlayerTextDrawSetPreviewRot(playerid, EnchantWorkTD[playerid][1], ItemsInfo[Inventory[playerid][0][kamen]][itemRotation][0], ItemsInfo[Inventory[playerid][0][kamen]][itemRotation][1], ItemsInfo[Inventory[playerid][0][kamen]][itemRotation][2], ItemsInfo[Inventory[playerid][0][kamen]][itemRotation][3]);
	}

	PlayerTextDrawSetString(playerid, EnchantWorkTD[playerid][8], kamen >= 0 ? (str_f("X %d", Inventory[playerid][1][kamen])):"");
	PlayerTextDrawSetSelectable(playerid, EnchantWorkTD[playerid][1], kamen >= 0 ? true:false);
	PlayerTextDrawColor(playerid, EnchantWorkTD[playerid][1], kamen >= 0 ? 0xFFFFFFFF:0x999999FF);
	ShowPlayerTD(playerid, EnchantWorkTD[playerid][1]);

	return PlayerPlaySound(playerid, 6801, 0.0, 0.0, 0.0), ShowPlayerTD(playerid, EnchantWorkTD[playerid][0]);
}

stock DestroyEnchantWork(playerid)
{
	HideInvent(playerid);

	for new i; i < 29; i++ do DestroyPlayerTD(playerid, EnchantWorkTD[playerid][i]);
	
	EnchantWork{playerid} = false;

	if EnchantWorkItem[playerid][0] - 1 >= 0 *then InventSlotUse[playerid][EnchantWorkItem[playerid][0] - 1] = false; 
	if EnchantWorkItem[playerid][1] - 1 >= 0 *then InventSlotUse[playerid][EnchantWorkItem[playerid][1] - 1] = false; 

	CancelSelectTextDraw(playerid);
	KillTimer(EnchantTimer[playerid]);
	
	return true;
}

