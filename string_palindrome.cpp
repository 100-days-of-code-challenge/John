#include <iostream>
#include <string>


using namespace std;



bool isPal(string s) {
    for(int i=0; i<s.length()/2; i++)
        if(s[i] != s[s.length()-i-1])
            return false;
    return true;
}


int main() {

    string s= "abcdcba";

    cout << isPal(s);


	return 0;
}