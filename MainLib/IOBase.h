#pragma once
#include "IOStatus.h"

class IOBase
{
public:
	virtual ~IOBase() {};
	virtual eCursor GetCursorInput(int InputType) = 0;
	virtual unsigned int GetColor(int Red, int Green, int Blue) = 0;
	virtual int DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag = TRUE, int LineThickness = 1) = 0;
	virtual int DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness) = 0;
};