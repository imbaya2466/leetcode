#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
        int myAtoi(string str) {
        for(char c:str){
            if(isalpha(c))  return 0;
            if(isdigit(c))  break;
        }
        try{ 
            int res = stoi(str);
            return res;
        }
        catch(std::invalid_argument& e){
            return 0;
        }
        catch(std::out_of_range& e){
            //search for negative sign
            return (str.find(string(1,'-'))!=string::npos)?-2147483648:2147483647;
        }
    }
};


int main()
{
	string s;
	cin.getline(s,128);
	Solution a;
	cout<<a.myAtoi(s);
	
}
