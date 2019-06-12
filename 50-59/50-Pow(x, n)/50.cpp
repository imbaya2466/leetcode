#include <bits/stdc++.h>
using namespace std;

//a11=a1+a2+a8    
//也就是说将幂化为2的次方依次相加
//每次底数翻倍表示幂2的幂多1，当幂累计达到目标幂时即可，又因为以2为计数，因此直接将11化为2进制即可 
class Solution {
public:
    double myPow(double x,long n) {
        long y=abs(n);
        double ans=1,cnt=x;
        while(y){
            if(y&1){//如果这位有1，那么a的2的这位幂就算它的因数之一 
                ans*=cnt;
            }
            cnt*=cnt;
            y>>=1;
        }
        if(n<0) return 1.0/ans;
        return ans;
    }
};


int main(){
	
}
