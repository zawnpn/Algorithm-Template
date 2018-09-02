char s1[maxn],s2[maxn];
int dp[maxn][maxn];
for(int i=1;i<=n1;++i){  //从1开始存
	for(int j=1;j<=n2;++j){
		if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}


int i=n1,j=n2,path[maxn],k=-1;
while(dp[i][j]){
    if(dp[i-1][j]==dp[i][j]) --i;
    else if(dp[i][j-1]==dp[i][j])  --j;
    else {
            path[++k]=i;
            --i; --j;
    }
}
for(;k;--k) cout<<s1[path[k]]<<" ";
cout<<s1[path[0]]<<endl;
