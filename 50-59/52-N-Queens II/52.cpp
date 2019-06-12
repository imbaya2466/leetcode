
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool suit(vector<string> &map,int x,int y,int n){
		for(int i=0;i<n;i++){
			if(map[i][y]=='Q'){
				return false;
			}
		}
		for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--){
			if(map[i][j]=='Q'){
				return false;
			}
		}
		for(int i=x-1,j=y+1;i>=0&&j<n;i--,j++){
			if(map[i][j]=='Q'){
				return false;
			}
		}
		return true;
	}
	void dfs(vector<vector<string>> &ret,vector<string> &map,int row,int n){
		if(row==n){
			ret.push_back(map);
			return;
		}
		for(int i=0;i<n;i++){
			if(suit(map,row,i,n)){
				map[row][i]='Q';
				dfs(ret,map,row+1,n);
				map[row][i]='.';
			}
		}
	}
    int totalNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> map(n, string(n, '.'));
        dfs(ret,map,0,n);
        return ret.size();
    }
};

/*
class Solution {
public:
    int totalNQueens(int n) {
		int ret[]={1,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596};
		return ret[n];
    }
};

*/

int main(){
	Solution s;
	for(int i=0;i<50;i++){
		cout<<s.totalNQueens(i)<<",";
	}
}
