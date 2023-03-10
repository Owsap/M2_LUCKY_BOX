/// 1.
// Add to the bottom of the file
#if defined(__LUCKY_BOX__)
bool ITEM_MANAGER::ReadLuckyBoxFile(const char* c_pszFileName)
{
	if (m_pLuckyBox)
	{
		delete m_pLuckyBox;
		m_pLuckyBox = nullptr;
	}

	CTextFileLoader TextFileLoader;
	if (!TextFileLoader.Load(c_pszFileName))
		return false;

	// Group Lucky Box Mapper
	{
		if (!TextFileLoader.SetChildNode("luckyboxmapper"))
		{
			sys_err("ReadLuckyBoxFile : Syntax error %s : no LuckyBoxMapper node", c_pszFileName);
			return false;
		}

		TTokenVector* pToken;
		for (int i = 1; i < 256; ++i)
		{
			if (!TextFileLoader.GetTokenVector(std::to_string(i), &pToken))
				break;

			const std::string& strVnum = pToken->at(0);

			DWORD dwVNum = 0;
			str_to_number(dwVNum, strVnum.c_str());

			if (!ITEM_MANAGER::instance().GetTable(dwVNum))
			{
				sys_err("ReadLuckyBoxFile : there is no item %s, node: LuckyBoxMapper", strVnum.c_str());
				return false;
			}

			std::string& strGroupName = pToken->at(1);
			std::transform(strGroupName.begin(), strGroupName.end(), strGroupName.begin(), ::tolower);

			m_mapLuckyBoxMapper.insert(std::make_pair(dwVNum, strGroupName));
		}

		if (m_mapLuckyBoxMapper.empty())
		{
			sys_err("ReadLuckyBoxFile : Empty LuckyBoxMapper");
			TextFileLoader.SetParentNode();
			return false;
		}

		TextFileLoader.SetParentNode();
	}

	// Group Lucky Box
	{
		if (!TextFileLoader.SetChildNode("luckybox"))
		{
			sys_err("ReadLuckyBoxFile : Syntax error %s : no LuckyBox node", c_pszFileName);
			return false;
		}

		int iPrice;
		if (!TextFileLoader.GetTokenInteger("price", &iPrice))
		{
			sys_err("ReadLuckyBoxFile : Syntax error %s : no Price", c_pszFileName);
			TextFileLoader.SetParentNode();
			return false;
		}

		BYTE bMaxTryCount;
		if (!TextFileLoader.GetTokenByte("max_try", &bMaxTryCount))
		{
			sys_err("ReadLuckyBoxFile : Syntax error %s : no Max_Try", c_pszFileName);
			TextFileLoader.SetParentNode();
			return false;
		}

		TTokenVector* pToken;
		m_pLuckyBox = new CLuckyBoxGroup(iPrice, bMaxTryCount);

		for (const auto& it : m_mapLuckyBoxMapper)
		{
			const DWORD& c_dwBoxVNum = it.first;
			const std::string& strBoxName = it.second;

			if (!TextFileLoader.SetChildNode(strBoxName.c_str()))
			{
				sys_err("ReadLuckyBoxFile : Syntax error %s : no %s node in group LuckyBox.", c_pszFileName, strBoxName.c_str());
				return false;
			}

			for (int k = 1; k < 256; ++k)
			{
				if (!TextFileLoader.GetTokenVector(std::to_string(k), &pToken))
					break;

				if (pToken->size() < 2)
					continue;

				const std::string& strVnum = pToken->at(0);

				DWORD dwVNum = 0;
				str_to_number(dwVNum, strVnum.c_str());

				if (!ITEM_MANAGER::instance().GetTable(dwVNum))
				{
					sys_err("ReadLuckyBoxFile : there is no item %s, node: %s", strVnum.c_str(), strBoxName.c_str());
					return false;
				}

				BYTE bCount = 0;
				str_to_number(bCount, pToken->at(1).c_str());

				m_pLuckyBox->AddItem(c_dwBoxVNum, dwVNum, bCount);
			}

			if (m_pLuckyBox->GetItemCount(c_dwBoxVNum) == 0)
			{
				sys_err("ReadLuckyBoxFile : there is no item, node: %s", strBoxName.c_str());
				return false;
			}

			TextFileLoader.SetParentNode();
		}


		TextFileLoader.SetParentNode();
	}
	return true;
}

CLuckyBoxGroup* ITEM_MANAGER::GetLuckyBoxGroup()
{
	return m_pLuckyBox;
}
#endif
