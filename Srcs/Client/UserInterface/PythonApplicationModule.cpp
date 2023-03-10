/// 1.
// Search
#ifdef ENABLE_ENERGY_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_ENERGY_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_ENERGY_SYSTEM", 0);
#endif

// Add below
#if defined(ENABLE_LUCKY_BOX)
	PyModule_AddIntConstant(poModule, "ENABLE_LUCKY_BOX", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_LUCKY_BOX", 0);
#endif

#if defined(ENABLE_GACHA)
	PyModule_AddIntConstant(poModule, "ENABLE_GACHA", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_GACHA", 0);
#endif
