#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
    
    vector<int> reverseprogresses;

    reverse(progresses.begin(), progresses.end());
    reverse(speeds.begin(), speeds.end());



    while (!progresses.empty())
    {
        int progresscount = 0;

        for (int i = 0; i < progresses.size(); i++)
        {
            if (progresses[i] + speeds[i] < 100)
            {
                progresses[i] = progresses[i] + speeds[i];
            }
            else
            {
                progresses[i] = 100;
            }

        }

        while (!progresses.empty() && progresses.back() == 100)
        {
            progresses.pop_back();
            speeds.pop_back();
            progresscount++;
        }

        if (progresscount != 0)
        {
            answer.push_back(progresscount);
        }

    }

  

    return answer;
}