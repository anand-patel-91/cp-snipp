class DSU{
public:
    int n;
    vector<int> par,size,rank;
    
    DSU(int n){
        this->n=n;
        par.resize(n+1,0);
        size.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
            size[i]=1;
            rank[i]=0;
        }
    }

    int findPar(int v){
        if(v==par[v]) return v;
        return par[v]=findPar(par[v]);
    }

    void unionBySize(int a, int b){
        int x=findPar(a);
        int y=findPar(b);

        if(x!=y){
            if(size[x]<size[y]) swap(x,y);
            par[y]=x;
            size[x]+=size[y];
        }
    }

    void unionByRank(int a, int b){
        int x=findPar(a);
        int y=findPar(b);

        if(x!=y){
            if(size[x]<size[y]) swap(x,y);
            par[y]=x;
            if(rank[x]==rank[y]) rank[x]++;
        }
    }
};