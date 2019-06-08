#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> ret;
	vector<int> add;
    //需要当前不要重复选择，但是整个串中需要可重选
	void dfs(int sub,vector<int>& candidates,int begin){
		if(sub==0){
			ret.push_back(add);
			return;
		}
        if(sub<0){
            return;
        }
        //第一个不要跳过，后面重复的跳过，保证了重复的可被多选(一个串是每次递归选一个连起来的，因此本位不重复不影响)，但是本位不会重选多次重复值
		for(int i=begin;i<candidates.size();i++){
           if(i==begin||candidates[i]!=candidates[i-1]){
            add.push_back(candidates[i]);
			dfs(sub-candidates[i],candidates,i+1);
			add.pop_back();
           }
		}
		return ;
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(target,candidates,0);
        return ret;
    }
};


int main(){
	
}
