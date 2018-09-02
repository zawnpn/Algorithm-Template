int wei[maxn],val[maxn],dp[maxn],c;
memset(dp,0,sizeof(dp));  //若要恰好放满 则dp[0]=0  其余为负无穷
for(int i=0;i<n;++i){             //若c较小，n较大，可调整 i,j的内外顺序
    for(int j=c;j>=wei[i];--j){   //完全背包的话，j顺序反过来即可
        dp[j]=max(dp[j],dp[j-wei[i]]+val[i]);
    }
}