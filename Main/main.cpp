#include "DxLib.h"
#include "PlayerView.h"
#include "DxlibIO.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(640, 480, 16);
	ChangeWindowMode(true);	// �E�B���h�E���[�h
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠉�ʂɃZ�b�g

	DxlibIO io;
	Player player(10, 10);
	PlayerView view(&io, &player);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		int key = io.GetCursorInput(DX_INPUT_KEY_PAD1);
		player.move(key);
		ClearDrawScreen();
		view.Draw();

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}