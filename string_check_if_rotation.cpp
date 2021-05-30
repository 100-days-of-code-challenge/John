#include <iostream>
#include <vector>
#include <string>


using namespace std;


bool if_rot(string s1, string s2) {
    // remove "abcd", "bc" cases
    if(s1.length() != s2.length())
        return false;
    string d= s1+s1;

    return d.find(s2) != string::npos;
}

int main() {
    string s1= "hello";
    string s2= "lohel";

    cout << if_rot(s1, s2)<< "\n";

}