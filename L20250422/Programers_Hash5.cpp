#include <string>
#include <vector>

#include<map>
#include <algorithm> // sort
using namespace std;




vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> Countgenres;
    vector<int> answer;
    int arr[2] = { -1,-1 };
    //��� �帣�� �� ū�� �˾ƺ������� 
    for (int i = 0; i < genres.size(); i++)
    {
        Countgenres[genres[i]] += plays[i];
    }

    vector<pair<string, int>> SortGenres(Countgenres.begin(), Countgenres.end());
   
    // map�� sort�� �������� �ʱ⶧���� vector<pair>�� ��ȯ�Ͽ� ���
    sort(SortGenres.begin(), SortGenres.end(), [](pair<string, int>& a, pair<string, int>& b) {return a.second > b.second; }); 

    struct songs
    {
        int index;
        int play;
    };

    vector<songs> Songs;
    
    for (auto SortSong : SortGenres)
    {
        string indexString;
        indexString = SortSong.first;
        for (int i = 0; i < genres.size(); i++)
        {
            if (indexString == genres[i])
            {
                songs A;
                A.index= i;
                A.play = plays[i];
                Songs.push_back(A);
            }
        }
        // Songs ���͸� sorting ���ǿ� ���ؼ� 
        sort(Songs.front(), Songs.back(), [](songs& a, songs& b) {
            if (a.play == b.play)
                return a.index < b.index;
            return a.play > b.play;
            });
       
        answer.push_back(Songs[0].index);
        answer.push_back(Songs[1].index);
        Songs.clear();



    }


    
    return answer;
}