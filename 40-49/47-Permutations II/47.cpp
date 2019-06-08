#include <bits/stdc++.h>

using namespace std;
//dfs
// 1 1 2
// 1 2 1
// 2 1 1
// ���������ô���ǰ�󽻻���ԭ����
// 1 2 2 ������1������2�������Ź�������ֻ֦�ǽ��뵱ǰ��ͬ�Ľ���ȥ�� �������ܱ�֤�������Ĳ�һ�� 
 
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
			dfs(nums,step+1); //ʹ�÷����ô��ݱ�֤�˲���Ե�ǰ�����޸�
			//ɾ�����ú󽻻����ɱ�֤ÿ�λ��Ķ���һ������Ϊ������� 
		}
		
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ret;
    }
};

 

// �ӵ�ǰ������ζ�ź����ÿ�������ᱻ��������һ�Σ����������ʲô�Լ����������ô����ȫ���ù� 
// [1,2,3]
// [1,3,2]
// [2,1,3]
// [2,3,1]
// [3,2,1]
// [3,1,2]
//�ܽ�������� 
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
