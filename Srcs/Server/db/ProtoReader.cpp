/// 1.
// Search @ get_Item_Type_Value
	string arType[] = {

// Extend with
	string arType[] = {
		[ . . . ]
#if defined(__GACHA_SYSTEM__)
		"ITEM_GACHA",
#endif
	};

/// 2.
// Search
	static string arSub31[] = {
		"EXTRACT_DRAGON_SOUL",
		"EXTRACT_DRAGON_HEART"
	};

// Add below
#if defined(__GACHA_SYSTEM__)
	static string arSubGacha[] = {
		"USE_GACHA",
#if defined(__LUCKY_BOX__)
		"GEM_LUCKY_BOX_GACHA",
		"SPECIAL_LUCKY_BOX_GACHA",
#endif
	};
#endif

/// 3.
// Search
	static string arSub31[] = {

// Extend with
	static string* arSubType[] = {
		[ . . . ]
#if defined(__GACHA_SYSTEM__)
		arSubGacha,
#endif
	};

/// 4.
// Search
	static int arNumberOfSubtype[_countof(arSubType)] = {

// Extend with
	static int arNumberOfSubtype[_countof(arSubType)] = {
		[ . . . ]
#if defined(__GACHA_SYSTEM__)
		sizeof(arSubGacha) / sizeof(arSubGacha[0]),
#endif
	};
