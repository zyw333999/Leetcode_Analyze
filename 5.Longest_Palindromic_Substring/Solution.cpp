class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if(length < 2)
        {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        int same_i_j[1000][1000];
        memset(same_i_j, 0, sizeof(int)*1000*1000);
        for(int i = 0; i < length; ++i)
        {
            same_i_j[i][i] = 1;
            if(i < length -1 && s[i] == s[i+1])
            {
                same_i_j[i][i+1] = 1;
                begin  = i;
                maxLen = 2;
            }
        }
        
        for(int len = 3; len <= length; ++len)
        {
            for(int i = 0; i + len - 1 < length; ++i)
            {
                int j = i + len -1;
                if(s[i] == s[j] && same_i_j[i+1][j-1] == 1)
                {
                    same_i_j[i][j] = 1;
                    maxLen = len;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);
        
    }
};

/*
给定s，查找最长的回文子串：
1. 首先，如果s的长度 等于0或者1，那么直接返回s即可，因为自身也算是回文。
设置动规思想所需的存储空间same_i_j,用预判断s[i,j]是否是回文子串 (s[i,j]表示i到j位置的子串)
2. s的长度大于1，那么先判断s[i][i+1]是否是回文子串，并存储在same_i_j中。
3.回文子串为何可以使用动规的思想，因为如果s[i,j]是回文子串且s[i-1] == s[j+1]，那么是s[i-1, j+1]也就是回文串，因此same_i_j[i-1][j+1] = 1;
4.因此根据3所示的思想，从长度为3的开始更新same_i_j同时查找最长的回文子串即可，具体代码见cpp文件。
示例：
ababc：
  s[1,1]是回文子串，且s[0] == s[2],那么s[0,2]也是回文子串
  s[2,2]是回文子串，且s[1] == s[3],那么s[1,3]也是回文子串
*/