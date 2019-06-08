
#include <bits/stdc++.h>

using namespace std;


//�ҵĲ���෽�� 
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1;
        for(int i= num1.size()-1;i>=0;i--){
        	n1.push_back(num1[i]-'0');
		}
		
		vector<int> ret; 
		int mul=0;
		int add_next=0;
		for(int i=num2.size()-1;i>=0;i--){
			
			int mul_num=num2[i]-'0';
			add_next=0;
			for(int j=0;j<n1.size();j++){
				int mul_once=mul_num*n1[j]+add_next;
				add_next=mul_once/10;
				int add_now=mul_once%10;
				if(j+mul==ret.size()){
					ret.push_back(0);
				}
				int add_ret=ret[j+mul]+add_now;
				ret[j+mul]=add_ret%10;
				add_next+=add_ret/10;
			}
			if(add_next!=0){
				//ÿ�����һλ��Ȼ�����10���� 
				ret.push_back(add_next);
			}
			mul++;
		}
		
		for(int i=ret.size()-1;i>0;i--){
			if(ret[i]!=0){
				break;
			}
			ret.erase(ret.begin()+i);
		}
		string ret_str;
		for(int i=ret.size()-1;i>=0;i--){
			ret_str.push_back('0'+ret[i]);
		}
		
		return ret_str;
    }
};
//���еļ�෽��
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');//һ���㹻
		 
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');  //�����µ��ۼ�ֵһ�����    i+j+1����ȷ�� 
                ans[i + j + 1] = sum % 10 + '0'; //��λֱ�Ӽ� 
                ans[i + j] += sum / 10; //��λֱ�Ӽ� 
            }
        }
        //ȥ0 
        for (int i = 0; i < m + n; i++) {
            if (ans[i] != '0') {
                return ans.substr(i);
            }
        }
        return "0";
    }
};





int main(){
	Solution s;
	cout<<s.multiply("5463","0");
}
