class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        vector<vector<int>> al(n);
        for(int i=0; i<edges.size(); ++i)
        {
            int s = edges[i][0];
            int d = edges[i][1];
            al[s].push_back(d);
            al[d].push_back(s);
        }
        bool res = true;
        int comp = 0;
        for(int i=0; i<n; ++i)
        {
            if(!visited[i])
            {
                dfs(n, 0, al, visited, parent, res);
                comp++;
                if(comp > 1) return false;
            }
        }
        return res;
    }
    void dfs(int n, int src, vector<vector<int>>& al, vector<bool>& visited, vector<int>& parent, bool& res)
    {
        visited[src] = true;
        for(int neib: al[src])
        {
            if(!visited[neib])
            {
                parent[neib] = src;
                dfs(n, neib, al, visited, parent, res);
                if(!res) return;
            }
            else
            {
                if(parent[src] != neib)
                    res = false;
            }
        }
    }
};
