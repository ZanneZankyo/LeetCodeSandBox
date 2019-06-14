/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.74%)
 * Total Accepted:    494K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

/*

Test Case:

"babad"
"cbbd"
"aaaaaaaaaa"
""
"cccccccca"
"ccccccccca"
"abcda"

*/

#define TIME 1
#define SPACE 2
#define BIAS TIME

#if BIAS == TIME

class Solution {
public:

    int getMaxPalindromeEven(string const &s, int leftStartIndex){
        int maxLength = 0;
        int left = leftStartIndex;
        int right = leftStartIndex + 1;
        while(left >= 0 && right < s.size()){
            if(s[left] != s[right]){
                return maxLength;
            }
            --left;
            ++right;
            maxLength += 2;
        }
        return maxLength;
    }

    int getMaxPalindromeOdd(string const &s, int centerIndex){
        int maxLength = 1;
        int left = centerIndex - maxLength;
        int right = centerIndex + maxLength;
        while(left >= 0 && right < s.size()){
            if(s[left] != s[right]){
                return maxLength;
            }
            --left;
            ++right;
            maxLength += 2;
        }
        return maxLength;
    }
    
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        int maxOddLength = 1;
        int maxOddIndex = 0;

        int maxEvenLength = 0;
        int maxEvenIndex = 0;

        for(int i = 0; i < s.size(); ++i){
            if(i+2 < s.size() && s[i] == s[i+2]){
                int palindromeLength = getMaxPalindromeOdd(s, i+1);
                if(palindromeLength > maxOddLength){
                    maxOddLength = palindromeLength;
                    maxOddIndex = i + 1;
                }
            }
            if(i+1 < s.size() && s[i] == s[i+1]){
                int palindromeLength = getMaxPalindromeEven(s, i);
                if(palindromeLength > maxEvenLength){
                    maxEvenLength = palindromeLength;
                    maxEvenIndex = i;
                }
            }
        }

        //cout<<maxOddIndex<<':'<<maxOddLength<<','<<maxEvenIndex<<':'<<maxEvenLength<<'|';

        if(maxOddLength > maxEvenLength){
            return s.substr(maxOddIndex - maxOddLength/2, maxOddLength);
        }
        else{
            return s.substr(maxEvenIndex - maxEvenLength/2 + 1, maxEvenLength);
        }

        

    }

};

#endif


#if BIAS == SPACE

class Solution {
public:
    bool isPalindrome2(const string& s)
    {
        if(s.size() == 1)
            return true;
        int i,j;
        if((s.size() & 1) == 0)
        {
            i = s.size() / 2 - 1;
            j = s.size() / 2;
        }
        else
        {
            i = j = s.size() / 2;
        }
        
        for(; i>=0 && j<s.size(); i--,j++)
            if(s[i]!=s[j])
                break;
        return i == -1 && j == s.size();
    }
    bool isPalindrome(const string& s, int from, int to)
    {
        int size = to - from + 1;
        if(size == 1)
            return true;
        int i,j;
        if((size & 1) == 0)
        {
            i = size / 2 - 1 + from;
            j = size / 2 + from;
        }
        else
        {
            i = j = size / 2 + from;
        }
        
        for(; i>=from && j<=to; i--,j++)
            if(s[i]!=s[j])
                break;
        return i == from-1 && j == to+1;
    }
    string longestPalindrome(string s) {
        int from = 0;
        int to = 0;
        string result;
        int maxLen = 0;
        while(from < s.size())
        {
            to = s.size() - 1;
            while(to >= from)
            {
                int len = to - from + 1;
                if(len > maxLen)
                {
                    if(isPalindrome(s,from,to))
                    {
                        maxLen = len;
                        result = s.substr(from, len);
                        break;
                    }
                }
                to--;
            }
            from++;
        }
        return result;
    }
};


#endif
