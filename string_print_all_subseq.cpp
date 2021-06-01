#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printSubsequence(string s, string res) {
    // cout << " " << s << endl << fflush;
    if(s.length() == 0){
        cout << res << "  ";
        return;
    }

    string new_res= res+s.substr(0,1);
    
    printSubsequence(s.substr(1,s.length()-1), new_res);
    printSubsequence(s.substr(1,s.length()-1), res);

}

void printSubsequence(string s) {
    printSubsequence(s, "");
}

int main() {


    cout << endl;
    printSubsequence("abcd");
    cout << endl;



    return 0;
}