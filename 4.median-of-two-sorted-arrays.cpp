/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.68%)
 * Total Accepted:    393.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;
        int i2 = 0;
        
        vector<int> nums;
        nums.reserve(nums1.size()+nums2.size());
        
        while(i1 < nums1.size() || i2 < nums2.size())
        {
            int val;
            if(i1 >= nums1.size())
                val = nums2[i2++];
            else if(i2 >= nums2.size())
                val = nums1[i1++];
            else if(nums1[i1] < nums2[i2])
                val = nums1[i1++];
            else
                val = nums2[i2++];
            nums.push_back(val);
        }
        
        int maxIndex = nums.size() - 1;
        if(nums.size() & 1 == 1)
            return nums[maxIndex / 2];
        else
            return (nums[maxIndex / 2] + nums[(maxIndex / 2) + 1]) / 2.f;
            
    }
};

