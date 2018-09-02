void print_subset(int *A,int *B,int n,int cur){
    if(cur==n){
        for(int i=0;i<n;++i) if(B[i]) printf("%d ",A[i]); printf("\n");
        return;
    }
    B[cur]=0; print_subset(A,B,n,cur+1);
    B[cur]=1; print_subset(A,B,n,cur+1);
}