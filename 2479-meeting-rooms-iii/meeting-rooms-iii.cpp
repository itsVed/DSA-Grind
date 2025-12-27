class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> usedroom(n, 0);
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> availrooms;
        priority_queue<P, vector<P>, greater<P>> current;
        
        for(int i=0; i < n; i++){
            availrooms.push(i);
        }

        for(vector<int> v : meetings){
            int start = v[0];
            int end = v[1];
            int duration = end - start;

            while(!current.empty() and current.top().first <= start){
                int room = current.top().second;
                availrooms.push(room);
                current.pop();
            }


            if(!availrooms.empty()){
                int room = availrooms.top();
                availrooms.pop();
                usedroom[room]++;
                current.push({end, room});
            }
            else{
                int room = current.top().second;
                long long time = current.top().first;

                current.pop();
                usedroom[room]++;
                current.push({time + duration, room});
            }
        }

        int maxvalue = INT_MIN;
        int roomnum = -1;

        for(int i=0; i < n; i++){
            if(usedroom[i] > maxvalue){
                maxvalue = usedroom[i];
                roomnum = i;
            }
        }

        return roomnum;
    }
};