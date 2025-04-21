#include <string>
#include <vector>
#include <map>
using namespace std;

// map 은 다음 원소로 접근하기 위해서는 next를 사용

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