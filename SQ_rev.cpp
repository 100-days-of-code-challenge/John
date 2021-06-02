#include <iostream>
#include <stack>

using namespace std;

char* reverse(char *S, int len)
{
    stack<char> stk;

    for(int i=0; i<len; i++) {
        stk.push(S[i]);
    }

    char *res= (char *) malloc(sizeof(char)*(len+1));

    for(int i=0; i<len; i++) {
        res[i]= stk.top();
        stk.pop();
    }
    res[len]= '\0';

    return res;

}