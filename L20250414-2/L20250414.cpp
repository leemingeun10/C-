/*
world
wall 
floor
player 
monster
destination

isexist
move
isOverlap
isend

class position
{
	
}
		



class player
{
	position ps;	
}
*/

//
//#include<iostream>
//using namespace std;
//
//
//class State
//{
//public:
//	int Id;
//	string name;
//};
//
//class Transition
//{
//public:
//	int CurrentState;
//	string Condition;
//	int NextState;
//};
//
//class MonsterFSM 
//{
//public:
//	Transition Transitions[5];
//	State States[4];
//	void Process(Monster _Monster)
//	{
//		for (int i = 0; i < 5; i++)
//		{
//			if (_Monster.state == Transitions[i].CurrentState &&  _Monster.Condition)
//		}
//
//	}
//};
//
//class Monster
//{
//public:
//	int state;
//	string Condition;
//};
//
//int main()
//{
//	State states[4];
//
//	states[0].Id = 1;
//	states[0].name = "배회";
//
//	states[0].Id = 2;
//	states[0].name = "추격";
//
//	states[0].Id = 3;
//	states[0].name = "공격";
//
//	states[0].Id = 4;
//	states[0].name = "죽음";
//
//	Transition Transitions[4];
//
//	MonsterFSM MyMonsterFSM[4];
//
//	MyMonsterFSM[0].Transitions.CurrentState = 1;
//	MyMonsterFSM[0].Transitions.Condition = "적발견";
//	MyMonsterFSM[0].Transitions.NextState = 2;
//
//	MyMonsterFSM[0].Transitions.CurrentState = 1;
//	MyMonsterFSM[0].Transitions.Condition = "적발견";
//	MyMonsterFSM[0].Transitions.NextState = 2;
//
//	MyMonsterFSM[0].Transitions.CurrentState = 1;
//	MyMonsterFSM[0].Transitions.Condition = "적발견";
//	MyMonsterFSM[0].Transitions.NextState = 2;
//
//	MyMonsterFSM[0].Transitions.CurrentState = 1;
//	MyMonsterFSM[0].Transitions.Condition = "적발견";
//	MyMonsterFSM[0].Transitions.NextState = 2;
//
//
//
//	//대충 이런식으로 초기화하면댐
//	return 0;
//}
//
//
//#include<iostream>
//using namespace std;
//#include"Wall.h"
//#include"Monster.h"
//#include"Goal.h"
//#include"UWorld.h"
//#include"Floor.h"
//#include "Player.h"
//
//
//int main()
//{
//	Player* Aplayer = new Player();
//	
//
//	delete Aplayer;
//	Aplayer = nullptr;
//
//	return 0;
//}
