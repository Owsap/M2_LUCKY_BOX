""" 1. """
# Add to the bottom of the file
	if app.ENABLE_LUCKY_BOX:
		def ShowLuckyBoxWindow(self, dwItemVnum, byItemCount, iNeedMoney, wSlotIndex):
			if self.interface:
				self.interface.ShowLuckyBoxWindow(dwItemVnum, byItemCount, iNeedMoney, wSlotIndex)
