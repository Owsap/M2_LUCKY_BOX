/// 1.
// Search
			case HEADER_GC_SPECIFIC_EFFECT:
				ret = RecvSpecificEffect();
				break;

// Add below
#if defined(ENABLE_LUCKY_BOX)
			case HEADER_GC_LUCKY_BOX:
				ret = RecvLuckyBoxPacket();
				break;
#endif
