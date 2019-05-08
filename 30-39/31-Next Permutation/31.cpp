#include <bits/stdc++.h>
using namespace std;
// 1 2 3 4 5 6
// 1 6 2 4 6 5 3

// AC & 100%
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int swap1=nums.size()-1;
    	int i=swap1-1;
        for(;i>=0;i--){
        	if(nums[i]<nums[swap1]){
        		swap1=i;
        		break;
			}
			swap1=i;
		}
		if(i<0) {
            sort(nums.begin(),nums.end());
            return;
        }
		int swap2;
		for(i=nums.size()-1;i>swap1;i--){
        	if(nums[i]>nums[swap1]){
        		swap2=i;
        		break;
			}
		}
		swap(nums[swap1],nums[swap2]);
		sort(nums.begin()+swap1+1,nums.end());
    }
};





int main(){
	
}
