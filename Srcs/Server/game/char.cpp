/// 1.
// Search @ void CHARACTER::Initialize
	m_pGuild = NULL;

/// Add below
#if defined(__LUCKY_BOX__)
	ResetLuckyBoxData();
#endif

/// 2.
// Search
	marriage::CManager::instance().Logout(this);

/// Add below
#if defined(__LUCKY_BOX__)
	LuckyBoxReceive();
#endif

/// 3.
// Search
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen())

// Change with
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen()
#if defined(__LUCKY_BOX__)
						|| IsLuckyBoxOpen()
#endif
						)

/// 4.
// Replace
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen())

// Replace with
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen()
#if defined(__LUCKY_BOX__)
					|| pkChrCauser->IsLuckyBoxOpen()
#endif
						)

/// 5.
// Search
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen()))

// Replace with
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen())
#if defined(__LUCKY_BOX__)
					|| IsLuckyBoxOpen()
#endif
						)

/// 6.
// Search
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

// Replace with
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__LUCKY_BOX__)
			|| IsLuckyBoxOpen()
#endif
			)

/// 7.
// Search
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())

// Replace with
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
#if defined(__LUCKY_BOX__)
			|| IsLuckyBoxOpen()
#endif
		)

/// 8.
// Search
	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

// Replace with
	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__LUCKY_BOX__)
		|| IsLuckyBoxOpen()
#endif
		)
