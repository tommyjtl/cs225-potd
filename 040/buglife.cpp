#include <queue>
#include <vector>

bool isBipartite(int v, vector<vector<int>> adj)
{
    vector<bool> visitied(adj.size());
    vector<int> level(adj.size());
    visitied[v] = true, level[v] = 0;

    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (int u : adj[v])
        {
            if (!visitied[u])
            {
                visitied[u] = true;
                level[u] = level[v] + 1;
                q.push(u);
            }
            else if (level[v] == level[u])
            {
                return false;
            }
        }
    }

    return true;
}

// returns true if a counterexample is found
bool bugLife(int numBugs, vector<int> &b1, vector<int> &b2)
{
    // code to make ignore the warning
    // delete and replace with your own.
    vector<vector<int>> adj(numBugs + 1);

    for (unsigned long i = 0; i < b1.size(); i++)
    {
        adj[b1[i]].push_back(b2[i]);
        adj[b2[i]].push_back(b1[i]);
    }

    // for (unsigned long i = 1; i < adj.size(); i++) {
    //     std::cout << i << std::endl;
    //     for (const auto &n : adj[i]) {
    //         std::cout << "└----" << n << std::endl;
    //     }
    // }

    for (int i = 1; i < (int)adj.size(); i++)
    {
        // iterative check, in case any component is connecting to itself
        if (!isBipartite(i, adj))
            return true;
    }

    return false;
}