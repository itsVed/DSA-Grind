class Solution {
    public List<Integer> topoSort(int k, int[][] conditions) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= k; i++) adj.add(new ArrayList<>());

        int[] indegree = new int[k + 1];

        for (int[] edge : conditions) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            indegree[v]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) q.add(i);
        }

        List<Integer> order = new ArrayList<>();

        while (!q.isEmpty()) {
            int node = q.poll();
            order.add(node);

            for (int nei : adj.get(node)) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.add(nei);
            }
        }

        if (order.size() != k) return new ArrayList<>();
        
        return order;
    }

    public int[][] buildMatrix(int k, int[][] row, int[][] col) {

        List<Integer> rowOrder = topoSort(k, row);
        List<Integer> colOrder = topoSort(k, col);

        if (rowOrder.isEmpty() || colOrder.isEmpty()) return new int[0][0];

        int[] rowPos = new int[k + 1];
        int[] colPos = new int[k + 1];

        for (int i = 0; i < k; i++) {
            rowPos[rowOrder.get(i)] = i;
            colPos[colOrder.get(i)] = i;
        }

        int[][] ans = new int[k][k];

        for (int num = 1; num <= k; num++) {
            ans[rowPos[num]][colPos[num]] = num;
        }

        return ans;
    }
}