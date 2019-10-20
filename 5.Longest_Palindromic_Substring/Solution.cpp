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