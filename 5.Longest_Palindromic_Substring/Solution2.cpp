class Solution {
public:
    string longestPalindrome(string s)
     {
        string newS = "$#";
        for (int i=0;i<s.size();i++) //首先构造出新的字符串
        {
            newS += s[i];
            newS += '#';
        }
        int rd[2002];//记录构造的新串的最大回文串长度
        memset(rd, 0, 2000*sizeof(int));
        int pos = 0, mx = 0;
        int start = 0, maxLen = 0;
        for (int i = 1; i < newS.size(); i++) 
        {
            rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
			//这里首先判断i是否在最大长度回文子串的边界内部（右边边界为mx，中心为pos），
			//1.若是不在，则rd[i] = 1;
			//2.若是在，则首先一定是比边界的位置减去i的长度要小，其次应该是等于i与pos位置对称的回文子串长度相等
			
            while (i+rd[i]<newS.size() && i-rd[i]>0 && newS[i + rd[i]] == newS[i - rd[i]])
			{//这里就是如果i+rd[i]的长度依然是回文子串，那么继续往前遍历
				rd[i]++;
			}
            if (i + rd[i] > mx) //如果最右侧端点大于mx,则更新pos和mx
            {
                pos = i;
                mx = i + rd[i];
            }
            if (rd[i] - 1 > maxLen) //跟新起始位置以及最大长度
            {
                start = (i - rd[i]) / 2;
                maxLen = rd[i] - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
/*
解析位于源代码中
算法原理参考网址：https://www.jianshu.com/p/6db44081a155
具体来说就是

示例：ababc
新的字符串
$#a#b#a#b#c#

rd[1] = 1; pos = 1; mx = 2;
rd[2] = 1;执行while;rd[2] = 2; pos = 2, mx = 4;
rd[3] = 1;
rd[4] = 1;while end，rd[4] = 3, pos = 4, mx = 7;
rd[5] = 1;
rd[6] = 1;while end, rd[6] = 3, pos = 6, mx = 9;
....






*/