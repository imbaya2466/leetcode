#include <bits/stdc++.h>
using namespace std;


//�ݹ飬�ٺú���һ�� 
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
        //ֻҪ��֤����Ĵ��ڵ���ǰ��ľ��� ��������֤������ֻ������һ�� 
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
