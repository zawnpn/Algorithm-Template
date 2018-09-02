struct edge{
    int to,w;
    bool operator<(const edge&b)const {return w>b.w;}
    edge(){to=w=0;}
    edge(int to,int w){this->to=to; this->w=w;}
};
const int maxn=1010,inf=1000000;
vector<edge> edges[maxn];
int n,dis[maxn];
priority_queue<edge> que;
void dijkstra(int s){
    while(que.size()) que.pop();
    fill(dis,dis+n+1,inf);
    que.push(edge(s,0)); dis[s]=0;
    while(que.size()){
        edge eg=que.top(); que.pop();
        int u=eg.to;
        if(eg.w!=dis[u]) continue;
       for(int i=0;i<edges[u].size();++i){
           int v=edges[u][i].to;
           if(dis[v]>dis[u]+edges[u][i].w){
               dis[v]=dis[u]+edges[u][i].w;
               que.push(edge(v,dis[v]));
           }
       }
    }
}