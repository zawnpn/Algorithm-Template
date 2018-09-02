const int maxnode=100010,sigma_size=10;
struct trie{
    int ch[maxnode][sigma_size],val[maxnode];
    int sz;
    void init(){
        sz=1; 
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    trie(){init();}
    bool insert(char *s){
        int ok=1;
        int u=0,n=strlen(s);
        for(int i=0;i<n;++i){
           int c=s[i]-'0';
           if(!ch[u][c]){
               memset(ch[sz],0,sizeof(ch[sz]));
               ch[u][c]=sz++;
           }
           else{
               if(val[ch[u][c]]||i==n-1) ok=0;
           }
           u=ch[u][c];
        }
        val[u]=1;
        return ok;
    }
} ;