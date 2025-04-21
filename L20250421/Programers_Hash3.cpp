#include <string>
#include <vector>
#include <map>
using namespace std;

// map �� ���� ���ҷ� �����ϱ� ���ؼ��� next�� ���

bool solution(vector<string> phone_book) {

    map<string, int> numbers;
    bool answer = true;

    for (auto number : phone_book)
    {
        numbers[number] = number.length();    
    }

    for (auto num = numbers.begin(); num != numbers.end();)
    {
     

        if (next(num) == numbers.end())
        {
            break;
        }
        if (next(num)->first.compare(0, num->first.size(), num->first) == 0)
        {
            answer = false;
            break;
        }
       
     
        num++;
    }




    
    return answer;
}