#include <bits/stdc++.h>
using namespace std;


//һ��ʼ��˼·�ǶԵ� 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
        	sum+=nums[i];
        	ret=max(ret,sum);
        	sum=max(sum,0);
		}
		return ret;
    }
};


int main(){
	
}
