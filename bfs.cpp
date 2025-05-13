#include <bits/stdc++.h>

using namespace std;

class SocialNetwork
{
private:
    unordered_map<int, vector<int>> graph;

public:
    void addConnection(int user1, int user2)
    {
        graph[user1].push_back(user2);
        graph[user2].push_back(user1);
    }

    int getConnection(int user1, int user2)
    {
        if (user1 == user2)
            return 0;

        // Check if users exist
        if (graph.find(user1) == graph.end() || graph.find(user2) == graph.end())
            return -1;

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({user1, 0});
        visited.insert(user1);

        while (!q.empty())
        {
            auto [currUser, dist] = q.front();
            q.pop();

            for (int neighbor : graph[currUser])
            {
                if (neighbor == user2)
                    return dist + 1;

                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return -1;
    }
};