#include <bits/stdc++.h>
using namespace std;

//¶¨Î»Á©µã 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int>  ret;
        int begin_x=0,begin_y=0;
        int end_x=matrix.size()-1,end_y=matrix.size()?matrix[0].size()-1:-1;
        while(true){
        	if(begin_x>end_x||begin_y>end_y){
        		break;
			}
			for(int i=begin_y;i<=end_y;i++){
				ret.push_back(matrix[begin_x][i]);
			}
			for(int i=begin_x+1;i<=end_x;i++){
				ret.push_back(matrix[i][end_y]);
			}
            if(begin_x==end_x||begin_y==end_y){
                break;
            }
			for(int i=end_y-1;i>=begin_y;i--){
				ret.push_back(matrix[end_x][i]);
			}			
			for(int i=end_x-1;i>begin_x;i--){
				ret.push_back(matrix[i][begin_y]);
			}			
			begin_x++;
			begin_y++;
			end_x--;
			end_y--;
		}
        return ret;
    }
};


int main(){
	
}
