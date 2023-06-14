class graph{
public:  
    int n;
    vector<int> *adj;
    vector<bool> vis;
    vector<bool> pathVis;
  
    graph(int n){
        this->n=n;
        adj=new vector<int> [n+1];
        vis.resize(n+1,0);
        pathVis.resize(n+1,0);
    }
    void add_directed_edge(int u, int v){
        adj[u].push_back(v);
    }
    void add_undirected_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u=1){
        vis[u]=1;

        for(auto v:adj[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
    void bfs(int u=1){
        queue<int> q;
        q.push(u);
        vis[u]=1;

        while(!q.empty()){
            int x=q.front();
            q.pop();

            for(auto v:adj[x]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
};
