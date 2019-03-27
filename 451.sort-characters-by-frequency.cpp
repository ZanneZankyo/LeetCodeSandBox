/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (55.24%)
 * Total Accepted:    86.5K
 * Total Submissions: 156.5K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */
class Solution {
public:
    string frequencySort(string s) {
        if(s.empty()){
            return "";
        }
        int frequencies[128];
        memset(frequencies, 0, sizeof(frequencies));
        for(char c : s){
            ++frequencies[c];
        }
        string result;
        result.reserve(s.size());
        int max = 0;
        int maxIndex = -1;
        while(true){
            for(int i = 0; i < 128; ++i){
                if(frequencies[i] > max){
                    max = frequencies[i];
                    maxIndex = i;
                }
            }
            if(maxIndex == -1 || max == 0){
                break;
            }
            else{
                result.append(string(max,maxIndex));
                frequencies[maxIndex] = 0;
            }
            max = 0;
            maxIndex = -1;
        }
        return result;
    }
};

