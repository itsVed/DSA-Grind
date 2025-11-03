class Solution {
    public int minCost(String s, int[] t) {
        int n = s.length();
        int cost = 0;
        
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                if (t[i - 1] < t[i]) {
                    cost += t[i - 1];
                    t[i - 1] = 0;
                } else {
                    cost += t[i];
                    t[i] = t[i - 1];
                    t[i - 1] = 0;
                }
            }
        }
        
        return cost;
    }
}