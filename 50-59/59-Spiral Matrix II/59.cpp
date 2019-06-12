#include <bits/stdc++.h>
using namespace std;

//bx by
//
//		ex ey
//ÎÒµÄ 
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> ret(n,vector<int>(n));
        int bx=0,by=0;
        int ex=n-1,ey=n-1;
        int num=1;
    	while(bx<=ex){
    		for(int i=by;i<=ey;i++){
    			ret[bx][i]=num++;
			}
			for(int i=bx+1;i<=ex;i++){
    			ret[i][ey]=num++;
			}
			for(int i=ey-1;i>=by;i--){
				ret[ex][i]=num++;
			}
			for(int i=ex-1;i>bx;i--){
				ret[i][by]=num++;
			}
			bx++;
			by++;
			ex--;
			ey--;
		}
		return ret;
    }
};



int main(){
	
}
