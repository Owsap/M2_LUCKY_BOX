/// 1.
// Search
enum ETopWindowTypes

// Extend with
enum ETopWindowTypes
{
	[ . . . ]
#if defined(ENABLE_LUCKY_BOX)
	ON_TOP_WND_LUCKY_BOX,
#endif
	ON_TOP_WND_MAX,
};
