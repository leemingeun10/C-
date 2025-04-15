#pragma once
class Monster
{
private:
	float Xpos, Ypos;
public:
	void Attack();
	void Move();

	float getXpos();
	float getYpos();
	float setXpos();
	float setYpos();
};

