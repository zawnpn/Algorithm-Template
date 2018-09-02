char s[210];
const int inf=10000;
bool isala(char c){ //is alaphabet
     return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
void find_longest_shortest_word(){
    int n=strlen(s);
    int l=0,r=0,lmin,rmin,lmax,rmax;
    lmin=-1; rmin=inf;
    lmax=-1; rmax=-inf;
    while(l<n){
        while(l<n&&!isala(s[l])) ++l; 
        if(l==n) break;
        r=l+1;
        while(r<n&&isala(s[r]))  ++r;
        s[r]=0;
        if(r-l<rmin-lmin) {lmin=l; rmin=r; }
        if(r-l>=rmax-lmax){lmax=l; rmax=r;} 
        l=r+1;
    }
    if(lmax<0) printf("\n");
    else printf("%s\n",s+lmax);
    if(lmin<0) printf("\n");
    else printf("%s\n",s+lmin);
}

void find_longest_shortest_word(string s){
    stringstream ss;
    for(int i=0;i<s.size();++i) 
        if(!isala(s[i])) s[i]=' ';
        ss.clear();
    ss.str(s);
    string Max="",Min(inf,'a');
    string t;
    while(ss>>t){  
        if(t.size()>=Max.size()) Max=t;
        if(t.size()<Min.size())    Min=t;
    }
    cout<<Max<<endl;
    cout<<Min<<endl;
}


