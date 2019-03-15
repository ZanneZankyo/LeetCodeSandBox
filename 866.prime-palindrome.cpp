/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 *
 * https://leetcode.com/problems/prime-palindrome/description/
 *
 * algorithms
 * Medium (19.36%)
 * Total Accepted:    6K
 * Total Submissions: 30.9K
 * Testcase Example:  '6'
 *
 * Find the smallest prime palindrome greater than or equal to N.
 * 
 * Recall that a number is prime if it's only divisors are 1 and itself, and it
 * is greater than 1. 
 * 
 * For example, 2,3,5,7,11 and 13 are primes.
 * 
 * Recall that a number is a palindrome if it reads the same from left to right
 * as it does from right to left. 
 * 
 * For example, 12321 is a palindrome.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 6
 * Output: 7
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 11
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 13
 * Output: 101
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^8
 * The answer is guaranteed to exist and be less than 2 * 10^8.
 * 
 * 
 */
class Solution {
public:
    int nextPalindrome(int n){
        string str = to_string(n);
        if(str.size()%2 == 0)
        {
            int i1 = str.size()/2-1;
            int i2 = str.size()/2;
            char& c1 = str[i1];
            char& c2 = str[i2];
            if(c1 == '9' || c2 == '9')
            {
                bool carry = true;                
                do
                {
                    if(str[i1] == '9')
                        str[i1] = '0';
                    else
                    {
                        str[i1]++;
                        carry = false;
                    }
                    i1--;
                }while(i1 >= 0 && carry);
                if(i1<0 && carry)
                    str.insert(str.begin(),'1');
                for(int i = 0 ; i < str.size()/2;i++)
                    str[str.size()-1-i] = str[i];
            }
            else
            {
                c1++;
                c2++;
            }
        }
        else
        {
            int i1 = str.size()/2;
            char& c1 = str[i1];
            if(c1 == '9')
            {
                bool carry = true;                
                do
                {
                    if(str[i1] == '9')
                        str[i1] = '0';
                    else
                    {
                        str[i1]++;
                        carry = false;
                    }
                    i1--;
                }while(i1 >= 0 && carry);
                if(i1<0 && carry)
                    str.insert(str.begin(),'1');
                for(int i = 0 ; i < str.size()/2;i++)
                    str[str.size()-1-i] = str[i];
            }
            else
            {
                c1++;
            }
        }
        return atoi(str.c_str());
    }
    int closestPalindrome(int n){
        string str = to_string(n);
        for(int i = 0 ; i < str.size()/2;i++)
            str[str.size()-1-i] = str[i];
        return atoi(str.c_str());
    }
    bool isPalindrome(int n){
        if(n < 10)
            return true;
        string str = to_string(n);
        for(int i = 0; i<str.size()/2; i++)
            if(str[i] != str[str.size()-1-i])
                return false;
        return true;
    }
    bool isPrime(int n){
        if(n <= 1)
            return false;
        if(n == 2)
            return true;
        if( (n % 2) == 0 && n != 2)
            return false;
        for(int i = 3; i < n/2; i+=2)
        {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    int primePalindrome(int N) {
        if(N == 1)
            return 2;
        if(isPrime(N) && isPalindrome(N))
            return N;
        int r = closestPalindrome(N);
        while(!isPrime(r) || r < N)
            r = nextPalindrome(r);
        return r;
    }
};

