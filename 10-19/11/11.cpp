#include<bits/stdc++.h>
using namespace std;


//��һ��д�ķ��� 
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


//�Ϻô�
//̰�� 
class Solution {
public:
	
int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        
        
        //Ѱ�����ұ�h����ģ�С�ڵ��ڶ��ᶯ 
        //��߱�����hС�Ļ������� 
        while (height[i] <= h && i < j) i++;
        //�ұ߱�����hС�Ļ������� 
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
