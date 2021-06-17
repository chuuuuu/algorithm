// sol1: quick select, since i only need to do sort in one side
// it'll only takes O(n)

// however, using cyclic sort is a better way!

class Solution {
    public int firstMissingPositive(int[] nums) {
        for(int i=0; i<nums.length; i++){
            while(true){
                if(nums[i]<=0 || nums[i]>nums.length){
                    break;
                }
                if(nums[i]==i+1){
                    break;
                }
                
                int idx = nums[i]-1;
                if(nums[idx]==idx+1){
                    nums[i] = 0;
                }
                else{
                    int tmp = 0;
                    tmp = nums[i];
                    nums[i] = nums[idx];
                    nums[idx] = tmp;
                }
            }
        }
        
        for(int i=0; i<nums.length; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        
        return nums.length+1;
    }
}