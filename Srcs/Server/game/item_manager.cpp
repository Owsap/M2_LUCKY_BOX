/// 1.
// Search
	if (id == 0) // 새로 만드는 아이템일 때만 처리

// Add above
#if defined(__GACHA_SYSTEM__)
	if (item->GetType() == ITEM_GACHA)
		item->SetSocket(0, item->GetLimitValue(1));
#endif

/// 2.
// Search
	m_ItemIDSpareRange.dwMin = m_ItemIDSpareRange.dwMax = m_ItemIDSpareRange.dwUsableItemIDMin = 0;

// Add below
#if defined(__LUCKY_BOX__)
	m_pLuckyBox = nullptr;
#endif

/// 3.
// Search
	m_VIDMap.clear();

// Add below
#if defined(__LUCKY_BOX__)
	if (m_pLuckyBox)
	{
		delete m_pLuckyBox;
		m_pLuckyBox = nullptr;
	}
#endif

/// 4.
// Add to the bottom of the file

#if defined(__LUCKY_BOX__)
CLuckyBoxGroup::CLuckyBoxGroup(int iPrice, BYTE bMaxTryCount) :
	m_iPrice(iPrice),
	m_bMaxTryCount(bMaxTryCount)
{}

int CLuckyBoxGroup::GetPrice() const
{
	return m_iPrice;
}

BYTE CLuckyBoxGroup::GetMaxTryCount() const
{
	return m_bMaxTryCount;
}

void CLuckyBoxGroup::AddItem(DWORD dwBoxVNum, DWORD dwVNum, BYTE bCount)
{
	m_ItemsVec[dwBoxVNum].push_back({ dwVNum, bCount });
}

bool CLuckyBoxGroup::ContainsItems(DWORD dwBoxVNum) const
{
	auto it = m_ItemsVec.find(dwBoxVNum);
	if (it != m_ItemsVec.end() && !it->second.empty())
		return true;
	return false;
}

const CLuckyBoxGroup::SLuckyBoxItemInfo& CLuckyBoxGroup::GetRandomItem(DWORD dwBoxVNum) const
{
	const std::size_t nIndex = number(0, GetItemCount(dwBoxVNum) - 1);
	return m_ItemsVec.at(dwBoxVNum).at(nIndex);
}

std::size_t CLuckyBoxGroup::GetItemCount(DWORD dwBoxVNum) const
{
	return (ContainsItems(dwBoxVNum) ? m_ItemsVec.at(dwBoxVNum).size() : 0);
}
#endif
