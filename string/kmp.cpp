int kmp(char *t,char *p){
    int n=strlen(t),m=strlen(p);
    int *next=new int[m];
    next[0]=-1;
    for(int i=1,k=-1;i<m;++i){
        while(k>=0&&p[k+1]!=p[i]) k=next[k];
        if(p[k+1]==p[i]) ++k;
        next[i]=k;        //k保存的是p[0,1...i]的最长的同时是前缀和后缀的，那个前缀的最后一个字符的下标
    }
    for(int i=0,k=-1;i<n;++i){
        while(k>=0&&p[k+1]!=t[i]) k=next[k];
        if(p[k+1]==t[i]) ++k; //k保存的是p中已经匹配的最后一个字符的下标
        if(k==m-1) return i-m+1;   
    }
    return -1;  //不匹配
}
