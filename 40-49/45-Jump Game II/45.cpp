#include <bits/stdc++.h>
using namespace std;

//dfs     ʱ�䳬�� 
class Solution {
public:
	int min=INT_MAX;
	void f(vector<int>& nums,int now,int num){
		if(now>=nums.size()-1){
			if(min>num){
				min=num;
			}
			return;
		}
		for(int i=1;i<=nums[now];i++){
			f(nums,now+i,num+1);
		}
	}
	
    int jump(vector<int>& nums) {
       f(nums,0,0);
       return min;
    }
    
    
};

//bfs����С����Ҫ��¼ÿ��λ���ǵڼ����ģ�������Ϊ��������޷�ʹ�ñ���˳�������
//���Ҫ�����ͼ��С��¼��������������ÿ�η���ͼ��ĳһ���ʱ���ǵڼ������� 

//bfs���ǹ�����ȣ�һ��ʼ����ǶԵģ��� 
//����ⷨ���Ǳ�׼��bfs��ʹ��������ֻҪ�������У����ÿ�����ϴ���ĩ��ʼ��������ok
 
 //ÿ�ε�һ����¼�����ⲽ�����ߵ���Զ���䣬���һ�������ϸ�end+1�ģ������ͣ�ˡ� 
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) {
            step++; 
			int maxend = end + 1;
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return step;
				maxend = max(maxend, i + nums[i]);
			}
            start = end + 1;
            end = maxend;
        }
		return step;
    }
};


int main(){
	
}
