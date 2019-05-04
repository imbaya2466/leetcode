#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	
	
	vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;

	//���� 
    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

		//����Ϊ��׼        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;


		
        while (front < back) {

            int sum = num[front] + num[back];
            
            // -8 -6 -3 -2 3 5 6
            
            
            //��̰�ı�֤����һ��ѡ�񵽣����ᷢ���������ĵ�  
            //�� sumС�ڻ�׼Ŀ�꣬����С�� 
            if (sum < target)
                front++;
			//sum���ڻ�׼Ŀ�꣬������� 
            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                
                
                //ȥ���ظ����� 
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }
		
		
		//�����ظ����� 
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