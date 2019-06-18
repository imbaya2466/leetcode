#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int i=digits.size()-1;
        while(1){
        	if(i<0){
        		digits.insert(digits.begin(),1);
        		break;
			}
        	if(digits[i]+1==10){
        		digits[i]=0;
        		i--;
			}else{
				digits[i]+=1;
				break;
			}
		}
		return digits;
    }
};




int main(){
	
}
