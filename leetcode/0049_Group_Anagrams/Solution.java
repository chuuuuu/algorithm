class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs.length == 0){
            return new ArrayList();
        }
        
        Map<String, List> ret = new HashMap<String, List>();
        int[] count = new int[26];
        for(String s: strs){
            Arrays.fill(count, 0);
            for(char c: s.toCharArray()){
                count[c - 'a']++;
            }
            
            String key = "";
            for(int i=0; i<26; i++){
                key += "#";
                key += count[i];
            }
            
            if(!ret.containsKey(key)){
                ret.put(key, new ArrayList());
            }
            ret.get(key).add(s);

        }
        
        return new ArrayList(ret.values());
    }
}