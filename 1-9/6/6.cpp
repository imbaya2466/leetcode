#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    
    
    
    
    //1 7  13
    //2 6 8 12 14
    //3 5 9 11
    //4 10
    
    
    
    string convert(string s, int numRows) {
        
        string ret;
                                         
                                         
        int a=numRows*2-2;
        
        if(a==0)
        {
            return s;
        }
        
        int size=s.size();
        
        
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<size;j+=a)
            {

                 ret.push_back(s[j]);
                
                if(j%a!=0&&(j-numRows+1)%a!=0)
                {
                    int k=j+a-i*2;
                    if(k<size)
                    {
                         ret.push_back(s[k]);

                    }
                }
                
            }
        }
        
        
        
     return ret;   
    }
};




//6 4 2 0
int main()
{
	
	string s;
	int n;
	cin>>s>>n;
	Solution l;
	string a=l.convert(s,n);
	cout<<a;
}
