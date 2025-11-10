class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        
        for (int i = 0; i <= n - k; i++) {
            answer.push_back(calculateXSum(nums, i, i + k - 1, x));
        }
        
        return answer;
    }
    
private:
    int calculateXSum(vector<int>& nums, int start, int end, int x) {
        // Count occurrences
        unordered_map<int, int> freq;
        for (int i = start; i <= end; i++) {
            freq[nums[i]]++;
        }
        
        // If less than x distinct elements, return sum of array
        if (freq.size() < x) {
            int sum = 0;
            for (int i = start; i <= end; i++) {
                sum += nums[i];
            }
            return sum;
        }
        
        // Create vector of pairs (value, frequency)
        vector<pair<int, int>> elements;
        for (auto& p : freq) {
            elements.push_back({p.first, p.second});
        }
        
        // Sort by frequency (descending), then by value (descending)
        sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second; // Higher frequency first
            }
            return a.first > b.first; // Higher value first if same frequency
        });
        
        // Calculate x-sum (top x elements)
        int xSum = 0;
        for (int i = 0; i < x && i < elements.size(); i++) {
            xSum += elements[i].first * elements[i].second;
        }
        
        return xSum;
    }
};