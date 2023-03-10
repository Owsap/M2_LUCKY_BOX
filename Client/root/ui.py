""" 1. """
# Add @ class Button (If you don't have)
	def IsDown(self):
		return wndMgr.IsDown(self.hWnd)

# Add below
	if app.ENABLE_LUCKY_BOX:
		def SetButtonScale(self, xScale, yScale):
			wndMgr.SetButtonScale(self.hWnd, xScale, yScale)

""" 2. """
# Add @ class TitleBar (If you don't have)
	if app.ENABLE_LUCKY_BOX:
		def CloseButtonHide(self):
			if localeInfo.IsARABIC():
				self.imgLeft.LoadImage("d:/ymir work/ui/pattern/titlebar_right_02.tga")
				self.imgLeft.LeftRightReverse()
				self.btnClose.Hide()
			else:
				self.imgRight.LoadImage("d:/ymir work/ui/pattern/titlebar_right_02.tga")
				self.btnClose.Hide()
