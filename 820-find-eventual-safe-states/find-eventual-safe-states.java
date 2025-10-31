class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> ans = new ArrayList<>();
        List<List<Integer>> adj = new ArrayList<>();
        int n = graph.length;
        int[] indegree = new int[n];

        for(int i=0; i < n; i++) adj.add(new ArrayList<>());
        
        for(int i=0; i < n; i++){
            for(int node : graph[i]){
                adj.get(node).add(i);
                indegree[i]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();

        for(int i=0; i < n; i++){
            if(indegree[i] == 0){
                q.add(i);
                ans.add(i);
            }
        }

        while(!q.isEmpty()){
            int node = q.poll();

            for(int l : adj.get(node)){
                indegree[l]--;

                if(indegree[l] == 0){
                    q.add(l);
                    ans.add(l);
                }
            }
        }

        Collections.sort(ans);

        return ans;
    }
}