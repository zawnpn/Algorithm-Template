struct node{
    node *lc,*rc;
    char ch;
} nodes[maxn];

void preord(node *t){
    if(t==0) return;
    printf("%d",t->id);
    preord(t->lc); preord(t->rc);
}  
int cur=0,idx=0;
node * newnode(){
    nodes[cur].lc=nodes[cur].rc=0; 
    nodes[cur].ch=s[idx++];
    return &nodes[cur++];
}

node *build(){
    if(idx==len) return 0;
    char ch=s[idx];
    if(ch=='#') {++idx; return 0;}
    node *t=newnode();
    t->lc=build();
    t->rc=build();
    return t;
}
char s1[maxn],s2[maxn];
node *build(int l1,int r1,int l2,int r2){
    int idx;
    node *t=newnode(); t->ch=s1[l1];
    if(idx!=l2) t->lc=build(l1+1,idx-l2+l1+1,l2,idx);
    if(idx!=r2-1)t->rc=build(idx-l2+l1+1,r1,idx,r2);
    return t;
}

