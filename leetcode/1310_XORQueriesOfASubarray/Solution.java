// import java.util.Arrays;

class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int lenArr = arr.length;
        int[] rets = new int[lenArr];
        for(int i=0; i<lenArr; i++){
            if(i == 0){
                rets[0] = arr[0];
            }
            else{
                rets[i] = rets[i-1] ^ arr[i];
            }
        }
        // System.out.println(Arrays.toString(rets));
        
        int lenQ = queries.length;
        int[] ret = new int[lenQ];
        for(int i=0; i<lenQ; i++){
            ret[i] = rets[queries[i][1]];
            if(queries[i][0] != 0){
                ret[i] = ret[i] ^ rets[queries[i][0]-1];
            }
        }
        // System.out.println(Arrays.toString(ret));
        
        return ret;
    }
}