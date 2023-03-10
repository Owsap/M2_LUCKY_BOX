""" 1. """
# Add
if app.ENABLE_LUCKY_BOX:
	import uiLuckyBox

""" 2. """
# Search
		self.wndGuild = None

# Add below
		if app.ENABLE_LUCKY_BOX:
			self.wndLuckyBox = None

""" 3. """
# Search
		self.wndChatLog = wndChatLog

# Add below
		if app.ENABLE_LUCKY_BOX:
			self.wndLuckyBox = uiLuckyBox.LuckyBoxWindow()
			if app.WJ_ENABLE_TRADABLE_ICON:
				self.wndLuckyBox.BindInterface(self)
				self.wndLuckyBox.SetInven(self.wndInventory)

""" 4. """
# Search
		self.privateShopBuilder.SetItemToolTip(self.tooltipItem)

# Add below
		if app.ENABLE_LUCKY_BOX:
			self.wndLuckyBox.SetItemToolTip(self.tooltipItem)

""" 5. """
# Search
		if self.wndHelp:
			self.wndHelp.Destroy()

# Add below
			if self.wndLuckyBox:
				self.wndLuckyBox.Destroy()
				del self.wndLuckyBox

""" 6. """
# Search
	def EmptyFunction(self):
		pass

# Add below
	if app.ENABLE_LUCKY_BOX:
		def ShowLuckyBoxWindow(self, dwItemVnum, byItemCount, iNeedMoney):
			if self.wndLuckyBox:
				self.wndLuckyBox.ShowLuckyBoxWindow(dwItemVnum, byItemCount, iNeedMoney)

""" 7. """
# Search
	def MarkUnusableInvenSlotOnTopWnd(...

# Extend with
			if app.ENABLE_LUCKY_BOX:
				if onTopWnd == player.ON_TOP_WND_LUCKY_BOX and self.wndLuckyBox:
					return True

# Example
	def MarkUnusableInvenSlotOnTopWnd(...
		[ . . . ]

		if app.ENABLE_LUCKY_BOX:
			if onTopWnd == player.ON_TOP_WND_LUCKY_BOX and self.wndLuckyBox:
				return True

		return False
