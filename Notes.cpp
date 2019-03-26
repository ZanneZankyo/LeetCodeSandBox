class Notes{
    #define INT_MAX 0x7FFFFFFF
    #define INT_MIN 0x80000000
    int binarySearch(vector<int>& nums ,int startIndex, int endIndex, int target){
        int near = startIndex;
        int far = endIndex;
        if(nums[near] == target)
            return near;
        if(nums[far] == target)
            return far;
        int half = (near + far) / 2;
        do{
            int n = nums[half];
            if(n == target){
                return half;
            }
            else if(n < target){
                near = half + 1;
            }
            else{
                far = half;
            }
            half = (near + far) / 2;
        }while(near < far);
        return -1;
    }
};