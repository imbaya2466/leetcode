#include <bits/stdc++.h>
using namespace std;

// 00 01 02
// 10 11 12
// 20 21 22

// x,y		y,n-x
// n-y,x	n-x,n-y

// 00 01 02 03 
// 10 11 12 13
// 20 21 22 23
// 30 31 32 33


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int k=n-1;
        for(int i=0;i<n/2;i++){
        	for(int j=i;j<k-i;j++){
        		int tmp=matrix[i][j];
        		matrix[i][j]=matrix[k-j][i];
        		matrix[k-j][i]=matrix[k-i][k-j];
        		matrix[k-i][n-1-j]=matrix[j][k-i];
        		matrix[j][k-i]=tmp;
			}
		}
    }
};




int main(){
	
}
