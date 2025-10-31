class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] vis = new boolean[n];
        
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        vis[0] = true;

        while(!q.isEmpty()) {
            int room = q.poll();

            for(int key : rooms.get(room)) {
                if(!vis[key]) {
                    vis[key] = true;
                    q.add(key);
                }
            }
        }

        for(boolean visited : vis) {
            if(!visited) return false;
        }
        
        return true;
    }
}
