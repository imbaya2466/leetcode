#include <bits/stdc++.h>
using namespace std;



//ÅÅÐòºó°¤¸ö¼ì²â 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    	vector<vector<int>> ret;
    	if(!intervals.size()){
    		return ret;
		}
		sort(intervals.begin(),intervals.end());
    	int a=intervals[0][0];
    	int b=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
        	if(b>=intervals[i][0]){
        		b=max(b,intervals[i][1]);
			}else{
				ret.push_back({a,b});
				a=intervals[i][0];
				b=intervals[i][1];
			}
		}
		ret.push_back({a,b});
		return ret;
    }
};


int main(){
	
}









