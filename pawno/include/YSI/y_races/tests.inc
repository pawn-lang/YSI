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
