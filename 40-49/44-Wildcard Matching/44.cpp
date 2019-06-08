#include <bits/stdc++.h>

using namespace std;

 
//我的dp方法 
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
    	int n=p.size();
    	//dp[i][j]代表 长度为i的s可以与长度为j的p匹配 
		vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
		dp[0][0]=true;

		for(int i=1;i<=n;i++)
		{
			dp[0][i]=p[i-1]=='*'&&dp[0][i-1];
		}

		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(p[j-1]=='*')
				{
					dp[i][j]=dp[i][j-1]||dp[i-1][j];
				} 
				else
				{
					dp[i][j]=(p[j-1]==s[i-1]||p[j-1]=='?')&&dp[i-1][j-1];
				}
				
			}
		} 
		
		return dp[m][n];
    }
};

//大佬更快的方法：
class Solution {
public:
    bool isMatch(string s, string p) {
        int  slen = s.size(), plen = p.size(), i, j, iStar=-1, jStar=-1;

        for(i=0,j=0 ; i<slen; ++i, ++j)
        {
            if(p[j]=='*')
            { //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j;
                --i;
            }
            else
            { 
                if(p[j]!=s[i] && p[j]!='?')
                {  // mismatch happens
                    if(iStar >=0)
                    { // met a '*' before, then do traceback
                        i = iStar++;
                        j = jStar;
                    }
                    else return false; // otherwise fail
                }
            }
        }
        while(p[j]=='*') ++j;
        return j==plen;
    }
}; 






int main(){
}
