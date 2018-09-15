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

//两个相同列打乱范围求lcs(在映射中求lis)
int b[N],idx[N],n;
int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while ('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
int main(){
    n=read();
    memset(b,0x3f,sizeof(b));
    for (int i=1;i<=n;i++)
        idx[read()]=i;
    for (int i=1;i<=n;i++){
        int x=idx[read()];
        *lower_bound(b+1,b+n+1,x)=x;
    }
    printf("%d",lower_bound(b+1,b+n+1,b[0])-b-1);
    return 0;
}
