#include <bits/stdc++.h>

using namespace std;

//�ҵĽⷨ   ������ʹ��sort������ 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++){
        	if(nums[i]<0){
        		i--;
        		continue;
			}
				
			if(nums[i]!=i){
				return i;
			}
		}
        return nums.size()+1;
    }
};

//���еĽⷨ
class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        //���ν����ַŵ���Ӧ��λ���ϣ�ԭ���Ļ�һֱ���û���ע����while���� 
        //���ﱣ֤�˷�Χ�ڵ�����һ����ŵ���Ӧ��λ�ã���������ַŵ�ǰ�滻λ���ɣ��Լ�Ҳ����� 
		//  1  2   5   7    4   6
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};

 




int main(){
	Solution s;
	vector<int> nums={1,2,0};
	cout<<s.firstMissingPositive(nums);
}
