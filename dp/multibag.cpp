//HDU-2191
#include <cstdio>
const int maxn = 110;
int dp[maxn];
struct rice{
    int p;
    int h;
    int c;
} r[maxn];
int V;
int max(int a, int b) { return a > b ? a : b; }
void ZeroOnePack(int cost, int weight){
    for (int v = V; v >= cost; v--){
        dp[v] = max(dp[v], dp[v - cost] + weight);
    }
    return;
}
void CompletePack(int cost, int weight){
    for (int v = cost; v <= V; v++){
        dp[v] = max(dp[v], dp[v - cost] + weight);
    }
    return;
}
void MultiplePack(int cost, int weight, int amount){
    if (cost*amount >= V){
        CompletePack(cost, weight);
        return;
    }
    else{
        int k = 1;
        while(k<amount){
            ZeroOnePack(k * cost, k * weight);
            amount -= k;
            k *= 2;
        }
        ZeroOnePack(amount * cost, amount * weight);
    }
    return;
}
int main(){
    int c, m;
    scanf("%d", &c);
    while(c--){
        scanf("%d%d", &V, &m);
        for (int i = 1; i <= m; i++){
            scanf("%d%d%d", &r[i].p, &r[i].h, &r[i].c);
        }
        for (int v = 0; v <= V; v++){
            dp[v] = 0;
        }
        for (int i = 0; i <= m; i++){
            MultiplePack(r[i].p, r[i].h, r[i].c);
        }
        printf("%d\n", dp[V]);
    }
    return 0;
}