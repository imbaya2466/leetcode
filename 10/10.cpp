#include<bits/stdc++.h>
using namespace std;

/*
��̬�滮 �����Ӵ�ƥ��ʱ ���������ӽ��ƥ��




*/



class Solution {
public:
    bool isMatch(string s, string p) {
    	int m=s.size();
    	int n=p.size();
    	
    	//dp[i][j]���� ����Ϊi��s�����볤��Ϊj��pƥ�� 
		vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
		
		dp[0][0]=true;
		//��pΪ0��s��Ϊ0ʱ����false
		//��sΪ0��p��Ϊ0ʱ�������ǰλ����*��ȥ��λ����Ϊtrue��Ϊtrue 
		for(int i=1;i<=n;i++)
		{
			dp[0][i]=i>1&&p[i-1]=='*'&&dp[0][i-2];
		}
		
		//��ʼ����
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				/*
				ֱ��ƥ�����*ƥ�� 
					
				*ƥ�� 
						
				ֱ��ƥ��:  
					��ǰƥ������ƥ�� 
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
