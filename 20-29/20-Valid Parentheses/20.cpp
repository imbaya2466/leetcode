#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	inline bool Pair(char left,char right)
	{
		switch(left){
			case '(':{
				if(right==')') return true;
				break;
			}
			case '[':{
				if(right==']') return true;
				break;
			}
			case '{':{
				if(right=='}') return true;
				break;
			}
		}
		return false;
	}
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.size();i++){
        	if(st.empty()){
        		st.push(s[i]);
			}
			else{
				if(Pair(st.top(),s[i])){
					st.pop();
				}else{
					st.push(s[i]);
				}
			}
		}
        return st.empty();
};

// better
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};


int main()
{
	
}
