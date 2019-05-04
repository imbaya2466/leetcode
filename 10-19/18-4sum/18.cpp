#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& num, int target) {
    	
    vector<vector<int> > res;
	//���� 
    std::sort(num.begin(), num.end());

	
    for (int i = 0; i < num.size(); i++) {
	for(int j=i+1;j<num.size();j++){
		//����Ϊ��׼        
        int targetn = target-(num[i]+num[j]);
        int front = j + 1;
        int back = num.size() - 1;
        while (front < back) {
            int sum = num[front] + num[back];
            // -8 -6 -3 -2 3 5 6
            //��̰�ı�֤����һ��ѡ�񵽣����ᷢ���������ĵ�  
            //�� sumС�ڻ�׼Ŀ�꣬����С�� 
            if (sum < targetn)
                front++;
			//sum���ڻ�׼Ŀ�꣬������� 
            else if (sum > targetn)
                back--;
            else {
                vector<int> triplet(4, 0);
                triplet[0] = num[i];
                triplet[1] = num[j];
                triplet[2] = num[front];
                triplet[3] = num[back];
                res.push_back(triplet);
                
                //��++���ұز�ƥ�䣬���һ�ζ�����û������ 
                do{front++;}while(num[front]==num[front-1]&&front<back);
                do{back--;}while(num[back]==num[back+1]&&front<back);
                
            }
            
        }
		//�����ظ����� 
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






