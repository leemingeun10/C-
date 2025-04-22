
#include <string>
#include <vector>
#include <map>

// �ڴ��� �������� ! �ٵ� hash �� �ذ�ɷ��� �����
using namespace std;

int solution(vector<vector<string>> clothes) {

    map<string, int > CountClothes;

    for (auto cloth : clothes)
    {
        CountClothes[cloth[1]]++;
    }

    int answer = 1;

    int index = 0;
    
    for (auto Kindofcloth : CountClothes)
    {
        answer *= (Kindofcloth.second + 1);
    }

    answer -= 1;
    

    
     

    return answer;
}