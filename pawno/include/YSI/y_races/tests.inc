new
	g_sRaceID;

Test:y_races_Create()
{
	g_sRaceID = Race_Create();
	ASSERT(g_sRaceID == 0);
	Race_Destroy(g_sRaceID);
}

Test:y_races_Destroy()
{
	g_sRaceID = Race_Create();
	ASSERT(g_sRaceID == 0);
	Race_Destroy(g_sRaceID);
	g_sRaceID = Race_Create();
	ASSERT(g_sRaceID == 0);
	Race_Destroy(g_sRaceID);
}

Test:y_races_ArrayAdd0()
{
	for (new i = 0; i != 10; ++i)
	{
		YSI_g_sRaceCheckpoints[i][0] = i + 1;
		YSI_g_sRaceCheckpoints[i][1] = i + 1;
		YSI_g_sRaceCheckpoints[i][2] = i + 1;
	}
	YSI_g_sCPIndex = 10;
	RaceArray_Add(10, 11.0, 11.0, 11.0);
	for (new i = 0; i != 11; ++i)
	{
		ASSERT(YSI_g_sRaceCheckpoints[i][0] == i + 1);
		ASSERT(YSI_g_sRaceCheckpoints[i][1] == i + 1);
		ASSERT(YSI_g_sRaceCheckpoints[i][2] == i + 1);
	}
	YSI_g_sCPIndex = 0;
}

Test:y_races_ArrayAdd1()
{
	for (new i = 0; i != 10; ++i)
	{
		YSI_g_sRaceCheckpoints[i][0] = i + 1;
		YSI_g_sRaceCheckpoints[i][1] = i + 1;
		YSI_g_sRaceCheckpoints[i][2] = i + 1;
	}
	YSI_g_sCPIndex = 10;
	RaceArray_Add(6, 22.0, 22.0, 22.0);
	for (new i = 0; i != 6; ++i)
	{
		ASSERT(YSI_g_sRaceCheckpoints[i][0] == i + 1);
		ASSERT(YSI_g_sRaceCheckpoints[i][1] == i + 1);
		ASSERT(YSI_g_sRaceCheckpoints[i][2] == i + 1);
	}
	ASSERT(YSI_g_sRaceCheckpoints[6][0] == 22.0);
	ASSERT(YSI_g_sRaceCheckpoints[6][1] == 22.0);
	ASSERT(YSI_g_sRaceCheckpoints[6][2] == 22.0);
	for (new i = 7; i != 11; ++i)
	{
		ASSERT(YSI_g_sRaceCheckpoints[i][0] == i);
		ASSERT(YSI_g_sRaceCheckpoints[i][1] == i);
		ASSERT(YSI_g_sRaceCheckpoints[i][2] == i);
	}
	YSI_g_sCPIndex = 0;
}

Test:y_races_ArrayShift()
{
	new
		to = 10;
	for (new i = 0; i != 10; ++i)
	{
		YSI_g_sRaceCheckpoints[i][0] = i + 1;
		YSI_g_sRaceCheckpoints[i][1] = i + 1;
		YSI_g_sRaceCheckpoints[i][2] = i + 1;
	}
	RaceArray_Shift(5, to, 6);
	YSI_g_sRaceCheckpoints[5][0] = 66.5;
	YSI_g_sRaceCheckpoints[5][1] = 66.5;
	YSI_g_sRaceCheckpoints[5][2] = 66.5;
	ASSERT(to == 11);
	for (new i = 0; i != 5; ++i)
	{
		ASSERT(YSI_g_sRaceCheckpoints[i][0] == i + 1);
		ASSERT(YSI_g_sRaceCheckpoints[i][1] == i + 1);
		ASSERT(YSI_g_sRaceCheckpoints[i][2] == i + 1);
	}
	ASSERT(YSI_g_sRaceCheckpoints[5][0] == 66.5);
	ASSERT(YSI_g_sRaceCheckpoints[5][1] == 66.5);
	ASSERT(YSI_g_sRaceCheckpoints[5][2] == 66.5);
	for (new i = 6; i != 11; ++i)
	{
		ASSERT(YSI_g_sRaceCheckpoints[i][0] == i);
		ASSERT(YSI_g_sRaceCheckpoints[i][1] == i);
		ASSERT(YSI_g_sRaceCheckpoints[i][2] == i);
		//printf("%.2f %.2f %.2f", YSI_g_sRaceCheckpoints[0][i][0], YSI_g_sRaceCheckpoints[0][i][1], YSI_g_sRaceCheckpoints[0][i][2]);
	}
}
