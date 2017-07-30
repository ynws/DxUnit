#include "DxLib.h"
#include "DxlibIO.h"

DxlibIO::DxlibIO()
{
}

DxlibIO::~DxlibIO()
{
}

eCursor DxlibIO::GetCursorInput(int InputType)
{
	// TODO: “¯Žž‰Ÿ‚µ‘Î‰ž
	int key = DxLib::GetJoypadInputState(InputType);
	if (key & PAD_INPUT_UP) return eCursor::UP;
	if (key & PAD_INPUT_DOWN) return eCursor::DOWN;
	if (key & PAD_INPUT_RIGHT) return eCursor::RIGHT;
	if (key & PAD_INPUT_LEFT) return eCursor::LEFT;
	return eCursor::NONE;
}

unsigned int DxlibIO::GetColor(int Red, int Green, int Blue)
{
	return DxLib::GetColor(Red, Green, Blue);
}

int DxlibIO::DrawCircle(int x, int y, int r, unsigned int Color, int FillFlag, int LineThickness)
{
	return DxLib::DrawCircle(x, y, r, Color, FillFlag, LineThickness);
}

int DxlibIO::DrawLine(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness)
{
	return DxLib::DrawLine(x1, y1, x2, y2, Color, Thickness);
}
