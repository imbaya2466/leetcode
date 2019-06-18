#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	int sum=0;
    	int space=0;
    	int beg=0;
    	vector<string> ret;
        for(int i=0;i<words.size();i++){
        	if(sum+words[i].size()<maxWidth){
        		sum+=words[i].size()+1;
        		space++;
			}else if(sum+words[i].size()==maxWidth){
				sum+=words[i].size();
			}else{
				space+=maxWidth-sum;
				string add;
				int word_space_num;
				int add_space_word;
				if(i-beg-1){
					word_space_num=space/(i-beg-1);
					add_space_word=space%(i-beg-1)+beg;
				}else{
					word_space_num=space;
					add_space_word=beg;
				}
				
				for(int j=beg;j<i-1;j++){
					if(j<add_space_word){
						words[j].insert(words[j].end(),word_space_num+1,' ');
					}else{
						words[j].insert(words[j].end(),word_space_num,' ');
					}
					add+=words[j];
				}
				add+=words[i-1];
				if(add.size()!=maxWidth){
					add.insert(add.end(),maxWidth-add.size(),' ');
				}
				ret.push_back(add);
				beg=i;
				i--;
				sum=0;
				space=0;
			}
		}
		if(sum){
			string add;
			for(int i=beg;i<words.size()-1;i++){
				add+=words[i]+' ';
			}
			add+=words[words.size()-1];
			if(add.size()!=maxWidth){
				add.insert(add.end(),maxWidth-add.size(),' ');
			}
			ret.push_back(add);
		}
		
		return ret;
    }
};

//´óÀÐµÄ 
vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    for(int i = 0, k, l; i < words.size(); i += k) {
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            l += words[i+k].size();
        }
        string tmp = words[i];
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
    }
    return res;
}




int main(){
	vector<string> ls={"What","must","be","acknowledgment","shall","be"};
	Solution s;
	s.fullJustify(ls,16);
}
