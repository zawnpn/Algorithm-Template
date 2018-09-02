int modequ(int a,int b,int n){    //ax=b(mod n)
    int d=gcd(a,n);
    if(b%d!=0) return -1;          
    a/=d; b/=d; n/=d;  n=abs(n);  //a'x=b(mod n)
    int x,y;         
    exgcd(a,n,x,y); 
    int p=x*b;                   //x=(a')^(-1)b'
    return ((p%n)+n)%n;
}
