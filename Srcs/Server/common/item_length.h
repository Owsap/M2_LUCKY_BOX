/// 1.
// Search
enum EExtractSubTypes

// Add above
#if defined(__GACHA_SYSTEM__)
enum EGachaSubType
{
	USE_GACHA,
#if defined(__LUCKY_BOX__)
	GEM_LUCKY_BOX_GACHA,
	SPECIAL_LUCKY_BOX_GACHA,
#endif
};
#endif
