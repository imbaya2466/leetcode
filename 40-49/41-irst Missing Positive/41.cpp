#include <bits/stdc++.h>

using namespace std;

//我的解法   不可以使用sort！！！ 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++){
        	if(nums[i]<0){
        		i--;
        		continue;
			}
				
			if(nums[i]!=i){
				return i;
			}
		}
        return nums.size()+1;
    }
};

//大佬的解法
class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        //依次将数字放到对应的位置上，原处的会一直被置换，注意用while即可 
        //这里保证了范围内的数字一定会放到对应的位置，多余的数字放当前替换位即可，自己也算多余 
		//  1  2   5   7    4   6
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};

 




int main(){
	Solution s;
	vector<int> nums={1,2,0};
	cout<<s.firstMissingPositive(nums);
}
