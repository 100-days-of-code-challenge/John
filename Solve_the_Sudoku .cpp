#include <iostream>

using namespace std;


const int N= 9;

bool notEmpty(int grid[N][N] ,int &r,int &c) {
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			if(grid[i][j]==0) {
				r=i;
				c=j;
				return true;
			}
		}
	}
	return false;
}

bool isSafe(int i,int j,int vertical[9][10],int horizontal[9][10],int sub[9][10],int val,int findsub[9][9]) {
	if((horizontal[i][val]) || (vertical[j][val]) || (sub[findsub[i][j]][val]))
		return false;
	horizontal[i][val]=1;
	vertical[j][val]=1;
	sub[findsub[i][j]][val]=1;
	return true;
}
bool solution(int grid[N][N],int vertical[9][10],int horizontal[9][10],int sub[9][10],int findsub[9][9]) {
	int i,j;
	if(!notEmpty(grid,i,j))
		return true;
	for(int k=1;k<=9;k++) {
		if(isSafe(i,j,vertical,horizontal,sub,k,findsub)) {
			grid[i][j]=k;
			if(solution(grid,vertical,horizontal,sub,findsub))
				return true;
			grid[i][j]=0;
			horizontal[i][k]=0;
			vertical[j][k]=0;
			sub[findsub[i][j]][k]=0;
		}
	}
	return false;
}


bool SolveSudoku(int grid[N][N]) {

	int vertical[9][10]={0};
	int horizontal[9][10]={0};
	int sub[9][10]={0};
	int findsub[9][9]={0};
	int cnt=0;
	for(int r=0;r<9;r=r+3) {
		for(int c=0;c<9;c=c+3) {
			for(int i=0;i<3;i++) {
				for(int j=0;j<3;j++) {
					findsub[r+i][c+j]=cnt;
				}
			}
			cnt++;
		}
	}
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++) {
			horizontal[i][grid[i][j]]=1;
			vertical[j][grid[i][j]]=1;
			sub[findsub[i][j]][grid[i][j]]=1;
		}
	}
	return solution(grid,vertical,horizontal,sub,findsub);
}


void printGrid (int grid[N][N]) {
	for(int i=0;i<9;i++) {
		for(int j=0;j<9;j++)
		cout << grid[i][j] << " ";
	}
}