class Solution {
public:
    int minimumDeletions(string s) {
        // find the pair of a and b starts with b then a

        stack<char> st;
        int n = s.length();
        int count = 0;

        for(int i=0; i < n; i++){

            if(!st.empty() and s[i] == 'a' and st.top() == 'b'){
                st.pop();
                count++;
                continue;
            }
        
            st.push(s[i]);
            //cout<<st.top()<<endl;
        }

        return count;
    }
};