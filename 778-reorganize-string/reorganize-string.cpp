class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        pair<int, char> prev = {0, '#'};

        string ans = "";

        while(!pq.empty()){
            auto [count, ch] = pq.top();
            pq.pop();

            ans += ch;
            count--;

            if(prev.first > 0){
                pq.push(prev);
            }

            prev = {count, ch};
        }

        if(ans.length() != s.length()) return "";

        return ans;
    }
};