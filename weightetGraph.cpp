class weighted_graph{
public:  
    int n;
    vector<pair<int,int>> *adj;
    vector<bool> vis;
    vector<bool> pathVis;
  
    weighted_graph(int n){
        this->n=n;
        adj=new vector<pair<int,int>> [n+1];
        vis.resize(n+1,0);
        pathVis.resize(n+1,0);
    }
    void add_directed_edge(int u, int v, int w=0){
        adj[u].push_back({v,w});
    }
    void add_undirected_edge(int u, int v, int w=0){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    void dfs(int u=1){
        vis[u]=1;

        for(auto v:adj[u]){
            if(!vis[v.first]){
                dfs(v.first);
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
                if(!vis[v.first]){
                    vis[v.first]=1;
                    q.push(v.first);
                }
            }
        }
    }
};