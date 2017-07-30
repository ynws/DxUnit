#include "PlayerView.h"

PlayerView::PlayerView(IOBase *io, Player * player)
{
	io_ = io;
	player_ = player;
}

PlayerView::~PlayerView()
{
}

void PlayerView::Draw()
{
	io_->DrawCircle(player_->getx() * 3, player_->gety() * 3, 10, io_->GetColor(255, 255, 255));
}
