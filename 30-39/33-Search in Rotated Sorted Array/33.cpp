#include <bits/stdc++.h>
using namespace std;

// bad answer
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
        	if(nums[i]==target){
        		return i;
			}
		}
		return -1;
    }
};
// good
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;

        while(lo<hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }

        int rot=lo;
        lo=0;hi=n-1;
		
		// 4 5 6 7 0 1 2  �±�+rot �ɻ�Ϊ����0 1 2 3 4 5 6 7
		// ���Ի������±�֮��Ϳ��԰�������ķ��ʻ�Ϊ��
		// ���Կ�������±꽫���黯Ϊ�� 
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(nums[realmid]==target)return realmid;
            if(nums[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};
int main(){
	
}
