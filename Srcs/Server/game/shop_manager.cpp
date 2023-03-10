/// 1.
// Search
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen())

// Replace with
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen()
#if defined(__LUCKY_BOX__)
		|| pkChr->IsLuckyBoxOpen()
#endif
		)
