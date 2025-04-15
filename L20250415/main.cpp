#include"Monster.h"
#include"Player.h"
#include<iostream>
#include"UWorld.h"
#include<time.h>;
/* 배열안에 있는 모든걸 다꺼내주세요
for (auto data : IntArray)
{
		cout <<data<<endl;
}
전체순회

vector.erase 가능

vector<> a ;
a.erase(find(a.begin(),a.end(),3)); 3이 존재하는 곳의 iterater를 반환해서 사용가능 3을 찾아서 지워줌
*/
//container verctor 
//erease 삭제 
//순회 for ranged for
//탐색 find



int main()
{
	srand(static_cast<unsigned int>(time(0)));
	UWorld NewWorld;
	NewWorld.Initialize();

	cout << "현재 Player의 수 :" << NewWorld.Players.size() << endl;
	cout << "현재 Slime의 수 :" << NewWorld.Slimes.size() << endl;
	cout << "현재 Boar의 수 :" << NewWorld.Boars.size() << endl;
	cout << "현재 Goblin의 수 :" << NewWorld.Goblins.size() << endl;


	return 0;
}