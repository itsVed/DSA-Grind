class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();
        int i = 0;
        bool last = false;

        while(i < n){
            if(bits[i] == 1){
                i += 2;
                last = false;
            }
            else{
                i++;
                last = true;
            }
        }

        return last;
    }
};