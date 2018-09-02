for(int i=0;i<n;++i) {
    for(int j=0;j<n;++j) scanf("%d",&mat[i][j]);
}
fill(tot[0],tot[0]+n,0);
for(int i=1;i<=n;++i){
    for(int j=0;j<n;++j) tot[i][j]=tot[i-1][j]+mat[i-1][j];
}
int res=-inf;
for(int i=0;i<n;++i){
    for(int j=i+1;j<=n;++j){
        for(int k=0;k<n;++k) line[k]=tot[j][k]-tot[i][k];
        res=max(res,max_sub_sum(line,dp,n));
    }
}
