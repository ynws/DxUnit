#pragma once

class Player
{
private:
	int x_, y_;
public:
	Player(int x, int y) { x_ = x; y_ = y; }
	void move(int x, int y) { x_ += x; y_ += y; }
	int getx() { return x_; }
	int gety() { return y_; }
};