

第五题
求最大回文字串。

最慢暴力:
class Solution {
public:
    bool ishw(string &s,int i,int j)
    {
        for(;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int i=0,j=0;
        int max=1;
        int mj=0,mi=0;
        for(;i<s.size();i++)
        {
            for(j=i;j<s.size();j++)
            {
                if(ishw(s,i,j))
                {
                    if(j-i+1>max)
                    {
                        max=j-i+1;
                        mj=j;
                        mi=i;
                    }
                }
            }
        }
        
        return s.substr(mi,max);
        
    }
};