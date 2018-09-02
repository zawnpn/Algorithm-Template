ll exgcd(ll a,ll b,ll &x,ll &y){     
    if(b==0) {x=1; y=0; return a;}
    ll res=exgcd(b,a%b,y,x);
    y-=x*(a/b);
    return res;
}
ll M;
ll china(int n,int *a,int *m){   // x=a_i(mod m_i) i=1,2,,,n
    ll x,y,res=0;
    M=1;
    for(int i=0;i<n;++i) M*=m[i];
    for(int i=0;i<n;++i){
        ll w=M/m[i];
        exgcd(w,(ll)m[i],x,y);
        res=(res+w*x*a[i])%M;
    }
    return (res+M)%M;
}