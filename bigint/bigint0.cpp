const int maxn=210;
struct bigint{
	int dig[maxn];
	bigint(string s=""){
		memset(dig,0,sizeof(dig));
		if(s.size()==0) {
			dig[0]=1;
			dig[1]=0;
			return ;
		}
		int k,i;
		for(i=s.length()-1,k=0;i>=0;--i){
			dig[++k]=s[i]-'0';
		}
		dig[0]=k;
	}
	void print(){
		for(int i=dig[0];i>0;--i){
			if(dig[i]==0&&dig[0]>1) --dig[0];
			else break;
		}
		for(int i=dig[0];i;--i) printf("%d",dig[i]);
	}
	bigint operator+(const bigint &b)const {
		bigint c;
		c.dig[0]=max(dig[0],b.dig[0]);
		for(int i=1;i<=c.dig[0];++i){
			if(i<=dig[0]) c.dig[i]+=dig[i];
			if(i<=b.dig[0]) c.dig[i]+=b.dig[i];
		}
		int x=0,i=1;
		while(x||i<=c.dig[0]){
			x+=c.dig[i];
			c.dig[i]=x%10;
			x/=10;
			++i;
		}
		c.dig[0]=i-1;
		return c;
	}
	bigint operator*(const bigint& b)const{
		bigint c;
		c.dig[0]=dig[0]+b.dig[0]-1;
		for(int i=1;i<=dig[0];++i){
			for(int j=1;j<=b.dig[0];++j){
				c.dig[i+j-1]+=dig[i]*b.dig[j];
			}
		}
		int x=0,i=1;
		while(i<=c.dig[0]||x){
			x+=c.dig[i];
			c.dig[i]=x%10;
			x/=10;
			++i;
		}
		c.dig[0]=i-1;
		return c;
	}
};