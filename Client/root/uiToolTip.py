""" 1. """
# Search
		if self.itemVnum in [79505, 79506]:
			if 0 != metinSlot[0]:
				self.AppendMallItemLastTime(metinSlot[0])

# Add below
		if app.ENABLE_GACHA:
			if 0 != metinSlot and item.ITEM_TYPE_GACHA == itemType and itemSubType == item.USE_GACHA:
				useCount = int(metinSlot[0])

				self.AppendSpace(5)
				self.AppendTextLine(localeInfo.TOOLTIP_REST_USABLE_COUNT % useCount, grp.GenerateColor(0.6705, 0.9490, 0.0, 1.0))
