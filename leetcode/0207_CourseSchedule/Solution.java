// main idea is topological sort
// when the graph is not DAG, it cannot be sorted by topSort
// topological sort is cannot be done without the indegreeMap
// if you want to do a topological sort with only BFS, then it won't work if
// 1->3, 2->4, 4->3

// time complexity O(V + E)
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // prerequisites[i][1] -> prerequisites[i][0]
        //map[i]: the courses needed to finish first.
        List<List<Integer>> map = new ArrayList<List<Integer>>();
        List<Integer> indegs = new ArrayList<Integer>();
        for(int i=0; i<numCourses; i++){
            map.add(new ArrayList<Integer>());
            indegs.add(0);
        }
        
        for(int i=0; i<prerequisites.length; i++){
            indegs.set(prerequisites[i][1], indegs.get(prerequisites[i][1])+1);
            map.get(prerequisites[i][0]).add(prerequisites[i][1]);
        }
        
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=0; i<numCourses; i++){
            if(indegs.get(i) == 0){
                q.offer(i);
            }
        }
        
        List<Integer> sortedCourses = new ArrayList<Integer>();
        while(!q.isEmpty()){
            Integer course = q.poll();
            sortedCourses.add(course);
            for(int i=0; i<map.get(course).size(); i++){
                int idx = map.get(course).get(i);
                indegs.set(idx, indegs.get(idx)-1);
                if(indegs.get(idx)==0){
                    q.offer(idx);
                }
            }
        }
                
        return (sortedCourses.size() == numCourses);
    }
}