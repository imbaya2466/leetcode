#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	
	
	vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

	//排序 
    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

		//依次为基准        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;


		
        while (front < back) {

            int sum = num[front] + num[back];
            
            // -8 -6 -3 -2 3 5 6
            
            
            //该贪心保证了有一定选择到，不会发生你所担心的  
            //当 sum小于基准目标，递增小的 
            if (sum < target)
                front++;
			//sum大于基准目标，递增大的 
            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                
                
                //去掉重复数字 
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }
		
		
		//跳过重复数字 
        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }
    
    return res;
    
}
};



int main()
{
	
	
}
