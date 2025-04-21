#include "ABoar.h"
#include<iostream>
using namespace std;
ABoar::ABoar()
{
}

ABoar::~ABoar()
{
}

void ABoar::Tick()
{
	Move();
}

void ABoar::Move()
{
	cout << "기어간다" << endl;
}
