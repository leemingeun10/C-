#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    vector<pair<int, int>> priorityque;

    int a = 0;
    for (auto members : priorities)
    {

      
        priorityque.push_back(members,a);
        a++;
    }
    
    return answer;
}