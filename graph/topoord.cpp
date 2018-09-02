const int maxn=510;
vector<int> edges[maxn],ans;
int ind[maxn],n,m,used[maxn];
int dfs(int k){  // void dfs(int k) 只输出一组值 后面return处也要修改
    if(k==n){
        for(int i=0;i<n-1;++i) printf("%d ",ans[i]);
        printf("%d\n",ans[n-1]);
        return 1;
    }
    for(int i=1;i<=n;++i){
        if(!ind[i]&&!used[i]){
            used[i]=1; ans.push_back(i);
            for(int j=0;j<edges[i].size();++j) ind[edges[i][j]]--;
            if(dfs(k+1)) return 1;
            for(int j=0;j<edges[i].size();++j) ind[edges[i][j]]++;
            used[i]=0; ans.pop_back();
        }
    }
    return 0;
}