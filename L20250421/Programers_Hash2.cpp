#include <vector>
#include<map>
using namespace std;

// 첫번째 시도 int int map 사용
int solution(vector<int> nums)
{
    map<int ,int > poketmons;

    for (auto num : nums)
    {
        poketmons[num]++;
    }

    int answer = 0;

    if (poketmons.size() > (nums.size() / 2))
    {
        answer = nums.size() / 2 ;
    }
    else
    {
        answer = poketmons.size();
    }



    return answer;
}