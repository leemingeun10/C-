
#include <string>
#include <vector>
#include <map>

// 코니의 옷입히기 ! 근데 hash 와 해결능력을 곁들인
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