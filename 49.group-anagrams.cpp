/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (45.13%)
 * Total Accepted:    304.3K
 * Total Submissions: 674.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<size_t> sortedHash;
        sortedHash.reserve(strs.size());
        vector<size_t> setHash;
        hash<string> hashFunc;
        for(string str : strs){
            sort(str.begin(), str.end());
            sortedHash.push_back(hashFunc(str));
        }
        for(int i = 0 ; i < strs.size(); ++i){
            bool belongsToAnySet = false;
            for(int j = 0 ; j < setHash.size(); ++j){
                if(setHash[j] == sortedHash[i]){
                    belongsToAnySet = true;
                    result[j].push_back(strs[i]);
                }
            }
            if(!belongsToAnySet){
                setHash.push_back(sortedHash[i]);
                result.push_back(vector<string>());
                result[result.size() - 1].push_back(strs[i]);
            }
        }
        return result;
    }
};

