class Solution {
public:

    void solve(int idx, string &digits, unordered_map<char, string> &mp, vector<string> &ans, string &temp){
        
        if(idx >= digits.length()){
            ans.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string s = mp[ch];

        for(int i=0; i < s.length(); i++){ // for loop to iterating the string and get the combinations
            temp.push_back(s[i]);
            solve(idx + 1, digits, mp, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;

        if(digits == "") return {};
        
        // mapping the string with the char from 2 to 9
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";

        solve(0, digits, mp, ans, temp);

        return ans;
    }
};