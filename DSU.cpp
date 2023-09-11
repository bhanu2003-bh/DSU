class disjoint
{
    private:
    vector<int>rank,par,sz;

    public:
    disjoint(int n){
        rank.resize(n+1,0);
        par.resize(n+1,0);
        sz.resize(n+1,0);
        for (int i = 0; i <n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int findpar(int node){
        if(par[node]==node) return par[node];
        return par[node] = findpar(par[node]);
    }
    
    void Unionbyrank(int u,int v){
      int p1 = findpar(u);
      int p2 = findpar(v);
      if(p1==p2) return;
      int r1 = rank[p1];
      int r2 = rank[p2];
      if(r1>r2){
        par[p2] = p1;
      }
      else if(r2>r1){
        par[p1] = p2;
    
      }
      else{
        rank[p1]++;
        par[p2] = p1;
       }
    }


        void Unionbysize(int u,int v){
      int p1 = findpar(u);
      int p2 = findpar(v);
      if(p1==p2) return;
       int s1 = sz[p1];
       int s2 = sz[p2];
       if(s1>s2){
        par[p2] = p1;
        sz[p1] = sz[p1]+sz[p2];
       }
       else{
        par[p1] = p2;
        sz[p2] = sz[p2]+sz[p1];
       }
    }
};
