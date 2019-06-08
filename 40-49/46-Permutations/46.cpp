#include <bits/stdc++.h>

using namespace std;
//dfs
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> add;
	bool map[1000]={0};
	void dfs(vector<int>& nums,int step){
		if(step==nums.size()){
			ret.push_back(add);
			return;
		}
		for(int i=0;i<nums.size();i++){
			if(!map[i]){
				add.push_back(nums[i]);
				map[i]=true;
				dfs(nums,step+1);
				map[i]=false;
				add.pop_back();
			}
		}
		
	}
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ret;
    }
};

//dalao µÄdfs
class Solution {
public:
	vector<vector<int>> ret;
	void dfs(vector<int>& nums,int step){
		if(step==nums.size()){
			ret.push_back(nums);
			return;
		}
		for(int i=step;i<nums.size();i++){
			swap(nums[step],nums[i]);
			dfs(nums,step+1);
			swap(nums[step],nums[i]);
		}
		
	}
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ret;
    }
};
int main(){

}
