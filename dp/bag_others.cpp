//double cost bag(3d)
f[i][v][u]=max(f[i-1][v][u],f[i-1][v-a[i]][u-b[i]]+w[i])
//double cost bag(2d)
for v=V...cost
	for u=U...cost
		f[v][u]=max(f[u][v],f[u-ucost[i]][v-vcost[i]]+w[i])

//group bag
for group in groups
	for v=V...0
		for i in group
			f[v]=max(f[v],f[v-c[i]]+w[i])
			
//optimize
if cost[i]<=cost[j] && weight[i]==weight[j]
	remove item[j]