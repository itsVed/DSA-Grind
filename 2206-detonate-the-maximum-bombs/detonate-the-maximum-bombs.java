class Solution {
    public int dfs(int i, List<List<Integer>> adj, boolean[] vis){
        int count = 1;
        vis[i] = true;

        for(int bomb : adj.get(i)){
            if(!vis[bomb]){
                count += dfs(bomb, adj, vis);
            }
        }

        return count;
    }

    public int maximumDetonation(int[][] bombs) {
        List<List<Integer>> adj = new ArrayList<>();
        int n = bombs.length;
        int ans = 0;

        for(int i=0; i < n; i++){
            adj.add(new ArrayList<>());
        }

        for(int i=0; i < n; i++){
            long x1 = bombs[i][0];
            long y1 = bombs[i][1];
            long r1 = bombs[i][2];

            for(int j=0; j < n; j++){
                if(i == j) continue;

                long x2 = bombs[j][0];
                long y2 = bombs[j][1];

                long dx = x2 - x1;
                long dy = y2 - y1;

                long dist = dx * dx + dy * dy;

                if(dist <= r1 * r1){
                    adj.get(i).add(j);
                }
            }
        }

        for(int i=0; i < n; i++){
            boolean[] vis = new boolean[n];

            ans = Math.max(ans, dfs(i, adj, vis));
        }

        return ans;
    }
}