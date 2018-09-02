int max_sub_sum(int *line,int *dp,int n){
    fill(dp,dp+n,0);
    dp[0]=line[0];
    for(int i=1;i<n;++i) dp[i]=max(dp[i],dp[i-1]+line[i]);
    int res=-inf;
    for(int i=0;i<n;++i) res=max(res,dp[i]);
    return res;
}
