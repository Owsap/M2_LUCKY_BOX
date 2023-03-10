/// 1.
// Search
	string arType[] = {

// Extend with
	string arType[] = {
		[ . . . ]
		"ITEM_GACHA",
	};

/// 2.
// Search
	string arSub31[] = {
		"EXTRACT_DRAGON_SOUL",
		"EXTRACT_DRAGON_HEART"
	};

// Add below
	string arSubGacha[] = {
		"USE_GACHA",
		"GEM_LUCKY_BOX_GACHA",
		"SPECIAL_LUCKY_BOX_GACHA"
	};

/// 3.
// Search
	static string* arSubType[] = {

// Extend with
	static string* arSubType[] = {
		[ . . . ]
		arSubGacha,
	};

/// 4.
// Search
	static int arNumberOfSubtype[] = {

// Extend with
	static int arNumberOfSubtype[] = {
		[ . . . ]
		sizeof(arSubGacha) / sizeof(arSubGacha[0]),
	};
