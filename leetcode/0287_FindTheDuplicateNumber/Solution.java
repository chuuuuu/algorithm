// it can also be done by fast/slow pointer

class Solution {
    public int findDuplicate(int[] nums) {
        int ret = 0;
        for(int i=0; i<nums.length; i++){
            int idx = nums[i];
            if(idx < 0){
                idx *= -1;
            }
            idx -= 1;
            
            if(nums[idx] < 0){
                ret = nums[i];
                if(ret < 0){
                    ret *= -1;
                }
                break;
            }
            else{
                nums[idx] *= -1;
            }
        }
        
        return ret;
    }
}