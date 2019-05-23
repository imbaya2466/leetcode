#incldue <bits/stdc++.h>
using namespace std;

// bad
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int a=-1,b=-1;
	  for(int i=0;i<nums.size();i++) {
	  	if(nums[i]==target){
	  		if(a==-1){
	  			a=i;
			  }
			
			if(i==nums.size()-1||nums[i+1]!=target){
				b=i;
				break;
			}
		  }
	  }
	  
	  return {a,b}; 
    }
};

// binary 
// 可以使用二分确认边界而非仅仅是一个值的位置 
class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
      vector<int> ret(2,-1);
      int i=0,j=A.size()-1;
      if(j==-1){
      	return ret;
	  }
      
    	while (i < j)
    	{
       		int mid = (i + j) /2;
        	if (A[mid] < target) i = mid + 1;
        	else j = mid;
    	}
    	if (A[i]!=target) return ret;
    	else ret[0] = i;
      
    	j = A.size()-1;  
    	while (i < j)
    	{
        	int mid = (i + j) /2 + 1;	
        	if (A[mid] > target) j = mid - 1;  
        	else i = mid;	
		}
    	ret[1] = j;
    	return ret; 
    }
};



int main(){
}
