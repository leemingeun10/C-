#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> QP;

    for (int i = 0; i < priorities.size(); i++)
    {
        QP.push({ priorities[i],i });
    }

    while (!QP.empty())
    {


    }
   


   

    return answer;
}