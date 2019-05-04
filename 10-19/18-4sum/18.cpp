#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& num, int target) {
    	
    vector<vector<int> > res;
	//排序 
    std::sort(num.begin(), num.end());

	
    for (int i = 0; i < num.size(); i++) {
	for(int j=i+1;j<num.size();j++){
		//依次为基准        
        int targetn = target-(num[i]+num[j]);
        int front = j + 1;
        int back = num.size() - 1;
        while (front < back) {
            int sum = num[front] + num[back];
            // -8 -6 -3 -2 3 5 6
            //该贪心保证了有一定选择到，不会发生你所担心的  
            //当 sum小于基准目标，递增小的 
            if (sum < targetn)
                front++;
			//sum大于基准目标，递增大的 
            else if (sum > targetn)
                back--;
            else {
                vector<int> triplet(4, 0);
                triplet[0] = num[i];
                triplet[1] = num[j];
                triplet[2] = num[front];
                triplet[3] = num[back];
                res.push_back(triplet);
                
                //左++后右必不匹配，因此一次动俩个没有问题 
                do{front++;}while(num[front]==num[front-1]&&front<back);
                do{back--;}while(num[back]==num[back+1]&&front<back);
                
            }
            
        }
		//跳过重复数字 
        // Processing duplicates of Number 1
        while (j + 1 < num.size() && num[j + 1] == num[j]) 
            j++;
    }
    while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;
	}
    return res;
    }
};


int main()
{
   Solution a;
   vector<int> s={1,0,-1,0,-2,2};
   a.fourSum(s,0);
}






