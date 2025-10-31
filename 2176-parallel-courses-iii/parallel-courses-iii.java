class Solution {
    public int minimumTime(int n, int[][] relations, int[] time) {
        List<List<Integer>> adj = new ArrayList<>();
        int[] indegree = new int[n + 1];
        for(int i=0; i <= n; i++) adj.add(new ArrayList<>());

        for(int[] arr : relations){
            int u = arr[0];
            int v = arr[1];

            adj.get(u).add(v);
            indegree[v]++;
        }

        int[] waitime = new int[n + 1];
        Queue<Integer> q = new LinkedList<>();

        int maxtime = 0;

        for(int i=1; i <= n; i++){
            if(indegree[i] == 0){
                q.add(i);
                waitime[i] = time[i - 1];
                maxtime = Math.max(maxtime, waitime[i]);
            }
        }

        while(!q.isEmpty()){
            int c = q.poll();

            for(int a : adj.get(c)){
                indegree[a]--;
                waitime[a] = Math.max(waitime[a], waitime[c] + time[a - 1]);
                maxtime = Math.max(maxtime, waitime[a]);

                if(indegree[a] == 0){
                    q.add(a);
                }
            }
        }

        return maxtime;
    }
}