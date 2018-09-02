queue<int> que; 
int vis[maxn];
while(que.size()) que.pop();
memset(vis,0,sizeof(vis));
que.push(0); vis[0]=1;
void bfs(){
    while(que.size()){
        int x=que.front(); que.pop();
        for( ){
            vis[ ]=1; //每加入队列就标记
            que.push( );
        }
    }
}
