int n,num[1010],dp[1010];
const int inf=10000000;
int lis(){   // nlogn 但是不能打印路径
    fill(dp,dp+n,inf);
    for(int i=0;i<n;++i){
        *lower_bound(dp,dp+n,num[i])=num[i];
    }
    return lower_bound(dp,dp+n,inf)-dp;
}




int n,num[maxn],dp[maxn],pre[maxn];  //n^2 能打印路径
int ans,idx;
void lis(){
    memset(pre,-1,sizeof(pre));
   for(int i=0;i<n;++i){
       dp[i]=0;
       for(int j=0;j<i;++j){
           if(num[i]>num[j]&&dp[j]+1>dp[i]){
               dp[i]=dp[j]+1;
               pre[i]=j;
               if(dp[i]>ans){
                   ans=dp[i];
                   idx=i;
               }
           }
       }
   }
}
void print(int i){
    if(pre[i]!=-1)  print(pre[i]);
    printf("%d",num[i]);
}
int main(){
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;++i) scanf("%d",&num[i]);
        lis();
        printf("%d\n",ans);
        print(idx);
        printf("\n");
    }
    return 0;
}
