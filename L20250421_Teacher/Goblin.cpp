#include "Goblin.h"
#include <iostream>

using namespace std;

AGoblin::AGoblin()
{
	//cout << "고블린 생성" << endl;
}

AGoblin::~AGoblin()
{
	//cout << "고블린 삭제" << endl;
}

void AGoblin::Tick()
{
	Move(); 
}

void AGoblin::Move()
{
	cout << "뛴다." << endl;
}
