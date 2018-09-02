const int maxn=110; 
int lc[maxn],rc[maxn],p[maxn];  /／若节点编号严格是1-n
int n,m;



const int maxn=1010;
struct node{
    int val;
    node *lc,*rc;
} nodes[maxn];
int cur=0;
node *newnode(int v=0){
    nodes[cur].val=v; 
    nodes[cur].lc=nodes[cur].rc=0;
    return &nodes[cur++];
}
