#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {     
        stack<int> st;
        for(int i=0;i<s.size();i++){
        	if(st.empty()){
        		st.push(i);
			}
			else{
				if(s[st.top()]=='('&&s[i]==')'){
					st.pop();
				}else{
					st.push(i);
				}
			}
		}
        int max=0;
        int k=s.size();
        int j=0;
        while(!st.empty()){
        	j=st.top();
        	if(k-j>max){
        		max=k-j;
			}
			k=j;
			st.pop();
		}
		if(k+1>max){
        	max=k+1;
		}
		return max-1;
    }
};
int main(){
	Solution s;
	s.longestValidParentheses("(()");
}
