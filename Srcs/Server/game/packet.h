/// 1.
// Search
	HEADER_CG_STATE_CHECKER = 206,

// Add below
#if defined(__LUCKY_BOX__)
	HEADER_CG_LUCKY_BOX = 208,
#endif

/// 2.
// Search
	HEADER_GC_RESPOND_CHANNELSTATUS = 210,

// Add below
#if defined(__LUCKY_BOX__)
	HEADER_GC_LUCKY_BOX = 217,
#endif

/// 3.
// Add to the bottom of the file above #pragma pack()
#if defined(__LUCKY_BOX__)
enum ELUCKY_BOX_ACTION
{
	LUCKY_BOX_ACTION_RETRY,
	LUCKY_BOX_ACTION_RECEIVE,
};

typedef struct SPacketCGLuckyBox
{
	BYTE bHeader;
	BYTE bAction;
} TPacketCGLuckyBox;

typedef struct SPacketGCLuckyBox
{
	BYTE bHeader;
	DWORD dwVNum;
	BYTE bCount;
	int iNeedMoney;
	WORD wSlotIndex;
} TPacketGCLuckyBox;
#endif
