#include "APlayer.h"
#include <iostream>
using namespace std;


APlayer::APlayer()
{
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	Move();
}

void APlayer::Move()
{
	cout << "�̵��Ѵ�" << endl;
}
