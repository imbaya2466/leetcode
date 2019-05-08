#include <bits/stdc++.h>
using namespace std;

// my fastest
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int cont=0;
        for(int i=n-1;i>=0;i--){
        	if(nums[i]==val){
        		cont++;
        		nums[i]=nums[n-cont];
			}
		}
		return cont;
    }
};

int main(void){
	
}
