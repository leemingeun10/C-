#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int Compareint = -1;


    for (auto arrint : arr)
    {
       
        if(Compareint != arrint)
        {
            Compareint = arrint;
            answer.push_back(arrint);
        }
    }




    return answer;
}