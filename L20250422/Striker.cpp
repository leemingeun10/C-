#include "Striker.h"
#include<iostream>
using namespace std;
Striker::Striker()
{
	SetPlayerSkill(1, "��ȣ��");
	cout << "��Ʈ����Ŀ ���� HP: " << GetPlayerStat().HP << " MP:" << GetPlayerStat().Mp << endl;
}

Striker::~Striker()
{
}

void Striker::Attack()
{
	cout << "��Ʈ����Ŀ " << GetPlayerSkill(1) << "����"<<endl;
}
