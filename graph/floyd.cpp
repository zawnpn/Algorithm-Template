const int inf=1000000,maxn=210;   //支持负边
int n,dis[maxn][maxn];
void floyd(){          //dis[i][i]=0;  inf
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }     //通过检查dis[i][i]有没有为负的 可以判断有无负圈
}


//支持打印路径
const int maxn=40;
int p,q,r;
const int inf=1000000;
map<string,int> Id;
map<int,string> Name;
struct dis{
    int len,pre;
} Dis[maxn][maxn];
void print(int u,int v){
    if(u==v){
        cout<<Name[v]; return;
    }
    print(u,Dis[u][v].pre);
    cout<<"->("<<Dis[Dis[u][v].pre][v].len<<")"<<"->"<<Name[v];
}
for(int k=0;k<p;++k){
        for(int i=0;i<p;++i){
            for(int j=0;j<p;++j){
                int tmp=Dis[i][k].len+Dis[k][j].len;
                if(tmp<Dis[i][j].len){
                    Dis[i][j].len=tmp; 
                    Dis[i][j].pre=Dis[k][j].pre;
                }
            }
        }
    }