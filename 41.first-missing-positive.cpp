/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (42.40%)
 * Likes:    18279
 * Dislikes: 1979
 * Total Accepted:    1.7M
 * Total Submissions: 4M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array nums. Return the smallest positive integer
 * that is not present in nums.
 * 
 * You must implement an algorithm that runs in O(n) time and uses O(1)
 * auxiliary space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,0]
 * Output: 3
 * Explanation: The numbers in the range [1,2] are all in the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,4,-1,1]
 * Output: 2
 * Explanation: 1 is in the array but 2 is missing.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [7,8,9,11,12]
 * Output: 1
 * Explanation: The smallest positive integer 1 is missing.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (0 < nums[i] && nums[i] < nums.size() 
            && nums[i] != i + 1 
            && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
#if 0 // TLE
        int Max = nums[0];
        int Min = 2;
        for (int n : nums) {
            if (n > 0) {
                Max = max(n, Max);
                Min = min(n, Min);
            }
        }
        if (Min > 1) {
            return 1;
        }

        
        int c = Min;
        while(true) {
            bool hit = false;
            for (int n : nums) {
                if (n == c) {
                    hit = true;
                    break;
                }
            }
            if (hit) {
                ++c;
            }
            else {
                break;
            }
        }
        return c;
#endif
    }
};
#if 0
#include <iostream>
void main() {
    Solution s;
    vector<int> v({3,4,-1,1});
    cout << s.firstMissingPositive(v);
}
#endif
// @lc code=end

