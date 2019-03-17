#include<bits/stdc++.h>
using namespace std;
#define ll long long 
class Solution {
public:
    int reverse(int x) {
    	ll reg=0;
   		
        while(x/10!=0)
        {
        	reg=x%10+reg*10;
        	
        	x/=10;
		}
	
		reg=x%10+reg*10;
		
		return (reg<INT_MIN || reg>INT_MAX) ? 0 : reg;
		
    }
};

int main()
{
	int i;
	cin>>i;
	Solution a;
	cout<<a.reverse(i);
	
}
