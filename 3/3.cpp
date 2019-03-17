
手动找的话，字符从前往后看，当发现重复的字符时，将开始的字符设置为重复的第一次出现之后。每次记录看到最长的子串


将字符的asc作为下标。内存当前出现的位置。
遍历string。如果字符在之前出现过。更新start。每次都应该记录字符的出现位置，并计算位置-start记录最长






int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }