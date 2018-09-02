const int maxm=5210,maxn=510;
struct edge{
    int u,v,c;
}edges[maxm];

int e,n,dis[maxn];
bool bellman(){
    const int inf=100000000;  //不能用-1,在判断负环时有问题
    fill(dis,dis+n,inf);
    dis[1]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<e;++j){
            edge eg=edges[j];
            if(dis[eg.v]>dis[eg.u]+eg.c){
                dis[eg.v]=dis[eg.u]+eg.c;
                if(i==n-1) return 1;
            }
        }
    }
    return 0;
}

void bellman(){                //无负边
    const int inf=100000000;  
    fill(dis,dis+n,inf);
    dis[1]=0;
    while(1){
        int update=0;
        for(int i=0;i<e;++i){
            edge eg=edges[i];
            if(dis[eg.v]>dis[eg.u]+eg.c){
                dis[eg.v]=dis[eg.u]+eg.c;
                update = 1;
            }
        }
        if(!update) break;
    }
}