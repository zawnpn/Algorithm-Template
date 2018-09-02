void cnt(){
        fill(dp,dp+m+1,0); dp[0]=1; //恰好凑齐
        for(int i=0;i<n;++i){
            for(int j=m;j>=num[i];--j){
                dp[j]=(dp[j-num[i]]+dp[j]);
            }
        }
}