int cnt,vis[maxn][maxn];
void dfs(int x,int y,int id){
    // 判读边界
    dfs(nx,ny,id);
}

for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        if(!vis[i][j]){
            vis[i][j]=1;
            dfs(i,j,++cnt);
            //vis[i][j]=0;
        }
    }
}