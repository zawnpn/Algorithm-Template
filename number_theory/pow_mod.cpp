int pow_mod(ll a,ll p,ll n){
    if(a==0) return 0;
    if(p==0) return 1;
    ll tmp=pow_mod(a,p/2,n);
    tmp=tmp*tmp%n;
    if(p%2) tmp=tmp*a%n;
    return (int) tmp;
}