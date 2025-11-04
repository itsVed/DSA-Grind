class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;

        HashMap<Integer,Integer> mp = new HashMap<>();
        for (int i = 0; i < k; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        int[] ans = new int[n - k + 1];

        BiFunction<HashMap<Integer,Integer>, Integer, Integer> sum = (map, X) -> {
            List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());

            Collections.sort(list, (a, b) -> {
                if (a.getValue().equals(b.getValue()))
                    return b.getKey() - a.getKey();
                return b.getValue() - a.getValue();
            });

            int s = 0;
            int count = 0;

            for (Map.Entry<Integer, Integer> e : list) {
                if (count == X) break;
                s += e.getKey() * e.getValue();
                count++;
            }

            return s;
        };

        ans[0] = sum.apply(mp, x);

        for (int i = k; i < n; i++) {
            mp.put(nums[i - k], mp.get(nums[i - k]) - 1);
            
            if (mp.get(nums[i - k]) == 0) mp.remove(nums[i - k]);

            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);

            ans[i - k + 1] = sum.apply(mp, x);
        }

        return ans;
    }
}
