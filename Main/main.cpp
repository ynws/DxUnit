#include "DxLib.h"
#include "Player.h"

#ifndef _ROGEBREAZ_TEST
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(true);	// ウィンドウモード
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏画面にセット

	Player player(0, 0);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// キー入力取得
		int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		if (Key & PAD_INPUT_UP) player.move(0, -3);
		if (Key & PAD_INPUT_DOWN) player.move(0, 3);
		if (Key & PAD_INPUT_RIGHT) player.move(3, 0);
		if (Key & PAD_INPUT_LEFT) player.move(-3, 0);

		ClearDrawScreen();

		DrawCircle(player.getx(), player.gety(), 5, GetColor(255,255,255), TRUE);

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
#endif