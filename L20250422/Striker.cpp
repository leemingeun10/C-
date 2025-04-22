#include "Striker.h"
#include<iostream>
using namespace std;
Striker::Striker()
{
	SetPlayerSkill(1, "뇌호격");
	cout << "스트라이커 생성 HP: " << GetPlayerStat().HP << " MP:" << GetPlayerStat().Mp << endl;
}

Striker::~Striker()
{
}

void Striker::Attack()
{
	cout << "스트라이커 " << GetPlayerSkill(1) << "공격"<<endl;
}
