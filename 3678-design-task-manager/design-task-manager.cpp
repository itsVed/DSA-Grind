class TaskManager {
public:

    unordered_map<int, pair<int,int>> taskinfo;
    priority_queue<pair<int,int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        
        for(int i=0;i < tasks.size(); i++){
            int userid = tasks[i][0];
            int taskid = tasks[i][1];
            int pri    = tasks[i][2];
            
            taskinfo[taskid] = {userid, pri};
            pq.push({pri, taskid});
        }

    }
    
    void add(int userId, int taskId, int priority) {
        taskinfo[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskinfo[taskId].second = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskinfo.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto[pri, taskid] = pq.top();
            pq.pop();

            if(taskinfo.count(taskid) and taskinfo[taskid].second == pri){
                int user = taskinfo[taskid].first;
                taskinfo.erase(taskid);

                return user;
            }
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */