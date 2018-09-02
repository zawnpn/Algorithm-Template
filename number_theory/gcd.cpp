int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int exgcd(int a,int n,int &x,int &y){
    if(n==0) {x=1; y=0; return a;}
    int res= exgcd(n,a%n,y,x);
    y-=x*(a/n);
    return res;
}