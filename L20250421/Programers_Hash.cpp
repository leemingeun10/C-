#include <string>
#include <vector>
#include <map>
using namespace std;

// �ؽ��� �����͸� �ٸ��� ã�� ���ؼ� ���ڷ� �ٲٴ°�
// �ؽ����̺��� ����°� ��ǥ
// 1���õ� �й�
//string solution(vector<string> participant, vector<string> completion) {
//
//    
//
//    for (auto name_start = participant.begin() ; name_start != participant.end() ;) // iterater ���
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

// include map �� unordered map ���� ������ �� �����Ѵ� // �ؽ��� ���ؼ� stl map�� ����غ��� 
// 2���õ� ����
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