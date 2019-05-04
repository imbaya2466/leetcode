#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	
	int map[10]={0,0,3,3,3,3,3,4,3,4};
	
	char charmap[10][4]={{0,0,0,0},{0,0,0,0},{'a','b','c',0},{'d','e','f',0},{'g','h','i',0},{'j','k','l',0},{'m','n','o',0},{'p','q','r','s'},{'t','u','v',0},{'w','x','y','z'}};
	
    vector<string> letterCombinations(string digits) {
    	
    	
    	if(digits.size()==0)
    	{
    		return vector<string>();
		}
    	
    	
    	int sum=1;
    	
        for(int i=0;i<digits.size();i++)
        {
        	int num=digits[i]-'0';
        	sum*=map[num];
		}
		
		vector<string> ret(sum);
		
		int lssum=sum;
		
		for(int i=0;i<digits.size();i++)
        {
        	int num=digits[i]-'0';
        	int charnum=map[num];
        	lssum/=charnum;
        	
        	int j=0;
        	while(j<sum)
        	{
        		for(int l=0;l<charnum;l++)
        		for(int k=0;k<lssum;k++)
        		{
        			ret[j].push_back(charmap[num][l]);
        			j++;
				}
			}
		}
        
        
        return ret;
        
        
    }
};



int main()
{
	
 } 
