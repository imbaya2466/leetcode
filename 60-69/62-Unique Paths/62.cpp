#include <bits/stdc++.h>
using namespace std;

//dfs直接超时 
class Solution {
public:
	int n,m;
	int sum=0;
	void f(int x,int y){
		if(x==n-1&&y==m-1){
			sum++;
			return;
		}
		if(x==n||y==m){
			return;
		}
		f(x+1,y);
		f(x,y+1);
	}
	
	
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        f(0,0);
        return sum;
    }
};

//dp
// dp[i][j]=dp[i-1][j]+dp[i][j-1]
class Solution {
public:
	
    int uniquePaths(int m, int n) {
    	//dp[m][n]表示终点在mn的路数，因为返回的是dp[m-1][n-1] 
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
//dp 一行也可以
 class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        return dp[n - 1];
    }
};
//数学解法 从总共走的m+n-2步中组合出m-1或者n-1
//也就是高中组合数 C(m+n-2,m-1)=  C(m+n-2,n-1)
//组合数有很多求法，但直接的阶乘后除并没有dp快。 







int main(){
	Solution s;
	s.uniquePaths(3,2);
}
