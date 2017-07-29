#include <gtest/gtest.h>
#include "Player.h"

TEST(Player, init) {
	Player p(1, 3);
	EXPECT_EQ(p.getx(), 1);
	EXPECT_EQ(p.gety(), 3);
}

TEST(Player, move) {
	Player p(1, 3);
	p.move(10, -5);
	EXPECT_EQ(p.getx(), 11);
	EXPECT_EQ(p.gety(), -2);
}