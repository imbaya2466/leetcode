
#include <bits/stdc++.h>
using namespace std;

//dfs
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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> map(n, string(n, '.'));
        dfs(ret,map,0,n);
        return ret;
    }
};


//更好的方法是使用3个hashset存储哪一行、那一列被用了
//斜着使用i-j的值表示即可，可直接存于 hashset
























int main(){
	
}
