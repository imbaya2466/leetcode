#include <bits/stdc++.h>
using namespace std;

//a11=a1+a2+a8    
//Ҳ����˵���ݻ�Ϊ2�Ĵη��������
//ÿ�ε���������ʾ��2���ݶ�1�������ۼƴﵽĿ����ʱ���ɣ�����Ϊ��2Ϊ���������ֱ�ӽ�11��Ϊ2���Ƽ��� 
class Solution {
public:
    double myPow(double x,long n) {
        long y=abs(n);
        double ans=1,cnt=x;
        while(y){
            if(y&1){//�����λ��1����ôa��2����λ�ݾ�����������֮һ 
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
