#include <bits/stdc++.h>
using namespace std;

// Custom hash for tuple<int,int,int>
struct tuple_hash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto h1 = hash<int>{}(get<0>(t));
        auto h2 = hash<int>{}(get<1>(t));
        auto h3 = hash<int>{}(get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
public:
    int limit;
    deque<tuple<int,int,int>> dq;
    unordered_set<tuple<int,int,int>, tuple_hash> st;
    unordered_map<int, vector<int>> destMap; 

    Router(int memoryLimit) {
        limit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> t = {source,destination,timestamp};
        if (st.count(t)) return false;

        
        if ((int)dq.size() == limit) {
            auto old = dq.front(); dq.pop_front();
            st.erase(old);
            int oldDest = get<1>(old), oldTime = get<2>(old);
            destMap[oldDest].erase(destMap[oldDest].begin());
        }

        dq.push_back(t);
        st.insert(t);
        destMap[destination].push_back(timestamp); 
        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty()) return {};
        auto t = dq.front(); dq.pop_front();
        st.erase(t);

        int dest = get<1>(t), time = get<2>(t);
        destMap[dest].erase(destMap[dest].begin());

        return {get<0>(t), dest, time};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto &vec = destMap[destination];
        auto l = lower_bound(vec.begin(), vec.end(), startTime);
        auto r = upper_bound(vec.begin(), vec.end(), endTime);
        return r - l;
    }
};
