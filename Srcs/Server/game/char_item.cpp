/// 1.
// Search
	if (IsCubeOpen() || NULL != DragonSoul_RefineWindow_GetOpener())
		return false;

// Add below
#if defined(__LUCKY_BOX__)
	if (IsLuckyBoxOpen())
		return false;
#endif

/// 2.
// Search
		case ITEM_EXTRACT:
		{
			[ . . . ]
		}
		break;

// Add below
#if defined(__GACHA_SYSTEM__)
		case ITEM_GACHA:
		{
			switch (item->GetSubType())
			{
				case USE_GACHA:
				{
					/*
					DWORD dwBoxVNum = item->GetVnum();
					std::vector<DWORD> vVNum;
					std::vector<DWORD> vCount;
					std::vector<LPITEM> vItems(0);
					int iCount = 0;
					if (GiveItemFromSpecialItemGroup(dwBoxVnum, vVNum, vCount, vItems, iCount))
					*/
					if (GiveItemFromSpecialItemGroup(item->GetVnum()))
					{
						if (item->GetSocket(0) > 1)
							item->SetSocket(0, item->GetSocket(0) - 1);
						else
							ITEM_MANAGER::instance().RemoveItem(item, "REMOVE (ITEM_GACHA)");
					}
				}
				break;

#if defined(__LUCKY_BOX__)
				case GEM_LUCKY_BOX_GACHA:
				case SPECIAL_LUCKY_BOX_GACHA:
					SetLuckyBoxSrcItem(item);
					break;
#endif
			}
		}
		break;
#endif

/// 3.
// Search
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

// Replace with
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__LUCKY_BOX__)
			|| IsLuckyBoxOpen()
#endif
			)

/// 4.
// Search
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

// Replace with
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__LUCKY_BOX__)
			|| IsLuckyBoxOpen()
#endif
			)

/// 5.
// Add to the bottom of the file
#if defined(__LUCKY_BOX__)
void CHARACTER::SetLuckyBoxSrcItem(const LPITEM c_lpItem)
{
	if (c_lpItem == nullptr)
		return;

	if (PreventTradeWindow(WND_ALL))
	{
		ChatPacket(CHAT_TYPE_INFO, LC_STRING("You have to close other windows."));
		return;
	}

	ResetLuckyBoxData();

	m_sLuckyBox.dwSrcItemVNum = c_lpItem->GetVnum();
	m_sLuckyBox.dwSrcItemID = c_lpItem->GetID();
	m_sLuckyBox.wSrcSlotIndex = c_lpItem->GetCell();

	SendLuckyBoxInfo();
}

void CHARACTER::SendLuckyBoxInfo()
{
	if (!IsLuckyBoxOpen())
		return;

	if (!GetDesc())
		return;

	CLuckyBoxGroup* pLuckyBox = ITEM_MANAGER::Instance().GetLuckyBoxGroup();
	if (!pLuckyBox)
		return;

	if (!pLuckyBox->ContainsItems(m_sLuckyBox.dwSrcItemVNum))
		return;

	m_sLuckyBox.bTryCount++;

	while (true)
	{
		const CLuckyBoxGroup::SLuckyBoxItemInfo& item = pLuckyBox->GetRandomItem(m_sLuckyBox.dwSrcItemVNum);
		if (pLuckyBox->GetItemCount(m_sLuckyBox.dwSrcItemVNum) > 1 && item.dwVNum == m_sLuckyBox.dwItemVNum)
			continue;

		m_sLuckyBox.dwItemVNum = item.dwVNum;
		m_sLuckyBox.bItemCount = item.bCount;
		break;
	}

	TPacketGCLuckyBox Packet;
	Packet.bHeader = HEADER_GC_LUCKY_BOX;
	Packet.dwVNum = m_sLuckyBox.dwItemVNum;
	Packet.bCount = m_sLuckyBox.bItemCount;
	Packet.iNeedMoney = GetLuckyBoxPrice();
	Packet.wSlotIndex = m_sLuckyBox.wSrcSlotIndex;
	GetDesc()->Packet(&Packet, sizeof(Packet));
}

void CHARACTER::LuckyBoxRetry()
{
	if (!IsLuckyBoxOpen())
		return;

	CLuckyBoxGroup* pLuckyBox = ITEM_MANAGER::Instance().GetLuckyBoxGroup();
	if (!pLuckyBox)
		return;

	if (m_sLuckyBox.bTryCount >= pLuckyBox->GetMaxTryCount())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_STRING("You can't do this anymore."));
		return;
	}

	const int c_iPrice = GetLuckyBoxPrice();
	if (c_iPrice > GetGold())
	{
		ChatPacket(CHAT_TYPE_INFO, LC_STRING("You don't have enough money."));
		return;
	}

	PointChange(POINT_GOLD, -c_iPrice);
	ChatPacket(CHAT_TYPE_INFO, LC_STRING("%d Yang has been deducted.", c_iPrice));
	SendLuckyBoxInfo();
}

void CHARACTER::LuckyBoxReceive()
{
	if (!IsLuckyBoxOpen())
		return;

	const LPITEM c_lpSrcItem = ITEM_MANAGER::Instance().Find(m_sLuckyBox.dwSrcItemID);
	if (c_lpSrcItem)
	{
		ITEM_MANAGER::Instance().RemoveItem(c_lpSrcItem);
		AutoGiveItem(m_sLuckyBox.dwItemVNum, m_sLuckyBox.bItemCount);
	}

	ResetLuckyBoxData();
}

int CHARACTER::GetLuckyBoxPrice() const
{
	CLuckyBoxGroup* pLuckyBox = ITEM_MANAGER::Instance().GetLuckyBoxGroup();
	if (!pLuckyBox)
		return 0;

	int iRet = pLuckyBox->GetPrice();
	for (int i = 1; i < m_sLuckyBox.bTryCount; i++)
		iRet *= 2;

	return iRet;
}

bool CHARACTER::IsLuckyBoxOpen() const
{
	return m_sLuckyBox.dwSrcItemID != 0;
}

void CHARACTER::ResetLuckyBoxData()
{
	memset(&m_sLuckyBox, 0, sizeof(m_sLuckyBox));
}
#endif
