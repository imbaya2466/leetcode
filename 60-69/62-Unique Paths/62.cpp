#include <bits/stdc++.h>
using namespace std;

//dfsֱ�ӳ�ʱ 
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
    	//dp[m][n]��ʾ�յ���mn��·������Ϊ���ص���dp[m-1][n-1] 
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
//dp һ��Ҳ����
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
//��ѧ�ⷨ ���ܹ��ߵ�m+n-2������ϳ�m-1����n-1
//Ҳ���Ǹ�������� C(m+n-2,m-1)=  C(m+n-2,n-1)
//������кܶ��󷨣���ֱ�ӵĽ׳˺����û��dp�졣 







int main(){
	Solution s;
	s.uniquePaths(3,2);
}
