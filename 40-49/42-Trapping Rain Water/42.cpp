
#include <bits/stdc++.h>
using namespace std;

//失败的版本，不能一行一行加，超时 
class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int h=1;
        int beg=0,end=height.size();
        while(1){
        	int left=-1;
        	int check_end=-1;
        	for(int i=beg;i<end;i++){
        		if(height[i]>=h){
        			if(left==-1){
        				beg=i;
					}else{
						sum=sum+i-left-1;
					}
					check_end=i;
					left=i;
				}
			}        	
			end=check_end+1;
        	if(end-beg<=2){
        		return sum;
			}
			h++;
		}
		return sum;
    }
};

//大佬的版本
int trap2(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
    	//左右低的逼近，返回低的值    取低保证没有问题 
        int lower = height[height[l] < height[r] ? l++ : r--];
        //获取底的值和当前水面，差值为水的高度  
        level = max(level, lower);
        water += level - lower;
    }
    return water;
} 


int main(){
	Solution s;
	vector<int> a={2,0,2};
	s.trap(a);
	trap2(a);
}
