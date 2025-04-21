#include "Boar.h"
#include <iostream>

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
	std::cout << "¸äµÅÁö ÁúÁÖ" << std::endl;
}
