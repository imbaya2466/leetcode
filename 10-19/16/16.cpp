#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& num, int targetold ) {           
    int res;
    int min=INT_MAX;
	//���� 
    std::sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
		//����Ϊ��׼        
        int target = targetold-num[i];
        int front = i + 1;
        int back = num.size() - 1;		
        while (front < back) {
            int sum = num[front] + num[back];           
            // -8 -6 -3 -2 3 5 6          
            //��̰�ı�֤����һ��ѡ�񵽣����ᷢ���������ĵ�  
            //����ƽ���ѡ�����ʽ���ģ�����������������������������������̰�ģ��� 
            //�� sumС�ڻ�׼Ŀ�꣬����С�� 
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
			//sum���ڻ�׼Ŀ�꣬������� 
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
