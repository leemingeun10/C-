#pragma once
#include"AMonster.h"
// �Ҹ��ڿ��� virtual�� �� �־������


class AGoblin : public AMonster
{
public:
	AGoblin();
	virtual ~AGoblin();
	virtual void move() override;

};
// �ڽ��� �θ�� ���� �Լ��� ����� �� �װ� virtual�� �޾Ƽ� �� �������� ����Ұ��̴� �ϸ� �Ȱ��� virtual ����� override�� ���־���Ѵ�.
