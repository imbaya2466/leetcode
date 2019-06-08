#include <bits/stdc++.h>
using namespace std;

//dfs     时间超出 
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

//bfs求最小步数要记录每个位置是第几步的！！！因为横向遍历无法使用遍历顺序代表步数
//因此要额外的图大小记录！！！！！记下每次访问图中某一点的时候是第几步就行 

//bfs才是广度优先，一开始想的是对的！！ 
//这个解法不是标准的bfs，使用了特性只要超出就行，因此每次是上次最末开始，超出就ok
 
 //每次的一步记录的是这步可能走的最远区间，因此一定是有上个end+1的，否则就停了。 
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
