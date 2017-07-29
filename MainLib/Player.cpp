#include "Player.h"

Player::Player(int x, int y) {
	x_ = x;
	y_ = y;
}

void Player::move(int x, int y) {
	x_ += x;
	y_ += y;
}

int Player::getx() { return x_; }
int Player::gety() { return y_; }
