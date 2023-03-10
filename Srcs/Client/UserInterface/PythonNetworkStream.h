/// 1.
// Search
		bool SendMallCheckoutPacket(BYTE byMallPos, TItemPos InventoryPos);

// Add below
#if defined(ENABLE_LUCKY_BOX)
	// Lucky Box
	bool SendLuckyBoxActionPacket(BYTE bAction);
	bool RecvLuckyBoxPacket();
#endif
