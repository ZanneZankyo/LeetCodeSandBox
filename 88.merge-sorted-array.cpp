/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (34.98%)
 * Total Accepted:    335.5K
 * Total Submissions: 958.9K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void Insert(vector<int>& v, int index, int value){
        for(int i = v.size() - 2; i>=index; i--){
            v[i+1] = v[i];
        }
        v[index] = value;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = 0;
        int i2 = 0;
        while(i1 < m && i2 < n){
            if(nums2[i2] < nums1[i1]){
                Insert(nums1, i1, nums2[i2]);
                //nums1.insert(nums1.begin() + i1, nums2[i2]);
                i2++;
                m++;
            }
            else
                i1++;
        }
        while(i2 < n){
            nums1[m++] = nums2[i2++];
        }
    }
};

