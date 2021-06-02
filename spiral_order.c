
#include <stdio.h>
#include <stdlib.h>


int *spiral(int n) {

    // int res [n*n];

    int *res= (int *)malloc(sizeof(int)*n*n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            res[i*n+j]= -1;
    }


    int i=0, j=0;
    int i_increasing= 0, j_increasing= 1, i_decresing= 0, j_decresing= 0;

    for(int el=1; el<=n*n; el++) {
        
        res[i*n+j]= el;


        if(i_increasing) i++;
        else if(j_increasing) j++;
        else if(i_decresing) i--;
        else if(j_decresing) j--;

        if( i<0 || i>=n || j<0 || j>=n || res[i*n+j]!=-1){
            if(j_increasing) {
                j--;
                i++;
                j_increasing=0;
                i_increasing=1;
            }
            else if(i_increasing) {
                i--;
                j--;
                i_increasing=0;
                j_decresing=1;
            }
            else if(j_decresing) {
                j++;
                i--;
                j_decresing=0;
                i_decresing=1;
            }
            else if(i_decresing) {
                i++;
                j++;
                i_decresing=0;
                j_increasing=1;
            }
        }

    }


    return res;
}



int main() {

    int n=5;

    int *res= spiral(n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", res[i*n+j]);
        }
        printf("\n");
    }

    return 0;

}


