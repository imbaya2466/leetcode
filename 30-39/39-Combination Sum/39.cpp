#include <bits/stdc++.h>
using namespace std;


//递归，再好好想一下 
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> add;
	
	int dfs(int sub,vector<int>& candidates,int begin){
		if(sub==0){
			ret.push_back(add);
			return 1;
		}
        if(sub<0){
            return 1;
        }
        //只要保证后面的大于等于前面的就行 ，这样保证了序列只会遇到一次 
		for(int i=begin;i<candidates.size();i++){
			add.push_back(candidates[i]);
			int num=dfs(sub-candidates[i],candidates,i);
			add.pop_back();
			if(num) return 0;
		}
		return 0;
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        dfs(target,candidates,0);
        return ret;
    }
};







int main(){
}
