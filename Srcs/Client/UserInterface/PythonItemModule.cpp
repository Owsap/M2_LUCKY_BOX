/// 1.
// Add to the bottom of the file above }
#if defined(ENABLE_GACHA)
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_GACHA", CItemData::ITEM_TYPE_GACHA);
	PyModule_AddIntConstant(poModule, "USE_GACHA", CItemData::USE_GACHA);
#if defined(ENABLE_LUCKY_BOX)
	PyModule_AddIntConstant(poModule, "GEM_LUCKY_BOX_GACHA", CItemData::GEM_LUCKY_BOX_GACHA);
	PyModule_AddIntConstant(poModule, "SPECIAL_LUCKY_BOX_GACHA", CItemData::SPECIAL_LUCKY_BOX_GACHA);
#endif
#endif
