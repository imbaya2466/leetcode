#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	
	
	void f(string &s,int num,char a,char b,char c)
	{
		if(num>=0&&num<4)
		{
			while(num--)
			{
				s.push_back(a);
			}
		}
		else if(num==4)
		{
			s.push_back(a);
			s.push_back(b);
		}
		else if(num>4&&num<9)
		{
			s.push_back(b);
			num-=5;
			while(num--)
			{
				s.push_back(a);
			}
		}
		else
		{
			s.push_back(a);
			s.push_back(c);
		}
	}
	
	
    string intToRoman(int num) {
        int s[4]={0};
        int i=0;
        while(num)
        {
        	s[i++]=num%10;
        	num/=10;
		}
		string ret;
		//4λ 
		while(s[3]--)
		{
			ret.push_back('M');
		}
		
		
		f(ret,s[2],'C','D','M');
		f(ret,s[1],'X','L','C');
		f(ret,s[0],'I','V','X');
		
		return ret;
	}

};


int main()
{
	int a;
	cin>>a;
	Solution s;
	cout<<s.intToRoman(a);
	
	
}
