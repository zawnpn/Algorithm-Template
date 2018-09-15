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
//template
int search()
{
    while(!que.empty)
    {
        node cur = que.front();que.pop();
		for(int i=1;i<=尝试方法数;i++)
		{
            node next = cur + ...
			if(next满足进一步搜索条件)
            {
                que.push(next);//为进一步搜索所需要的状态打上标记;
                进行当前步的操作
            }
		}
    }
}
