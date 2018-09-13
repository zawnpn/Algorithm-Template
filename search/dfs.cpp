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
//template
int search(int t)
{
    if(满足输出条件)
    {
        输出解;
    }
    else
    {
        for(int i=1;i<=尝试方法数;i++)
            if(满足进一步搜索条件)
            {
                为进一步搜索所需要的状态打上标记;
                search(t+1);
                恢复到打标记前的状态;//也就是说的{回溯一步}
            }
    }
}