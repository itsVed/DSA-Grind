class Solution {
public:
    /*
        It was a great question finding the unique palindrome of length 3
        using the set data structure for uniqueness
        first I go with recursion by it got TLE
        then switch to this version
    */
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        unordered_set<int> letter;
        int n = s.length();

        for(char ch : s){ // inserting all characters of string in our set
            letter.insert(ch);
        }

        for(char ch : letter){ // iterating over unique character which are present in our string
            int left_idx = -1;
            int right_idx= -1;

            for(int i=0; i < n; i++){ // left and right index of every character that are in set
                if(s[i] == ch){
                    if(left_idx == -1){
                        left_idx = i;
                    }

                    right_idx = i;
                }
            }

            unordered_set<int> st2; // another set to store the unique characters betweeen the left and right index 
                                    // because that's our answer, as we have to count the unique palindrome of length 3
                                    // so first and last position is fixed just need to take middle character between them

            for(int mid = left_idx + 1; mid < right_idx; mid++){
                st2.insert(s[mid]);
            }

            ans += st2.size(); // increase our ans by the size of unique characters
        }

        return ans; // returning the answer
    }
};