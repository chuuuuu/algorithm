// if he ask for 
// O(f(n)) time complexity and 
// O(g(n)) space complexity
// and it is hard to think, you can try specific condition first.

class Solution {
    public int[] productExceptSelf(int[] nums) {

        int[] ret = new int[nums.length];
        Arrays.fill(ret, 1);

        int tmp=1;        
        for(int i=0; i<nums.length; i++){
            if(i==0){
                tmp = 1;
            }
            else{
                tmp *= nums[i-1];
                ret[i] = tmp;
            }
        }
        
        tmp=1;
        for(int i=0; i<nums.length; i++){
            if(i!=0){
                tmp *= nums[nums.length-i];
                ret[nums.length-1-i] *= tmp;
            }
        }
        
        return ret;
    }
}