#include <bits/stdc++.h>
using namespace std;

//我的方法 
class Solution {
public:
    string getPermutation(int n, int k) {
    	int nj[]={0,1,2,6,24,120,720,5040,40320,362880};
        vector<int> num;
        k--;
        for(int i=n-1;i>0;i--){
        	num.push_back(k/nj[i]);
        	k=k%nj[i];
		}
		num.push_back(0);
		//用 0开始取 
		int arry[]={1,2,3,4,5,6,7,8,9};
		string ret;
		for(int i=0;i<num.size();i++){
			int j=num[i];
			for(int k=0;k<9;k++){
				if(arry[k]){					
					if(!j){
						ret.push_back(arry[k]+'0');
						arry[k]=0;
						break;
					}
					j--;
				}
			}
		}
		return ret;
    }
};

int main(){
	Solution s;
	cout<<s.getPermutation(4,2);
}


