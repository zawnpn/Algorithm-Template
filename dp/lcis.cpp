int n,m,num1[maxn],num2[maxn],pre[maxn],dp[maxn],ans,Max,last,idx;
void lcis(){
    ans=0; 
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<n;++i){
        Max=0;
        for(int j=0;j<m;++j){  //dp[j]表示串1的前i个和串的前j个，且以num2[j]结尾
            if(num1[i]>num2[j]) {
                Max=max(Max,dp[j]); //最大的dp[i-1][k]
                last=j;
            }
            if(num1[i]==num2[j]) {
                dp[j]=Max+1;
                pre[j]=last;
            }
            if(dp[j]>ans){
                ans=dp[j];
                idx=j;
            }
        }
    }
}
void print(int idx){
    if(pre[idx]!=-1) print(pre[idx]);
    printf("%d",num2[idx]);
}
