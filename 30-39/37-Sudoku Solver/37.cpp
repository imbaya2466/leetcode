#include <bits/stdc++.h>
using namespace std;


//ֱ�ӱ���dfs 
class Solution {
public:
	bool map1[9][9]={0}; 
	bool map2[9][9]={0}; 	
	bool map3[9][9]={0}; 	
	
	
	bool solve(int count,vector<vector<char>>& board){
		//��ɨ�赽����н� 
		if(count>=81){
			return true;
		}
		//��countɨ�赽��� 
		for(int i=count;i<81;i++){
			int ii=i/9;//�� 
			int jj=i%9;//�� 
			if(board[ii][jj]!='.'){
				continue;
			}
			else{
				for(int k=0;k<9;k++){//�ҷ��Ǹ����� 
					if(map1[ii][k]||map2[jj][k]||map3[(ii/3)*3+jj/3][k]){
						continue;
					}
					else{
						board[ii][jj]=k+49;
						map1[ii][k]=true;
						map2[jj][k]=true;
						map3[(ii/3)*3+jj/3][k]=true;
						if(solve(ii*9+jj+1,board)) return true;
						board[ii][jj]='.';
						map1[ii][k]=0;
						map2[jj][k]=0;
						map3[(ii/3)*3+jj/3][k]=0;
					}
				}
				return false;
			}
		}
		return true;
	}
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
        	for(int j=0;j<9;j++){
        		if(board[i][j]!='.'){
        			int num=board[i][j]-'0'-1;
        			map1[i][num]=true;
        			map2[j][num]=true;
        			map3[(i/3)*3+j/3][num] = true;
				}
			}
		}
        
        solve(0,board);
        
    }
};




int main(){
	
}
