/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 *
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (27.50%)
 * Total Accepted:    20.7K
 * Total Submissions: 75.4K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Given two strings A and B of lowercase letters, return true if and only if
 * we can swap two letters in A so that the result equals B.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        int numOfDiff = 0;
        int diff1 = -1;
        int diff2 = -1;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i]){
                numOfDiff++;
                if(diff1 == -1){
                    diff1 = i;
                }
                else{
                    diff2 = i;
                }
            }
        }
        if(numOfDiff == 2){
            if(A[diff1] == B[diff2] && A[diff2] == B[diff1]){
                return true;
            }
        }
        else if(numOfDiff == 0){
            char c[26];
            for(int i = 0; i < 26; i++){
                c[i] = 0;
            }
            for(int i = 0; i < A.size(); i++){
                c[A[i]-'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(c[i] >= 2)
                    return true;
            }
        }
        return false;
    }
};

