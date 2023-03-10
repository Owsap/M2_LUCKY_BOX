/// 1.
// Search
	enum EItemType

// Extend like
	enum EItemType
	{
		[ . . . ]
#if defined(ENABLE_GACHA)
		ITEM_TYPE_GACHA,
#endif
		ITEM_TYPE_MAX_NUM,
	};

/// 2.
// Search
	enum EExtractSubTypes
	{
		EXTRACT_DRAGON_SOUL,
		EXTRACT_DRAGON_HEART,
	};

// Add below
#if defined(ENABLE_GACHA)
	enum EGachaSubType
	{
		USE_GACHA,
#if defined(ENABLE_LUCKY_BOX)
		GEM_LUCKY_BOX_GACHA,
		SPECIAL_LUCKY_BOX_GACHA,
#endif
	};
#endif
