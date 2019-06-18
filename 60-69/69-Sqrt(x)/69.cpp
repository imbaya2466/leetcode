#include <bits/stdc++.h>
using namespace std;

//直接二分法 
class Solution {
public:
    int mySqrt(long long x) {
 		long long beg=0;
 		long long end=x;
		while(1){
			long long ret=(beg+end)/2;
			long long now=ret*ret;			
 			if(now<=x&&(ret+1)*(ret+1)>x){
 				return ret;
			}
			if(now<x){
				beg=ret+1;
			}else{
				end=ret;
			}
			
		}       
    }
};


int main(){
	
	
}
