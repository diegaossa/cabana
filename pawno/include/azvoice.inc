new 
    Iterator:AzVoiceZone<MAX_VEHICLES + MAX_PLAYERS + MAX_PLAYERS>,
    AzVoiceZoneType[2][MAX_VEHICLES + MAX_PLAYERS + MAX_PLAYERS];

stock CreateZoneAZVoice(zoneId, zoneTypeId, attachedId, const attachText[] = "", textColor = 0xffffffff, forplayerid = INVALID_PLAYER_ID)
{   
    if(forplayerid != INVALID_PLAYER_ID && !pTemp[forplayerid][pVoiceInitied])
        return false;

    if(zoneId == -1)
    {
        zoneId = Iter_Free(AzVoiceZone);
        Iter_Add(AzVoiceZone, zoneId);
    }

    if(zoneId >= MAX_VEHICLES + MAX_PLAYERS + MAX_PLAYERS)
        return (forplayerid != INVALID_PLAYER_ID ? SCM(forplayerid, 0xff0000ff, !"[DEBUG] Для CreateZoneAZVoice закончились слоты, передайте разработчику.") : _:false);

    new BitStream:bs = BS_New();

	BS_WriteValue(bs,
		PR_UINT8, 10,
		PR_UINT16, zoneId + 1,
		PR_UINT16, strlen(attachText),
		PR_STRING, attachText,
		PR_UINT32, textColor,
		PR_UINT8, AzVoiceZoneType[0][zoneId] = zoneTypeId,
		PR_UINT16, AzVoiceZoneType[1][zoneId] = attachedId,
		PR_UINT32, 0);

    if(forplayerid == INVALID_PLAYER_ID)
    {
        if(zoneTypeId == 2)
            sendVoiceData(bs, attachedId, 2, 252, attachedId, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);

        else if(zoneTypeId == 3)
            sendVoiceData(bs, attachedId, 1, 252, INVALID_PLAYER_ID, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);
    }
    else
        sendVoiceData(bs, forplayerid, 2, 252, forplayerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);

	return BS_Delete(bs);
}

stock PlayZoneAZVoice(zoneId, const audioLink[], audioPlayTime, forplayerid = INVALID_PLAYER_ID)
{
    if(!Iter_Contains(AzVoiceZone, zoneId))
        return false;

	new BitStream:bs = BS_New();

	BS_WriteValue(bs,
		PR_UINT8, 17,
		PR_UINT16, zoneId + 1,
		PR_BOOL, true,
		PR_UINT16, strlen(audioLink),
		PR_STRING, audioLink,
		PR_FLOAT, 0.0,
		PR_FLOAT, 0.7);

	if(audioPlayTime)
		BS_WriteValue(bs,
			PR_BOOL, true,
			PR_UINT32, audioPlayTime);

    if(forplayerid == INVALID_PLAYER_ID && AzVoiceZoneType[0][zoneId] == 3)
        sendVoiceData(bs, AzVoiceZoneType[1][zoneId], 1, 252, INVALID_PLAYER_ID, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);

    else
        sendVoiceData(bs, forplayerid, 2, 252, forplayerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);
	
	return BS_Delete(bs);
}

stock RemoveZoneAZVoice(zoneId, bool:destroy = false, forplayerid = INVALID_PLAYER_ID)
{
    if(zoneId == -1)
        return false;

	new BitStream:bs = BS_New();

	BS_WriteValue(bs, 
		PR_UINT8, destroy ? 11 : 13, 
		PR_UINT16, zoneId + 1);
        
    if(forplayerid == INVALID_PLAYER_ID)
    {
        if(AzVoiceZoneType[0][zoneId] == 2)
            sendVoiceData(bs, AzVoiceZoneType[1][zoneId], 2, 252, INVALID_PLAYER_ID, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5), sendVoiceData(bs, AzVoiceZoneType[1][zoneId], 2, 252, AzVoiceZoneType[1][zoneId], PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);

        else if(AzVoiceZoneType[0][zoneId] == 3)
            sendVoiceData(bs, AzVoiceZoneType[1][zoneId], 1, 252, INVALID_PLAYER_ID, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);
    }
    else
        sendVoiceData(bs, forplayerid, 2, 252, forplayerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5);

    return BS_Delete(bs);
}

cmd:audios(playerid, data[])
{
    mysql_string = "";

    if(sscanf(data, "is[256]i", data[0], mysql_string, data[1]))
        return false;

    return PlayZoneAZVoice(data[0], mysql_string, data[1]);
}

stock SearchAZVoiceZoneID(zone_type, zone_attachid)
{
    for(new i; i < Iter_Count(AzVoiceZone); i++)
        if(AzVoiceZoneType[0][i] == zone_type && AzVoiceZoneType[1][i] == zone_attachid)
            return i;

    return INVALID_DATA_ID;
}

stock sendPlayerVoiceKey(playerid, keyid, const name[])
{
	new BitStream:bs = BS_New();

    BS_WriteValue(bs, 
        PR_UINT8, 6,
        PR_UINT8, keyid,
        PR_UINT16, strlen(name),
        PR_STRING, name);

    return sendVoiceData(bs, playerid, 2, 252, playerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5), BS_Delete(bs);
}

stock toggleVoiceState(playerid, bool:status = false)
{
    if(!pTemp[playerid][pVoiceInitied])
        return false;

    new BitStream:bs = BS_New();

    BS_WriteValue(bs,
        PR_UINT8, 19,
        PR_UINT16, 0,
        PR_BOOL, status);

    return sendVoiceData(bs, playerid, 2, 252, playerid, PR_HIGH_PRIORITY, PR_RELIABLE_ORDERED, 5), BS_Delete(bs);
}

IPacket:252(playerid, BitStream:bs)
{
    if(!GetPlayerLauncher(playerid) || !pTemp[playerid][pVoiceKeyPressed])
        return false;

    if(PI[playerid][pMuteTime])
        return SendMuteMessage(playerid);

    new channel[2], bytesNum, BitStream:bsn = BS_New();

    BS_ReadValue(bs, PR_IGNORE_BITS, 8, PR_UINT8, channel[0], PR_UINT8, channel[1], PR_IGNORE_BITS, 8);

    foreach(new i: Player)
    {
        if (!pTemp[i][pVoiceInitied] || !IsPlayerStreamedIn(i, playerid)) 
            continue;

        BS_WriteValue(bsn, PR_UINT8, 252, PR_UINT16, playerid, PR_UINT8, channel[0], PR_UINT8, channel[1], PR_UINT16, 1, PR_UINT16, MAX_PLAYERS + MAX_VEHICLES + playerid + 1);

        BS_GetNumberOfBytesUsed(bs, bytesNum);

        for(new j = 4, id; j < bytesNum; j++)
            BS_ReadValue(bs, PR_UINT8, id), BS_WriteValue(bsn, PR_UINT8, id);

        sendVoiceData(bsn, playerid, 2, INVALID_DATA_ID, i, PR_HIGH_PRIORITY, PR_UNRELIABLE_SEQUENCED, 5), BS_Delete(bsn);
    }
    return true;
}

ICustomRPC:252(playerid, BitStream:bs)
{
    if(!GetPlayerLauncher(playerid))
        return false;

    new customid;
    BS_ReadValue(bs, PR_UINT8, customid);

    if(customid == 5)
    {
        static bool:status;
        BS_ReadValue(bs, PR_IGNORE_BITS, 8, PR_BOOL, status);
        pTemp[playerid][pVoiceKeyPressed] = status;

    }

    return true;
}

stock sendVoiceData(BitStream:bs, sendId, typeId, rpcId = INVALID_DATA_ID, forplayerid = INVALID_PLAYER_ID, PR_PacketPriority:priority = PR_HIGH_PRIORITY, PR_PacketReliability:reliability = PR_RELIABLE_ORDERED, orderingchannel = 0)
{
    foreach (new i: Player)
    {
        new target = forplayerid != INVALID_PLAYER_ID ? forplayerid : i;

        if (!pTemp[target][pVoiceInitied]) continue;

        if (forplayerid == INVALID_PLAYER_ID && ((typeId == 1 && !IsVehicleStreamedIn(sendId, i)) || (typeId == 2 && !IsPlayerStreamedIn(i, sendId))))
            continue;

        if (rpcId == INVALID_DATA_ID)
            PR_SendPacket(bs, target, priority, reliability, orderingchannel);

        else
            PR_SendRPC(bs, target, rpcId, priority, reliability, orderingchannel);

        if(forplayerid != INVALID_PLAYER_ID)
            break;
    }
    return true;
}