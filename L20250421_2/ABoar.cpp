#include "ABoar.h"
#include<iostream>
using namespace std;
ABoar::ABoar()
{
	SetActorForm('B');
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
	cout << "����" << endl;
}
