const int maxn=110,inf=10000000;
int n,dis[maxn],used[maxn],mat[maxn][maxn];
int prim(){
    memset(used,0,sizeof(used)); 
    fill(dis,dis+n+1,inf);
    dis[1]=0;
    int res=0;
    while(1){
        int u=-1;
        for(int v=1;v<=n;++v){
            if(!used[v]&&(u==-1||dis[v]<dis[u])) u=v;
        }
        if(u==-1) break;
        used[u]=1;
        res+=dis[u];
        for(int v=1;v<=n;++v){
            dis[v]=min(dis[v],mat[u][v]); //注意不是 dis[u]+mat[u][v]
        }
    }
    return res;
}



const int maxn=30,maxm=100,inf=100000;
int vis[maxn],mat[maxn][maxn],dis[maxn];
int n;
int prim(){
    memset(vis,0,sizeof(vis)); 

    fill(dis,dis+n,inf);
    int res=0;  
    dis[0]=0;
    while(1){
        int u=-1;
        for(int v=0;v<n;++v){
            if(!vis[v]&&(u==-1||dis[v]<dis[u])) u=v;
        }
        if(u==-1)  break;
        vis[u]=1;
        res+=dis[u];
        for(int i=0;i<n;++i) dis[i]=min(dis[i],mat[u][i]);
    }
    return res;
}




struct edge{
    int v,l;
    bool operator<(const edge &b) const {return l>b.l;}
    edge(int v=0,int l=inf){
        this->v=v; this->l=l;
    }
};
priority_queue<edge> que;
int prim(){
    fill(dis,dis+n,inf);
    int res=0;
    dis[0]=0; 
    memset(vis,0,sizeof(vis));
    while(que.size()) que.pop();
    que.push(edge(0,0)); 
    while(que.size()){
        int u=que.top().v,l=que.top().l;
        que.pop();
        if(dis[u]!=l||vis[u]) continue;
        res+=l;
        vis[u]=1;
        for(int v=0;v<n;++v) {
            if(dis[v]>mat[u][v]&&!vis[v]){
                dis[v]=mat[u][v];
                que.push(edge(v,dis[v]));
            }
        }
    }
    return res;
}
