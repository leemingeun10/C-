#include "Monster.h"
#include <iostream>

using namespace std;

//생성자
AMonster::AMonster()
{
	//cout << "몬스터 생성" << endl;
}

//소멸자
AMonster::~AMonster()
{
	//cout << "몬스터 삭제" << endl;
}

void AMonster::Tick()
{
}

void AMonster::Move()
{
	cout << "이동한다" << endl;
}
