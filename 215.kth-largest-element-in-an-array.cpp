/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (46.38%)
 * Total Accepted:    337.7K
 * Total Submissions: 727.1K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#if 0 // 17.67% runtime O(nk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = 0;
        for(n = 0; n < k; ++n){
            int maxIndex = n;
            int max = nums[n];
            for(int i = n; i < nums.size(); ++i){
                if(nums[i] > max){
                    max = nums[i];
                    maxIndex = i;
                }
            }
            int temp = nums[n];
            nums[n] = max;
            nums[maxIndex] = temp;
        }
        return nums[k-1];
    }
};
#endif

#if 0 //83.93% runtime O(nklogk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int const &num : nums){
            pq.push(num);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
#endif

#if 1 //98.02% runtime
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};
#endif
