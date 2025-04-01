#include <iostream>
#include <algorithm>  // sort() ����� ���� ��� �߰�
using namespace std;

struct Meeting {
    int start, end;
};

bool CompareEndTime(Meeting a, Meeting b) {
    if (a.end == b.end) return a.start < b.start;
    return a.end < b.end;
}

void FindNumOfMeets(int* Count, int NumberOfMeet, Meeting* Meetings);

int main() {
    int CountOfMeet = 0;
    int NumberOfMeet;
    cin >> NumberOfMeet;

    Meeting* Meetings = new Meeting[NumberOfMeet];

    for (int a = 0; a < NumberOfMeet; a++) {
        cin >> Meetings[a].start >> Meetings[a].end;
    }

    sort(Meetings, Meetings + NumberOfMeet, CompareEndTime);
    
    

    FindNumOfMeets(&CountOfMeet, NumberOfMeet, Meetings);

    cout << CountOfMeet;
    delete[] Meetings;
    return 0;
}

void FindNumOfMeets(int* Count, int NumberOfMeet, Meeting* Meetings) {
    if (NumberOfMeet == 0) return;  

    int MeetCount = 0; 
    (*Count)++;  
    for (int a = 1; a < NumberOfMeet; a++)
    {
        if (Meetings[a].start >= Meetings[MeetCount].end)
        {
            MeetCount = a;
            (*Count)++;
        }
    }
}



/* 1ȸ��
*
int MeetNum = 0;
if (*Count == 0) {
    (*Count)++;
}

for (;;) {
    int CompareNum = MeetNum;
    int MeetNum2 = -1;  //  �ʱⰪ ����

    for (int a = 0; a < NumberOfMeet; a++) {
        if (Meetings[a].start >= Meetings[MeetNum].end) { //  ������ ����
            if (MeetNum2 == -1 || CompareEndTime(Meetings[a], Meetings[MeetNum2])) {
                MeetNum2 = a;
            }
        }
    }

    if (MeetNum2 == -1) break; //  �� �̻� ������ ȸ�ǰ� ������ ����

    MeetNum = MeetNum2;
    (*Count)++;
}*/