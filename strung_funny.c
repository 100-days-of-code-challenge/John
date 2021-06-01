#include <stdio.h>
#include <string.h>


int abs_diff(int a, int b){
	return a>b? a-b:b-a;
}

char* funnyString(char* s) {
	int len= strlen(s);

	for(int i=0; i<len-1; i++) {
		if(abs_diff(s[i], s[i+1]) != abs_diff(s[len-i-1], s[len-i-2]))
			return "Not Funny";
	}
	return "Funny";
}

int main() {





	return 0;
}
