#include"Monster.h"
#include"Player.h"
#include<iostream>
#include"UWorld.h"
#include<time.h>;
/* �迭�ȿ� �ִ� ���� �ٲ����ּ���
for (auto data : IntArray)
{
		cout <<data<<endl;
}
��ü��ȸ

vector.erase ����

vector<> a ;
a.erase(find(a.begin(),a.end(),3)); 3�� �����ϴ� ���� iterater�� ��ȯ�ؼ� ��밡�� 3�� ã�Ƽ� ������
*/
//container verctor 
//erease ���� 
//��ȸ for ranged for
//Ž�� find



int main()
{
	srand(static_cast<unsigned int>(time(0)));
	UWorld NewWorld;
	NewWorld.Initialize();

	cout << "���� Player�� �� :" << NewWorld.Players.size() << endl;
	cout << "���� Slime�� �� :" << NewWorld.Slimes.size() << endl;
	cout << "���� Boar�� �� :" << NewWorld.Boars.size() << endl;
	cout << "���� Goblin�� �� :" << NewWorld.Goblins.size() << endl;


	return 0;
}