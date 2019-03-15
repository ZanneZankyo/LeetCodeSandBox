/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.13%)
 * Total Accepted:    263.1K
 * Total Submissions: 624.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int start = 0;
        while(start < height.size() - 1){
            int sum = 0;
            int end = start + 1;
            int max = 0;
            int maxI = -1;
            while(end < height.size() && height[end] < height[start]){
                sum += height[start] - height[end];
                if(height[end] > max){
                    max = height[end];
                    maxI = end;
                }
                end++;
            }
            if(end < height.size()){
                total += sum;
                start = end;
            }
            else if(start + 1 != maxI){
                sum = 0;
                for(int i = start + 1; i < maxI ;i++){
                    sum += max - height[i];
                }
                total += sum;
                start = maxI;
            }
            else
                start++;
            
        }
        return total;
    }
};

