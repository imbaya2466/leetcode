#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min=INT_MAX;
        string a,b;
        int lengtha,lengthb;
        int num=strs.size();
        
        if(num==0)
        {
        	return "";
		}
		if(num==1)
		{
			return strs[0];
		}
        
        
        a=strs[0];
        for(int i=1;i<num;i++)
        {
        	b=strs[i];
        	
        	char s=1;
        	int j=0;
        	
			while(j<a.size()&&j<b.size())
			{
				s=a[j]^b[j];
				if(s!=0)
				{
					break;
				}
				j++;
			}
        		
			if(j<min)
			{
				min=j;
			}
        	
		}
        
        
        
        return a.substr(0,min);
        
        
    }
};

int main()
{
	
} 
