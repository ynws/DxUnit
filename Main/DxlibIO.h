#pragma once
#include "IOBase.h"

class DxlibIO : public IOBase
{
public:
	DxlibIO();
	~DxlibIO();
	eCursor GetCursorInput(int InputType);
	unsigned int GetColor(int Red, int Green, int Blue);
	int DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag = TRUE, int LineThickness = 1);
	int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness = 1);
};