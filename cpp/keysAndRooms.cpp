#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, bool> visited;
        queue<int> q;
        
        
        for(int i=0; i<rooms.size(); i++)
        {
            visited[i] = false;
        }
        q.push(0);
        visited[0] = true;
        
        while(!q.empty())
        {
            int current_node = q.front();
            q.pop();
            
            for(auto n: rooms[current_node])
            {
                if(!visited[n])
                {
                    visited[n] = true;   
                    q.push(n);
                }
            }
        }
        
        for(int i=0; i<rooms.size(); i++)
            if (visited[i]==false)
                return false;
        return true;
    }
};