#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& num, int targetold ) {           
    int res;
    int min=INT_MAX;
	//排序 
    std::sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
		//依次为基准        
        int target = targetold-num[i];
        int front = i + 1;
        int back = num.size() - 1;		
        while (front < back) {
            int sum = num[front] + num[back];           
            // -8 -6 -3 -2 3 5 6          
            //该贪心保证了有一定选择到，不会发生你所担心的  
            //这个逼近的选择过程式核心！！！！！！！！！！！！！！！！！！贪心！！ 
            //当 sum小于基准目标，递增小的 
            if (sum < target)
            {
        		int ls=target-sum;
        		if(ls<min)
        		{
        			min=ls;
        			res=sum+num[i];
				}
            	front++;
			}               
			//sum大于基准目标，递增大的 
            else if (sum > target)
            {
            	int ls=sum-target;
        		if(ls<min)
        		{
        			min=ls;
        			res=sum+num[i];
				}
            	back--;
			}
            else {
                return targetold;
            }           
        }
    }
    return res;
    }
};



int main()
{
	
}
