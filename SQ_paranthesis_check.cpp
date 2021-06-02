#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    // bool ispar(string x)
    // {
    //     // Your code here

    //     stack<char> stk;

    //     for(char c: x){
    //         switch(c) {
    //             case '(':
    //             case '{':
    //             case '[':
    //                 stk.push(c);
    //                 break;
    //             case ')':
    //                 if(!stk.empty() && stk.top() == '(') {
    //                     stk.pop();
    //                     break;
    //                 }
    //                 else return false;

    //             case '}':
    //                 if(!stk.empty() && stk.top() == '{') {
    //                     stk.pop();
    //                     break;
    //                 }
    //                 else return false;

    //             case ']':
    //                 if(!stk.empty() && stk.top() == '[') {
    //                     stk.pop();
    //                     break;
    //                 }
    //                 else return false;
    //             default:
    //                 return false;
    //         }
    //     }

    //     if(!stk.empty()) return false;

    //     return true;

    // }



    bool ispar(string x)
    {
        stack<char>s;
        int l = x.size();
        for(int i=0;i<l;i++)
        {
            char c  = x[i];
            if(c=='(' || c == '[' || c== '{')
            {
               s.push(c);
            }
            else 
            {
                if(s.empty())
                    return false;
                
                if(c == ')' && s.top() != '(')
                return false;
                
                  if(c == '}' && s.top() != '{')
                    return false;
                
                  if(c == ']' && s.top() != '[')
                      return false;
                
                s.pop();
                
            }
        }
        
        // Y our code here
        
        return s.empty();
    }

};


int main() {

    Solution s;
    
    string par= "{[(())]()}";


    cout << s.ispar(par) << endl;

}