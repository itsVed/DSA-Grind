class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;

        for(int i=0; i < s.length(); i++){
            mp[s[i]]++;
        }

        for(auto i: t){
            if(mp[i] > 0){
                mp[i]--;

                if(mp[i] == 0){
                    mp.erase(i);
                }
            }
            else{
                return false;
            }
        }

        return mp.size() == 0 ? true : false;
    }
};