class Solution {

    public boolean topo(int n, List<List<Integer>> adj, int[] indegree){
        
        Queue<Integer> q = new LinkedList<>();

        for(int i=0; i < n; i++){
            if(indegree[i] == 0){
                q.add(i);
            }
        }

        int count = 0;

        while(!q.isEmpty()){
            int node = q.poll();
            count++;

            for(int l : adj.get(node)){
                indegree[l]--;

                if(indegree[l] == 0){
                    q.add(l);
                }
            }
        }

        return count == n;
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {

        List<List<Integer>> adj = new ArrayList<>();
        int n = numCourses;
        int[] indegree = new int[n];
        for(int i=0; i < n; i++) adj.add(new ArrayList<>());

        for(int[] edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj.get(v).add(u);
            indegree[u]++;
        }

        return topo(n, adj, indegree);
    }
}