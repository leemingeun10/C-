#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
bool solution(const char* s) {
    bool answer = true;
    
    int count = 0;
    int len = strlen(s);

    for (int i = 0 ; i< len; i++)
    {
        if (s[i] == '(')
        {
            count++;
        }
        else
        {
            count--;
        }
        
        if (count < 0)
        {
            answer = false;
        }

    }

    if (count != 0)
    {
        answer = false;
    }

    return answer;
}