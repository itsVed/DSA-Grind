class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;

        vector<bool> online(n, true);
        vector<int> mentions(n, 0);

        // min-heap of {comeOnlineTime, userId}
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        // sort events by timestamp
        sort(events.begin(), events.end(),
            [](const vector<string>& a, const vector<string>& b){
                return stoll(a[1]) < stoll(b[1]);
            }
        );

        int m = events.size();
        int i = 0;

        while(i < m){
            long long T = stoll(events[i][1]);

            // STEP 1 — restore users who should come online now
            while(!pq.empty() && pq.top().first <= T){
                auto [timeOnline, uid] = pq.top();
                pq.pop();
                online[uid] = true;
            }

            // find batch of events with same timestamp
            int j = i;
            while(j < m && stoll(events[j][1]) == T) j++;

            // STEP 2 — process OFFLINE events at this timestamp
            for(int k = i; k < j; k++){
                if(events[k][0] == "OFFLINE"){
                    int uid = stoi(events[k][2]);
                    if(online[uid]) {
                        online[uid] = false;
                        pq.push({T + 60, uid});
                    }
                }
            }

            // STEP 3 — process MESSAGE events
            for(int k = i; k < j; k++){
                if(events[k][0] != "MESSAGE") continue;

                string msg = events[k][2];

                if(msg == "ALL"){
                    for(int u = 0; u < n; u++)
                        mentions[u]++;
                    continue;
                }

                if(msg == "HERE"){
                    for(int u = 0; u < n; u++)
                        if(online[u]) mentions[u]++;
                    continue;
                }

                // parse id<number> tokens
                stringstream ss(msg);
                string tok;
                while(ss >> tok){
                    if(tok.rfind("id", 0) == 0){
                        int uid = stoi(tok.substr(2));
                        mentions[uid]++; // duplicates allowed
                    }
                }
            }

            i = j; // go to next timestamp batch
        }

        return mentions;
    }
};
