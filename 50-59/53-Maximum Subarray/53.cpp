#include <bits/stdc++.h>
using namespace std;


//一开始的思路是对的 
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
