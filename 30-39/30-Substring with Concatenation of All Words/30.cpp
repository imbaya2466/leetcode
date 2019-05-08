#include <bits/stdc++.h>
using namespace std;

//失败的解 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(!words.size()||!s.size()){
            return ret;
        }
        int sum_target=0;
        for(auto i:words){
        	int xorword=0;
        	for(auto j:i){
        		xorword^=j;
			}
			sum_target+=xorword;
		}
		
		int length=words[0].size();
		int num=words.size();
		int f=length*num; 
		
		sort(words.begin(), words.end());
		words.erase(unique(words.begin(), words.end()), words.end());
		for(auto word:words){
			int position=0;
			while((position=s.find(word,position)) != string::npos)
    		{
    			if(position+f>s.size()){
    				break;
				}
      			int sum_now=0;
				for(int j=position;j<position+f;j+=length){
					int xorword=0;
					for(int k=j;k<j+length;k++){
						xorword^=s[k];
					}
					sum_now+=xorword;
				}
				if(sum_now==sum_target){
					ret.push_back(position);
				}
       			position++;
    		}
		}
		
		return ret;
        
    }
};


class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> indexes;
    if (!s.size() || !words.size()) {
      return indexes;
    }
    unordered_map<string, int> counts;
    for (string word : words)
      counts[word]++;
    int n = s.length(), num = words.size(), len = words[0].length();
    int f=len*num; 
    sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()), words.end());
	for(auto word:words){
		int position=0;
		while((position=s.find(word,position)) != string::npos)
    	{
    		if(position+f>s.size()){
    			break;
			}
     		unordered_map<string, int> seen;
      		int j = 0;
      		for (; j < num; j++) {
        		string word = s.substr(position + j * len, len);
        		if (counts.find(word) != counts.end()) {
          			seen[word]++;
          		if (seen[word] > counts[word])
            	break;
        		}
        		else break;
      		}
      		if (j == num) indexes.push_back(position);
       		position++;
    	}
	}
    return indexes;
  }
};

//远好于上俩种的方法 窗口滑动 
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (!S.size() || !L.size()) {
        return res;
         }
        unordered_map<string, int>wordTimes;//L中单词出现的次数
        for(int i = 0; i < L.size(); i++)
            if(wordTimes.count(L[i]) == 0)
                wordTimes.insert(make_pair(L[i], 1));
            else wordTimes[L[i]]++;
        int wordLen = L[0].size();
         
        
        for(int i = 0; i < wordLen; i++)
        {//为了不遗漏从s的每一个位置开始的子串，第一层循环为单词的长度
            unordered_map<string, int>wordTimes2;//当前窗口中单词出现的次数
            int winStart = i, cnt = 0;//winStart为窗口起始位置,cnt为当前窗口中的单词数目
            for(int winEnd = i; winEnd <= (int)S.size()-wordLen; winEnd+=wordLen)
            {//窗口为[winStart,winEnd)
                string word = S.substr(winEnd, wordLen);
                if(wordTimes.find(word) != wordTimes.end())
                {
                    if(wordTimes2.find(word) == wordTimes2.end())
                        wordTimes2[word] = 1;
                    else wordTimes2[word]++;
                     
                    if(wordTimes2[word] <= wordTimes[word])
                        cnt++;
                    else
                    {//当前的单词在L中，但是它已经在窗口中出现了相应的次数，不应该加入窗口
                     //此时，应该把窗口起始位置想左移动到，该单词第一次出现的位置的下一个单词位置
                        for(int k = winStart; ; k += wordLen)
                        {
                            string tmpstr = S.substr(k, wordLen);
                            wordTimes2[tmpstr]--;
                            if(tmpstr == word)
                            {
                                winStart = k + wordLen;
                                break;
                            }
                            cnt--;
                        }
                    }
                     
                    if(cnt == L.size())
                        res.push_back(winStart);
                }
                else
                {//发现不在L中的单词
                    winStart = winEnd + wordLen;
                    wordTimes2.clear();
                    cnt = 0;
                }
            }
        }
        return res;
    }
};


int main(){
	string s1="a";
	vector<string> word={"a","a"};
	Solution a;
	a.findSubstring(s1,word);
	
}
