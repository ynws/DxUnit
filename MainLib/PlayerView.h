#pragma once
#include "Player.h"
#include "IOBase.h"
class PlayerView
{
private:
	IOBase *io_;
	Player *player_;
public:
	PlayerView(IOBase *io, Player * player);
	~PlayerView();
	void Draw();
};

