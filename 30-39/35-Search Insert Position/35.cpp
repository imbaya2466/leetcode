#include <bits/stdc++.h>
using namespace std;


// my
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
    	
    	while(i<j){
    		int mid=(i+j)/2;
    		if(nums[mid]==target){
    			return mid;
			}
    		if(nums[mid]>target){
    			j=mid;
			}else{
				i=mid+1;
			}	
		}
		if(nums[i]<target) return i+1;
		return i;
    }
};

// ����ʱ�ҵ���ʱʹ��<=���ã���֤���lowλ����ȷ 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
		return low;
    }
};






int main(){
	cout<<3/2;
}
