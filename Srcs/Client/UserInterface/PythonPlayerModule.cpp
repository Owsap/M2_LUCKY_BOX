/// 1.
// Search
void initPlayer()

// Add above
#if defined(ENABLE_LUCKY_BOX)
PyObject* playerSendLuckyBoxAction(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bAction;
	if (!PyTuple_GetByte(poArgs, 0, &bAction))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendLuckyBoxActionPacket(bAction);
	return Py_BuildNone();
}
#endif

/// 2.
// Search
		{ NULL, NULL, NULL },

// Add above
#if defined(ENABLE_LUCKY_BOX)
		// Lucky Box
		{ "SendLuckyBoxAction", playerSendLuckyBoxAction, METH_VARARGS },
#endif

/// 3.
// Add to the bottom of the file above }
#if defined(ENABLE_LUCKY_BOX)
	PyModule_AddIntConstant(poModule, "ON_TOP_WND_LUCKY_BOX", ON_TOP_WND_LUCKY_BOX);

	PyModule_AddIntConstant(poModule, "LUCKY_BOX_ACTION_RETRY", ELUCKY_BOX_ACTION::LUCKY_BOX_ACTION_RETRY);
	PyModule_AddIntConstant(poModule, "LUCKY_BOX_ACTION_RECEIVE", ELUCKY_BOX_ACTION::LUCKY_BOX_ACTION_RECEIVE);
#endif
