#include<bits/stdc++.h>
using namespace std;

/*
动态规划 ，当子串匹配时 ，父根据子结果匹配




*/



class Solution {
public:
    bool isMatch(string s, string p) {
    	int m=s.size();
    	int n=p.size();
    	
    	//dp[i][j]代表 长度为i的s可以与长度为j的p匹配 
		vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
		
		dp[0][0]=true;
		//当p为0、s不为0时都是false
		//当s为0、p不为0时，如果当前位置是*且去俩位的子为true则为true 
		for(int i=1;i<=n;i++)
		{
			dp[0][i]=i>1&&p[i-1]=='*'&&dp[0][i-2];
		}
		
		//开始增长
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				/*
				直接匹配或以*匹配 
					
				*匹配 
						
				直接匹配:  
					当前匹配且子匹配 
				*/ 
				if(p[j-1]=='*')
				{
					dp[i][j]=dp[i][j-2]||(p[j-2]==s[i-1]||p[j-2]=='.')&&dp[i-1][j];
				} 
				else
				{
					dp[i][j]=(p[j-1]==s[i-1]||p[j-1]=='.')&&dp[i-1][j-1];
				}
				
			}
		} 
		
		return dp[m][n];
				
    }
};


int main()
{
	string a,b;
	cin>>a>>b;
	Solution s;
	cout<<s.isMatch(a,b);
	
}
