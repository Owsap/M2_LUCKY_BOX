/// 1.
// Search
	TMapDW2DW m_map_new_to_ori;

// Add below
#if defined(__LUCKY_BOX__)
public:
	bool ReadLuckyBoxFile(const char* c_pszFileName);
	CLuckyBoxGroup* GetLuckyBoxGroup();
private:
	CLuckyBoxGroup* m_pLuckyBox;
	std::map<DWORD, std::string> m_mapLuckyBoxMapper;
#endif
