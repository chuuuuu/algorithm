public class Main {
  // we cannot take static and params away
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1, 3, 4, 8};
        int[][] queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
        sol.xorQueries(arr, queries);
  }
}