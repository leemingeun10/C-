#include "Monster.h"
#include <iostream>

using namespace std;

//������
AMonster::AMonster()
{
	//cout << "���� ����" << endl;
}

//�Ҹ���
AMonster::~AMonster()
{
	//cout << "���� ����" << endl;
}

void AMonster::Tick()
{
	Move();
}

void AMonster::Move()
{
	cout << "�̵��Ѵ�" << endl;
}
