class Solution {
    public int maxProduct(int[] nums) {
        // max[i]: the maximum product if i is the last emt        
        int[] maxs = new int[nums.length];
        // max[i]: the minimum product if i is the last emt
        int[] mins = new int[nums.length];
        
        int ret=nums[0];
        for(int i=0; i<nums.length; i++){
            if(i==0){
                maxs[i] = nums[i];
                mins[i] = nums[i];
            }
            else{
                maxs[i] = this.max(maxs[i-1] * nums[i], mins[i-1] * nums[i]);
                maxs[i] = this.max(maxs[i], nums[i]);
                mins[i] = this.min(maxs[i-1] * nums[i], mins[i-1] * nums[i]);
                mins[i] = this.min(mins[i], nums[i]);
                ret = this.max(maxs[i], ret);
            }
        }
        
        return ret;
    }
    
    private int max(int x, int y){
        if(x > y){
            return x;
        }
        
        return y;
    }

    private int min(int x, int y){
        if(x < y){
            return x;
        }
        
        return y;
    }

}