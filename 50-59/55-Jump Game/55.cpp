#include <bits/stdc++.h>
using namespace std;




//Ψһ�������-�Ҵ����٣�����ܿ� 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i+=nums[i]){
        	if(nums[i]==0){
        		for(int j=0;j<i;j++){
        			if(nums[j]+j>i){
        				i++;
        				goto A;
					}
				}
				return false;
			}
			A:
				continue;
		}
        return true;
    }
};






int main(){
	
}
