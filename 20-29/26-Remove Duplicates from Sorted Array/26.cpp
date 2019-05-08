#include <bits/stdc++.h>
using namespace std;

//garbage practices 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int i=0;
  		while(true){
  			if(nums.size()==i+1){
  				break;
			  }
			if(nums[i]==nums[i+1]){
				nums.erase(nums.begin()+i);
			}else{
				i++;
			}
		  }      
		  return nums.size();
    }
};

// std should used   erase after all move is quick 
// erase 2*once is more faster than 1*twice 
class Solution {
public:
int removeDuplicates(vector<int>& A){
    int n=A.size();
	int count = 0;
    for(int i = 1; i < n; i++){
        if(A[i] == A[i-1]) count++;
        else A[i-count] = A[i];
    }
    return n-count;
}
};

//0,0,1,1,1,2,2,3,3,4
int main(){
	
}
