/// 1.
// Search
	Set(HEADER_CG_MESSENGER, sizeof(TPacketCGMessenger), "Messenger", true);

// Add below
#if defined(__LUCKY_BOX__)
	Set(HEADER_CG_LUCKY_BOX, sizeof(TPacketCGLuckyBox), "LuckyBox", true);
#endif
