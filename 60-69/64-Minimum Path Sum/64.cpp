#include <bits/stdc++.h>
using namespace std;

//直接超时....必须dp 
class Solution {
public:
	int n,m;
	int ret=9999;
	
	void dfs(vector<vector<int>>& map,int x,int y,int sum){
		if(x==n||y==m||sum>=ret){
			return;
		}
		if(x==n-1&&y==m-1){
			ret=min(sum,ret);
			return;
		}
		if(y+1!=m)
		dfs(map,x,y+1,sum+map[x][y+1]);
		if(x+1!=n)
		dfs(map,x+1,y,sum+map[x+1][y]);
	}
	
	
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=n?grid[0].size():0;
        dfs(grid,0,0,grid[0][0]);
        return ret;
    }
};
//dp这个必须自己想出来！！！！ 
// dp[n][m]表示到nm的最小值 
// dp[n][m]=min(dp[n-1][m],dp[n][m-1])+map[n][m]
class Solution {
public:
	
    int minPathSum(vector<vector<int>>& map) {
		int n=map.size();
        int m=n?map[0].size():0;
  		vector<vector<int>> dp(n,vector<int>(m,0));
  		int sum=0;
		for(int i=0;i<n;i++){
  			sum+=map[i][0];
  			dp[i][0]=sum;
		}
		sum=0;
		for(int i=0;i<m;i++){
  			sum+=map[0][i];
  			dp[0][i]=sum;
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+map[i][j];
			}
		}
		return dp[n-1][m-1];
    }
};






int main(){
	vector<vector<int>> map={{1,3,1},{1,5,1},{4,2,1}};
	Solution s;
	cout<<s.minPathSum(map);
} 
