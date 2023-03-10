/// 1.
// Search
			Set(HEADER_GC_DRAGON_SOUL_REFINE, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));

// Add below
#if defined(ENABLE_LUCKY_BOX)
			Set(HEADER_GC_LUCKY_BOX, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCLuckyBox), STATIC_SIZE_PACKET));
#endif
