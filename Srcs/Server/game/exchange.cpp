/// 1.
// Search
	if (IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen())

// Replace with
	if (IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen()
#if defined(__LUCKY_BOX__)
		|| IsLuckyBoxOpen()
#endif
		)

/// 2.
// Search
	if (victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen())

// Replace with
	if (victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen()
#if defined(__LUCKY_BOX__)
		|| victim->IsLuckyBoxOpen()
#endif
		)
