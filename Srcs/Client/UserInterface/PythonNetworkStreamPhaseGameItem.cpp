/// 1.
// Add to the bottom of the file
#if defined(ENABLE_LUCKY_BOX)
bool CPythonNetworkStream::SendLuckyBoxActionPacket(BYTE bAction)
{
	TPacketCGLuckyBox Packet;
	Packet.bHeader = HEADER_CG_LUCKY_BOX;
	Packet.bAction = bAction;

	if (!Send(sizeof(Packet), &Packet))
		return false;

	return SendSequence();
}

bool CPythonNetworkStream::RecvLuckyBoxPacket()
{
	TPacketGCLuckyBox Packet;
	if (!Recv(sizeof(Packet), &Packet))
	{
		Tracen("RecvLuckyBox Packet Error");
		return false;
	}

	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "ShowLuckyBoxWindow", Py_BuildValue("(iiii)", Packet.dwVNum, Packet.bCount, Packet.iNeedMoney, Packet.wSlotIndex));
	return true;
}
#endif
