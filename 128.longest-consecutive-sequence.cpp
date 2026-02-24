/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (47.00%)
 * Likes:    22714
 * Dislikes: 1228
 * Total Accepted:    3.2M
 * Total Submissions: 6.7M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,0,1,2]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        s.clear();
        s.insert(nums.begin(), nums.end());
        int Max = 0;
        for (int n : s) {
            if (!s.contains(n-1)) {
                int len = 1;
                int x = n + 1;
                while (s.contains(x)) {
                    ++x;
                    ++len;
                }
                Max = max(len, Max);
                if (Max > nums.size() / 2) {
                    break;
                }
            }
        }
        return Max;
    }
private:
    unordered_set<int> s;
};
// @lc code=end

