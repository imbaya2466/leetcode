#include<bits/stdc++.h>
using namespace std;


//第一次写的方法 
class Solution {
public:
	
    int maxArea(vector<int>& height) {
    
		int max=0;
		
		int num=height.size();
		
		
		for(int i=num-1;i>0;i--)
		{
			
			for(int k=0;k<i;k++)
			for(int j=k;j<num-i;j+=i)
			{
				if(min(height[j+i],height[j])*i>max)
				{
					max=min(height[j+i],height[j])*i;	
				}	
			}	
		}
		return max;    
    }
};


//较好答案
//贪心 
class Solution {
public:
	
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        
        
        //寻找左右比h更大的，小于等于都会动 
        //左边比现在h小的话就右移 
        while (height[i] <= h && i < j) i++;
        //右边比现在h小的话就左移 
        while (height[j] <= h && i < j) j--;
    }
    return water;
}
}; 



int main()
{		
	vector<int> height;
	int a;
	int num;
	cin>>num;
	while(num--)
	{
		cin>>a;
		height.push_back(a);
	}
	
	Solution s;
	cout<<s.maxArea(height);
	
	
	
}
