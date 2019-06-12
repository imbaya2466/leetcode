#include <bits/stdc++.h>
using namespace std;

//我的方法 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int a=-1,b=-1;
        bool flag=false;
        if(!intervals.size()){
        	ret.push_back(newInterval);
        	return ret;
		}
        for(int i=0;i<intervals.size();i++){
            if(!flag&&intervals[i][1]>=newInterval[0]){
            	flag=true;
                if(newInterval[1]<intervals[i][0]){
                    ret.push_back(newInterval);
                }else{
                	a=min(newInterval[0],intervals[i][0]);
                	i--;
                	continue;
				}
            }
            if(a!=-1&&intervals[i][1]>=newInterval[1]){
                if(newInterval[1]<intervals[i][0]){
                	b=newInterval[1];
                	ret.push_back({a,b});
                	a=-1;
				}else{
					b=max(newInterval[1],intervals[i][1]);
					ret.push_back({a,b});
					a=-1;
					continue;
				}
            }
            if(a!=-1){
            	continue;
			}
            ret.push_back(intervals[i]);
        }
        
        if(a!=-1){
        	ret.push_back({a,newInterval[1]});
        	a=-1;
		}
        
        if(!flag){
        	ret.push_back(newInterval);
		}
        
        return ret;
    }
};


//更好的方法 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int index = 0;
        while(index < intervals.size() && intervals[index][1] < newInterval[0]){
            res.push_back(intervals[index++]);
        }
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        res.push_back(newInterval);
        while(index < intervals.size()){
            res.push_back(intervals[index++]);
        }
        return res;
    }
};

//[1,2],[3,5],[6,7],[8,10]
//     1  2     
//          

int main(){
	
}
