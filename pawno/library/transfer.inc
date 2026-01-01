CMD:transfer(playerid)
{
    if !PI[playerid][pVkontakte] *then
		return SCM(playerid, COLOR_OLDRED, "[Ошибка] {FFFFFF}Для перевода аккаунта вам необходимо привязать ВКонтакте - [/settings - Привязка ВКонтакте]");

	f(global_str, sizeof(global_str), "{cccccc}Информация | {ae433d}%s", PN(playerid));

	if !TranslationValidation(playerid) *then
		SPD(playerid, 18704, DIALOG_STYLE_LIST, global_str, "{ae433d}— {FFFFFF}Перейти к оформлению перевода аккаунта.\n{ae433d}— {FFFFFF}Информация к переводам.", "»", "x");

	else 
		SPD(playerid, 18704, DIALOG_STYLE_LIST, global_str, "{ae433d}— {FFFFFF}Информация о поданом Вами переводе.\n{ae433d}— {FFFFFF}Информация к переводам.", "»", "x");

	return true;
}

stock ShowTransferDialog(playerid, transfering = 0)
{
	switch(Transfer[playerid][PerevodDialog])
	{
	    case 0: SPD(playerid, 18705, DIALOG_STYLE_LIST, "{cccccc}Регистрация данных | {ae433d}Выбор сервера", "{FFFFFF}Arizona RP {ae433d}Paige\n{FFFFFF}Arizona RP {ae433d}Arena\n{FFFFFF}Arizona RP {ae433d}Marti\n{FFFFFF}Arizona RP {ae433d}Perfect\n{FFFFFF}Arizona RP {ae433d}BonusLand\n{FFFFFF}Arizona RP {ae433d}Coolidge\n{FFFFFF}Arizona RP {ae433d}Summer\n{FFFFFF}Arizona RP {ae433d}Bonusnik\n{FFFFFF}Arizona RP {ae433d}Sedona\n{FFFFFF}Arizona RP {ae433d}Cladman", "Далее", "Отмена");
		case 1:
		{
			if(!transfering) SPDF(playerid, 18705, DIALOG_STYLE_INPUT, "{cccccc}Регистрация данных | {ae433d}Перевод аккаунта", "{FFFFFF}Введите игровые данные от проекта {ae433d}%s {FFFFFF}по инструкции предоставленной ниже.\n{ae433d}Подсказка: {FFFFFF}Ваш Nick и Пароль (Yevhen_Kosovskyi | N99h67Pgcr9DRooD)\n{FFFFFF}После успешного ввода данных нажимте \"Далее\"", "Далее", "Назад", Transfer[playerid][PerevodServer]);
			else SPDF(playerid, 18705, DIALOG_STYLE_INPUT, "{cccccc}Регистрация данных | {ae433d}Перевод аккаунта", "{FFFFFF}Введите игровые данные от проекта {ae433d}%s {FFFFFF}по инструкции предоставленной ниже.\n{ae433d}Подсказка: {FFFFFF}Ваш Nick и Пароль (Yevhen_Kosovskyi | N99h67Pgcr9DRooD)\n{FFFFFF}После успешного ввода данных нажимте \"Далее\"", "Далее", "Назад", Transfer[playerid][PerevodServer]);
		}
		case 2:
		{
		    SAMF(COLOR_OLDRED, "[Предупреждение] {FFFFFF}Игрок другого проекта %s(%d) зарегистрировал новую заявку на перевод игрового аккаунта.", PN(playerid), playerid);
			SPDF(playerid, 0, 0, "{cccccc}Информация | {ae433d}Завершение перевода", "{ae433d}%s {FFFFFF}ваше заявление на перевод аккаунта успешно\nотправлено на рассмотрение руководителей проекта, оно может рассматриваться до 48 рабочих часов.\n\nДополнительные сведения:\n\
			{FFFFFF}Сервер с которого Вы хотите перевестись: {ae433d}%s.\n\
			{FFFFFF}Ваш ник-нейм на сервере с которого Вы переводитесь: {ae433d}%s.\n\
			{FFFFFF}Пароль от аккаунта: {ae433d}%s.", "Закрыть", "", PN(playerid), Transfer[playerid][PerevodServer], Transfer[playerid][PerevodNick], Transfer[playerid][PerevodPassword]);
			SQL("INSERT INTO `transfer` (`NickName`, `PerevodNick`, `PerevodPassword`, `PerevodServer`, `Status`) VALUES ('%s', '%s', '%s', '%s', '0');", PN(playerid), Transfer[playerid][PerevodNick], Transfer[playerid][PerevodPassword], Transfer[playerid][PerevodServer]);
		}
	}
	return 1;
}

stock TranslationValidation(playerid)
{
    new
		validation = cache_num_rows();

    f(mysql_string, 128, "SELECT `NickName` FROM `Transfer` WHERE `NickName` = '%s' LIMIT 1", PN(playerid));
    mysql_query(mysql, mysql_string);

	return validation;
}
