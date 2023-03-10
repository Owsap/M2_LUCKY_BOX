/// 1.
// Search
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

// Replace with
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__LUCKY_BOX__)
						|| ch->IsLuckyBoxOpen()
#endif
						)

/// 2.
// Search
int CInputDead::Analyze

// Add above
#if defined(__LUCKY_BOX__)
void CInputMain::LuckyBox(LPCHARACTER ch, const char* c_pData)
{
	const TPacketCGLuckyBox* c_pPacket = reinterpret_cast<const TPacketCGLuckyBox*>(c_pData);

	switch (c_pPacket->bAction)
	{
		case ELUCKY_BOX_ACTION::LUCKY_BOX_ACTION_RETRY:
			ch->LuckyBoxRetry();
			break;
		case ELUCKY_BOX_ACTION::LUCKY_BOX_ACTION_RECEIVE:
			ch->LuckyBoxReceive();
			break;
		default:
			sys_err("CInputMain::LuckyBox : Unknown action %d : %s", c_pPacket->bAction, ch->GetName());
			return;
	}
}
#endif

/// 3.
// Search
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

// Replace with
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__LUCKY_BOX__)
		|| ch->IsLuckyBoxOpen()
#endif
		)

/// 4.
// Search
		case HEADER_CG_WARP:
			Warp(ch, c_pData);
			break;

// Add below
#if defined(__LUCKY_BOX__)
		case HEADER_CG_LUCKY_BOX:
			LuckyBox(ch, c_pData);
			break;
#endif
