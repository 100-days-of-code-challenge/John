#include <iostream>
#include <vector>
#include <string>

using namespace std;




string lps_even_len(string s, int mid) {
    int ind= 0;
    string res= "";
    while(mid-ind >=0 && mid+ind+1<s.length() && s[mid-ind]  == s[mid+ind+1]) {
        res= s[mid-ind] + res + s[mid+ind+1];
        ind++;
    }
    return res;
}

string lps_odd_len(string s, int mid) {
    int ind= 1;
    string res=s.substr(mid, 1);
    
    while(mid-ind>=0 && mid+ind < s.length() && s[mid-ind] == s[mid+ind]) {
        res= s[mid-ind] + res + s[mid+ind];
        ind++;
    }

    return res;
}

string longest_pal_substr(string s) {
    string res= "";
    for(int i=0; i<s.length(); i++) {
        string lps_even= lps_even_len(s, i);
        string lps_odd= lps_odd_len(s, i);

        if(lps_odd.length() > res.length())
            res= lps_odd;
        if(lps_even.length() > res.length())
            res= lps_even;
    }
    return res;
}
















int main() {

    cout << longest_pal_substr("aaaabcbaa");

    return 0;
}