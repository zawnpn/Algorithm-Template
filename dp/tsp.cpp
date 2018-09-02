int solve(){   //上回到起始点，如果需要回到起始点，
    int s;
    for( s=0;s< (1<<n)-1;++s) fill(dp[s],dp[s]+n,inf);
    fill(dp[s],dp[s]+n,0);
    for(s=(1<<n)-2;s>0;--s){
        for(int u=0;u<n;++u ){
            if((s&(1<<u))==0) continue;   
            for(int v=0;v<n;++v){
                if(s&(1<<v)) continue;
                dp[s][u]=min(dp[s][u],dp[s|(1<<v)][v]+mat[u][v]);
            }
        }
    }
    s=1;
    int res=inf;
    for(int i=0;i<n;++i){
        res=min(res,dp[s][i]);
        s<<=1;
    }
    return res;
}