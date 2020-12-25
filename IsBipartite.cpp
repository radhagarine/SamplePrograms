class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        if(v<=0) return true;
        vector<char> color(v, '.'); //'.' = not visited, 'b' = black, 'w' = white
        for(int i=0; i<v; ++i)
        {
            if(color[i] == '.')
            {
                bool isbipar = bfs(graph, i, color);
                if(isbipar == false)
                    return isbipar;
            }
        }
        return true;
    }
    bool bfs(vector<vector<int>>& graph, int src, vector<char>& color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 'b';
        while(!q.empty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; ++i)
            {
                int t  = q.front(); q.pop();
                for(int j = 0; j<graph[t].size(); ++j)
                {
                    int neib = graph[t][j];
                    if(color[neib] == '.')
                    {
                        q.push(neib);
                        color[neib] = (color[t] == 'b') ? 'c' : 'b';
                    }
                    else if(color[neib] == color[t])
                        return false;
                }
            }
        }
        return true;
    }
        
};
