#include <iostream>
#include <vector>
#include <string>


using namespace std;


string find_dup(string s) {
    string res= "";
    int mem[256]= {};

    for(int i=0; i<s.length(); i++)
        mem[s[i]]++;
    for(int i=0; i<256; i++)
        if(mem[i]>1) {
            res+= "found ";
            res+=(char)i;
            res+=" ";
            res+=to_string(mem[i]);
            res+=" times\n";
        }
    return res;
}








int main() {

    string s= "hello and hii and nothing";

    cout << find_dup(s) << "\n";


    return 0;
}
