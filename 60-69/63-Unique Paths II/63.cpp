#include <bits/stdc++.h>
using namespace std;

//dfs还是超时 
class Solution {
public:
	int n,m;
	int sum=0;
	void dfs(vector<vector<int>>& map,int x,int y){
		if(x==n||y==m||map[x][y]){
			return;
		}
		if(x==n-1&&y==m-1){
			sum++;
			return;
		}

		dfs(map,x+1,y);
		dfs(map,x,y+1);
	}
	
	
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        m=n?obstacleGrid[0].size():0;
        dfs(obstacleGrid,0,0);
        return sum;
    }
};

//这题还是可以使用dp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	//dp[m][n]表示地图大小mn的路数 ，因此不以初始首行全1，首行仅作为辅助记录
		//辅助记录为0用于没有障碍时加前面的，为1用于初始化没障碍时为1 
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n];
    }
}; 

int main(){
	
}
