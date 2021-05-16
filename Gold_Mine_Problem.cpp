/*
Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect. 
Examples: 
 

Input : mat[][] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: mat[][] = { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)

Input : mat[][] = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
Output : 83

*/



#include <iostream>

#define MAX_SIZE 100
#define INT_MIN -99999

using namespace std;

int max(int i, int j, int k) {
    return (i>j)&&(i>k)?i : (j>k)?j:k;
}


int find_max_gold(int arr[MAX_SIZE][MAX_SIZE], int n, int m) {
    
    int mem[n]= {0};
    int new_mem[n]= {0};
    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            int left_val= j>0?mem[j-1]:INT_MIN;
            int right_val= j<n-1?mem[j+1]:INT_MIN;
            new_mem[j]= max(left_val, right_val, mem[j]);
        }
        for(int x=0; x<n; x++) {
            mem[x]= new_mem[x];
        }
    }
    int max_element= INT_MIN;
    for(int i=0; i<n; i++) {
        max_element= mem[i]>max_element?mem[i]:max_element;
    }
    return max_element;
}

