int idx(char ch){
    if(ch>='0'&&ch<='9') return ch-'0';
    if(ch>='A'&&ch<='Z') return ch-'A'+10;
    if(ch>='a'&&ch<='z')  return ch-'a'+10;
}
char ch(int x){
    if(x<10) return '0'+x;
    else return 'A'+x-10;
}
int toten(int b,char *s){
    int res=0;
    int n=strlen(s);
    for(int i=0;i<n;++i){
        int t=idx(s[i]);
        res=res*b+t;
    }
    return res;
}
void tob(int x,int b,char *s){
    int i=0;
    char s1[10000];
    while(x){
        s1[i++]=ch(x%b);
        x/=b;
    }
    for(int j=0;j<i;++j) s[j]=s1[i-1-j]; 
   if(i==0) s[i++]='0';
    s[i]=0;
}