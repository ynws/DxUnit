#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IOBase.h"

class MockIO : public IOBase {
public:
	MOCK_METHOD1(GetCursorInput, eCursor(int InputType));
	MOCK_METHOD3(GetColor, unsigned int(int Red, int Green, int Blue));
	MOCK_METHOD6(DrawCircle, int(int x, int y, int r, unsigned int Color, int FillFlag, int LineThickness));
	MOCK_METHOD6(DrawLine, int(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness));
};