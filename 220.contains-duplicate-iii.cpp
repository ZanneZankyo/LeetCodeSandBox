/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    int getBucketId(int num) {
        if (num >= 0) {
            return num / diffPlusOne;
        }
        else {
            return (num + 1) / diffPlusOne - 1;
        }
    }
#if 1 // Time Limit Exceeded
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        diffPlusOne = valueDiff + 1;
        bucket.clear();
        for (int i = 0; i < nums.size(); ++i) {
            int bucketId = getBucketId(nums[i]);
            auto found = bucket.find(bucketId);
            if (found != bucket.end()) {
                return true;
            }
            found = bucket.find(bucketId + 1);
            if (found != bucket.end()) {
                if (abs(found->second - nums[i]) <= valueDiff) {
                    return true;
                }
            }
            found = bucket.find(bucketId - 1);
            if (found != bucket.end()) {
                if (abs(found->second - nums[i]) <= valueDiff) {
                    return true;
                }
            }
            bucket.insert({bucketId, nums[i]});
            if (i - indexDiff >= 0) {
                int bucketToRemove = getBucketId(nums[i - indexDiff]);
                bucket.erase(bucketToRemove);
            }
        }
        return false;
    }
#else // Time Limit Exceeded
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for (int i = 0; i < nums.size(); ++i){
            for (int j = i + 1; j <= i + indexDiff && j < nums.size(); ++j){
                if (abs(nums[i] - nums[j]) <= valueDiff) {
                    cout << i << ',' << j << endl;
                    return true;
                }
            }
        }
        return false;
    }
#endif
private:
    long diffPlusOne;
    unordered_map<int, int> bucket;
};
// @lc code=end

