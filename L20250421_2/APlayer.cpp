#include "APlayer.h"
#include <iostream>
using namespace std;


APlayer::APlayer()
{
	SetActorForm('P');
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
