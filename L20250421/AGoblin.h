#pragma once
#include"AMonster.h"
// 소멸자에는 virtual을 꼭 넣어줘야함


class AGoblin : public AMonster
{
public:
	AGoblin();
	virtual ~AGoblin();
	virtual void move() override;

};
// 자식이 부모와 같은 함수를 사용할 때 그걸 virtual로 받아서 내 형식으로 사용할것이다 하면 똑같이 virtual 선언과 override를 써주어야한다.
