
#include <stdio.h>
#include <stdlib.h>



int * find_permutation(char *s, int n) {

    int min= 1, max= n;
    int *res= (int*)malloc(sizeof(int)*n);

    for(int sp=n-2; sp>=0; sp--) {
        if(s[sp] == 'D' || s[sp] == 'S') {
            res[sp+1]= min++;
        }
        else {
            res[sp+1]= max--;
        }
    }
    res[0]= max;
    return res;
}


int main() {

    int *res= find_permutation("SGGSGGSG", 9);

    for(int i=0; i<9; i++) {
        printf("%d ", res[i]);
    }


    return 0;
}

1, n
