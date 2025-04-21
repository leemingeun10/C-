#include <string>
#include <vector>
#include <map>
using namespace std;

// 해쉬는 데이터를 바르게 찾기 위해서 숫자로 바꾸는것
// 해쉬테이블을 만드는게 목표
// 1차시도 패배
//string solution(vector<string> participant, vector<string> completion) {
//
//    
//
//    for (auto name_start = participant.begin() ; name_start != participant.end() ;) // iterater 사용
//    {
//        bool found = false;
//        for (auto name_end : completion)
//        {
//            if (*name_start == name_end)
//            {
//                found = true;
//                participant.erase(name_start);
//                break;
//            }
//        }
//
//        if (!found)
//        {
//            name_start++;
//        }
//
//    }
//
//    
//
//    string answer = participant.front();
//
//
//    return answer;
//}

// include map 과 unordered map 둘의 차이점 을 이해한다 // 해쉬를 위해서 stl map을 사용해본다 
// 2차시도 성공
string solution(vector<string> participant, vector<string> completion) {
    map<string, int> members;

    for (auto name : participant)
    {
        members[name]++;
    }
    for (auto name : completion)
    {
        members[name]--;
    }

    string answer;
    
    for (auto member : members)
    {
        if (member.second == 1)
        {
             answer = member.first;
        }
    }


    return answer;
}