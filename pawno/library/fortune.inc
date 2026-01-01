
public: fortunetimer()//fortune
{
	if(fortunestep > 0)
	{
	    FortuneMove();
		fortunestep--;
	}
	else
	{
	    SetCameraBehindPlayer(fortunestarter);
		TogglePlayerControllable(fortunestarter, true);
		new a = Rand(10, 40);
  		new b = Rand(1000, 50000);
		switch(random(100))
		{
		    case 0..10: GiveDonate(fortunestarter, b), SCMF(fortunestarter, 0xAFAFAFFF, "Вы получили AZ Coins в размере %d", b);
		    case 11..16: GiveDonateMoney(fortunestarter, a), SCMF(fortunestarter, 0xAFAFAFFF, "Вы получили AZ Rub в размере %d",a);
		    case 17..30: AddItem(fortunestarter, 730	, 10), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили EXP в размере 10");
			case 31..40: AddItem(fortunestarter, 1811, 10), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили BTC в размере 10");
			case 41..50: AddItem(fortunestarter, 555, 10), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили Бронзовую рулетку в размере 10");
			case 51..60: AddItem(fortunestarter, 556, 10), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили Серебряную рулетку в размере 10");
			case 61..70: AddItem(fortunestarter, 557, 10), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили Золотую рулетку в размере 10");
			case 71..90: AddItem(fortunestarter, 530, 100000), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили Фишки казино в размере 100000");
			case 91..95: AddItem(fortunestarter, 522, 5000), SCM(fortunestarter, 0xAFAFAFFF, "Вы получили Семейный талон в размере 5000");
			case 96..99:
			{
       			AddItem(fortunestarter, 7474, 1);
       			SCM(fortunestarter, 0xAFAFAFFF, "ПОЗДРАВЛЯЕМ! Вы получили ГЛАВНЫЙ ПРИЗ: Apollo Intensa Emozione");
			}
		}
		fortunestarter = -1;
	    KillTimer(fortunespeed);
	}
}
	
stock FortuneMove()
{
    new Float:x, Float:y, Float:z, Float:Rx, Float:Ry, Float:Rz;
	GetObjectPos(fortune, x, y, z);
	GetObjectRot(fortune, Rx, Ry, Rz);
    Ry += 18.0;
    if(Ry >= 360.0) Ry = 0.0;
    MoveObject(fortune, x, y, z, 0.5, Rx, Ry, Rz);
}
stock Rand(min, max)
{
	new a = random(max - min) + min;
	return a;
}

stock GiveDonateMoney(playerid, money)
{
	if(playerid == INVALID_PLAYER_ID) return false;
	if(!IsPlayerLogged{playerid}) return false;
	if(PI[playerid][pRoubles]+money < 0)
	{
		SCM(playerid, COLOR_LIGHTRED, !"[Ошибка] {FFFFFF}Вы превысили лимит AZ-RUB!");
		return SCM(playerid, COLOR_VALIK, !"[Информация] {FFFFFF}Вы не можете их получить, иначе они уйдут в минус!");
	}
	PI[playerid][pRoubles] += money;
	UpdatePlayerDataInt(playerid, "Roubles", PI[playerid][pRoubles]);
	return GameTextForPlayerf(playerid, 3000, 3, "~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~w~%iAZ-RUB", money);
}
stock GetNameCar(model)
{
	if(model <= 611) return VehicleName[model-400];
	static name[28];
	name = "Invalid";
	for(new i; i < sizeof(NewCar); i++)
	{
		if(NewCar[i][NewCarLauncher] == model)
		{
			SetString(name, NewCar[i][NewCarName]);
			break;
		}
	}
}