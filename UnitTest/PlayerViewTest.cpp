#include "MockIO.h"
#include "PlayerView.h"

TEST(PlayerView, Draw) {
	MockIO mock;
	Player p(1, 3);
	PlayerView view(&mock, &p);

	EXPECT_CALL(mock, GetColor(255, 255, 255)).Times(1);
	EXPECT_CALL(mock, DrawCircle(3, 9, 10, 0, TRUE, 1)).Times(1);
	view.Draw();
}
