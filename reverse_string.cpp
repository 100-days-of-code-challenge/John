#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i<s.size()/2; i++) {
			char tmp= s[s.size()-i-1];
			s[s.size()-i-1]= s[i];
			s[i]= tmp;
		}
    }
};


int main() {

	Solution s;

	vector<char> str {'h', 'e', 'l', 'l', '0'};

	s.reverseString(str);

	for(int i=0; i<str.size(); i++) {
		cout <<  str[i];
	}



	return 0;
}
