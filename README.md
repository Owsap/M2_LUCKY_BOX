### Lucky Box
Original author of the system is @blackdragonx61

The group file now contains a mapper that allows you add any box with it's relative group.
```txt
Group LuckyBoxMapper
{
	#--#	BoxVNum	GroupName
	1	72734	Blue
	2	72735	Red
	3	72737	Green
}

Group LuckyBox
{
	Price	60000
	Max_Try	15
	Group	Blue
	{
		#--#	Vnum	Count
		1	27004	20
		2	27005	50
		3	27006	70
	}
	Group	Red
	{
		#--#	Vnum	Count
		1	27001	20
		2	27002	50
		3	27003	70
	}
	Group	Green
	{
		#--#	Vnum	Count
		1	27100	20
		2	27101	50
		3	27102	70
	}
}
```
The implementation also includes the item type **Gacha** and also includes support for the slot marking in the inventory.