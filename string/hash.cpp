const ull B=1000000007; //实在不行 可以用两个hash 另外用1e9+9

bool contatin(string a,string b){
    int la=a.length(),lb=b.length();
    if(la>lb) return 0;
    ull ha=0,hb=0,t=1;
    for(int i=0;i<la;++i){
        t*=B;
        ha=ha*B+a[i];
        hb=hb*B+b[i];
    }
    for(int i=0;i+la<=lb;++i){
        if(hb==hb) return 1;
        if(i+la<lb) hb=hb*B+b[i+la]-b[i]*t;
    }
    return 0;
}