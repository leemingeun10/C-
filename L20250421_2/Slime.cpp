#include "Slime.h"
#include <iostream>

using namespace std;

ASlime::ASlime()
{
}

ASlime::~ASlime()
{
}

void ASlime::Tick()
{
	Move();
}

void ASlime::Move()
{
	cout << "¹Ì²ô·¯Áø´Ù." << endl;
}
