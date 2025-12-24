class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<>());

        int count = 0;
        int csum = 0;

        for(int i=0; i < capacity.size(); i++){
            csum += capacity[i];
            count += 1;

            if(csum >= sum){
                break;
            }
        }

        return count;
    }
};