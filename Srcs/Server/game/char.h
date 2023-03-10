/// 1.
// Add
#if defined(__LUCKY_BOX__)
#	include "item_manager.h"
#endif

/// 2.
// Search
};

ESex GET_SEX(LPCHARACTER ch);

// Add above
#if defined(__LUCKY_BOX__)
public:
	void SetLuckyBoxSrcItem(LPITEM lpItem);
	void SendLuckyBoxInfo();
	void LuckyBoxRetry();
	void LuckyBoxReceive();
	int GetLuckyBoxPrice() const;
	bool IsLuckyBoxOpen() const;
	void ResetLuckyBoxData();

private:
	struct
	{
		DWORD dwSrcItemVNum;
		DWORD dwSrcItemID;
		WORD wSrcSlotIndex;
		BYTE bTryCount;
		DWORD dwItemVNum;
		BYTE bItemCount;
	} m_sLuckyBox;
#endif
