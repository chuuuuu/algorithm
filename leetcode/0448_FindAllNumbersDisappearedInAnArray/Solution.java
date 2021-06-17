
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {


        /*
        algorithm below using extra memory
        space complexity is O(n)
        */
        // boolean[] isExist = new boolean[nums.length];
        // Arrays.fill(isExist, false);
        // for(int i=0; i<nums.length; i++){
        //     isExist[nums[i]-1] = true;
        // }
        
        // List<Integer> ret = new ArrayList();
        // for(int i=0; i<nums.length; i++){
        //     if(!isExist[i]){
        //         ret.add(i+1);
        //     }
        // }
        
        // return ret;

        /*
        algorithm below doesnt using extra memory
        space complexity is O(1)
        */
        for(int i=0; i<nums.length; i++){
            int idx = nums[i];
            if(idx < 0){
                idx *= -1;
            }
            idx -= 1;
            
            if(nums[idx] > 0){
                nums[idx] *= -1;
            }
        }
        
        List<Integer> ret = new ArrayList();
        for(int i=0; i<nums.length; i++){
            if(nums[i] > 0){
                ret.add(i+1);
            }
        }
        
        return ret;


    }
}