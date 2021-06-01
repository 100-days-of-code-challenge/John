#include <iostream>
#include <vector>
#include <string>

using namespace std;



string count_and_say(int n) {

	if(n == 1)
		return "1";

	string num;
	if(n == 2)
		num= "1";
	else num= count_and_say(n-1);

	string res= "";
	char last= '$';
	int count= 0;

	for(int i=0; i<num.length(); i++) {

		if(num[i] == last) {
			count++;
		} else {
			if(count!=0)
				res+= to_string(count)+(num[i-1]);
			last= num[i];
			count= 1;
		}

	}

	if(count>0)
		res+= to_string(count)+(num[num.length()-1]);
	
	return res;
}







int main() {


	cout << count_and_say(2) << " "<< count_and_say(2).length() <<endl;

	// Solution s;
	// cout << s.lookandsay(3)<<endl;



	return 0;
}
