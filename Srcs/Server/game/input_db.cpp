/// 1.
// Search
	char szDragonSoulTableFileName[FILE_NAME_LEN];

// Add below
#if defined(__LUCKY_BOX__)
	char szLuckyBoxFileName[FILE_NAME_LEN];
#endif

/// 2.
// Search
	snprintf(szDragonSoulTableFileName, sizeof(szDragonSoulTableFileName),
		"%s/dragon_soul_table.txt", LocaleService_GetBasePath().c_str());

// Add below
#if defined(__LUCKY_BOX__)
	snprintf(szLuckyBoxFileName, sizeof(szLuckyBoxFileName),
		"%s/lucky_box.txt", LocaleService_GetBasePath().c_str());
#endif

/// 3.
// Search
	sys_log(0, "LoadLocaleFile: DragonSoulTable: %s", szDragonSoulTableFileName);
	if (!DSManager::instance().ReadDragonSoulTableFile(szDragonSoulTableFileName))
	{
		sys_err("cannot load DragonSoulTable: %s", szDragonSoulTableFileName);
		thecore_shutdown();
		return;
	}

// Add below
#if defined(__LUCKY_BOX__)
	sys_log(0, "LoadLocaleFile: LuckyBoxFile: %s", szLuckyBoxFileName);
	if (!ITEM_MANAGER::instance().ReadLuckyBoxFile(szLuckyBoxFileName))
	{
		sys_err("cannot load LuckyBoxFile: %s", szLuckyBoxFileName);
		thecore_shutdown();
		return;
	}
#endif

/// 4.
// Search
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen())

// Replace with
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__LUCKY_BOX__)
		|| ch->IsLuckyBoxOpen()
#endif
		)
