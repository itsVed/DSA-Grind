class Solution {
public:

    void rotate(string &s, int b){
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    string findLexSmallestString(string s, int a, int b) {
        string small = s;
        int n = s.length();

        queue<string> q;
        q.push(s);
        unordered_set<string> mp;
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < small){
                small = curr;
            }

            // Add a
            string temp = curr;
            for(int i=1; i < temp.length(); i+=2){
                temp[i] = (((temp[i] - '0') + a) % 10) + '0';
            }

            if(!mp.count(temp)){
                mp.insert(temp);
                q.push(temp);
            }

            // Rotate by b
            rotate(curr, b);

            if(!mp.count(curr)){
                mp.insert(curr);
                q.push(curr);
            }

        }

        return small;
    }
};