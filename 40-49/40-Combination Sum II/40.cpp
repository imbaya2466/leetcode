#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> ret;
	vector<int> add;
    //��Ҫ��ǰ��Ҫ�ظ�ѡ�񣬵�������������Ҫ����ѡ
	void dfs(int sub,vector<int>& candidates,int begin){
		if(sub==0){
			ret.push_back(add);
			return;
		}
        if(sub<0){
            return;
        }
        //��һ����Ҫ�����������ظ�����������֤���ظ��Ŀɱ���ѡ(һ������ÿ�εݹ�ѡһ���������ģ���˱�λ���ظ���Ӱ��)�����Ǳ�λ������ѡ����ظ�ֵ
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
