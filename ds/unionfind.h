const int maxn=1010;
int fa[maxn];  //memset(fa,-1,sizeof(fa));
findroot(int x){
    if(fa[x]==-1) return x;
    return fa[x]=findroot(fa[x]);
}

void Union(int x,int y){
    x=findroot(x); y=findroot(y);
    if(x!=y) fa[x]=y;
}