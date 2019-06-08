#include <bits/stdc++.h>

using namespace std;
//dfs
// 1 1 2
// 1 2 1
// 2 1 1
// 不能用引用传参前后交换的原因是
// 1 2 2 这俩个1都会与2交换被放过来。剪枝只是将与当前相同的交换去掉 ，但不能保证换过来的不一样 
 
class Solution {
public:
	vector<vector<int>> ret;
	void dfs(vector<int> nums,int step){
		if(step==nums.size()-1){
			ret.push_back(nums);
			return;
		}
		for(int i=step;i<nums.size();i++){
			if (i != step && nums[i] == nums[step]) continue;
			swap(nums[step],nums[i]);
			dfs(nums,step+1); //使用非引用传递保证了不会对当前进行修改
			//删除调用后交换即可保证每次换的都不一样，因为排序过了 
		}
		
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ret;
    }
};

 

// 从当前交换意味着后面的每个数都会被放在这里一次，这里的数是什么以及后面的数怎么样完全不用管 
// [1,2,3]
// [1,3,2]
// [2,1,3]
// [2,3,1]
// [3,2,1]
// [3,1,2]
//能解决但很慢 
class Solution {
public:
	set<vector<int>> ret;
	void dfs(vector<int> &nums,int step){
		if(step==nums.size()){
			ret.insert(nums);
			return;
		}
		for(int i=step;i<nums.size();i++){
			swap(nums[step],nums[i]);
			dfs(nums,step+1);
			swap(nums[step],nums[i]);
		}
		
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums,0);
        return vector<vector<int>> (ret.begin(), ret.end());
    }
};


int main(){

}
