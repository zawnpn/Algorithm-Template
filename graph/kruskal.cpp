const int maxn=110,maxm=5010;
int n,m,fa[maxn];
int findroot(int u){
    if(fa[u]==-1) return u;
    return fa[u]=findroot(fa[u]);
}
void Union(int u,int v){
    u=findroot(u); v=findroot(v);  //上能直接 fa[u]=v;
    fa[u]=v;
}
struct edge{
    int u,v,w;
    bool operator<(const edge& b) const {return w<b.w;}
} edges[maxm];
int kruskal(){
    memset(fa,-1,sizeof(fa));
    sort(edges,edges+m);
    int res=0;
    for(int i=0;i<m;++i){
        edge eg=edges[i];
        int u=eg.u,v=eg.v;
        if(findroot(u)==findroot(v)) continue;
        res+=eg.w;
        Union(u,v);
    }
    return res;
}