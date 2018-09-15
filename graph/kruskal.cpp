const int maxn=110,maxm=5010;
int n,m,fa[maxn];
int findroot(int u){
    if(fa[u]==-1) return u;
    return fa[u]=findroot(fa[u]);
}
/*int findroot(int u) {//初始化操作不同
	if (u != fa[u]) {
		fa[u] = findroot(fa[u]);
	}
	return fa[u];
}*/
void Union(int u,int v){
    u=findroot(u); v=findroot(v);  //上能直接 fa[u]=v;
    fa[u]=v;
}
struct edge {
	int u, v, w;
	bool operator<(const edge& b) const { return w < b.w; }
	edge() :u(), v(), w() {}
	edge(int u, int v, int w) :
		u(u), v(v), w(w) {}
} edges[maxm];
int kruskal(){
    memset(fa,-1,sizeof(fa));
	//for (int i = 1; i <= n; i++) fa[i] = i;//另一种
    sort(edges,edges+m);
    int res=0;
    for(int i=0;i<m;++i){
        edge eg=edges[i];
        int u=eg.u,v=eg.v;
        if(findroot(u)!=findroot(v)){
			res+=eg.w;
			Union(u,v);
		}
    }
    return res;
}