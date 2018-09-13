#include<cstdio>
#include<iostream>
#include<cstdlib>//for "exit()"
#include<algorithm>//for "reverse()"
#include<string>
#include<cstring>
using namespace std;
const int M = 10, P = 1, DIGITS=20000;// M=10^P 压位
//const int M = 100000000, P = 8, DIGITS = 20000;

struct BigNum
{
	int n[DIGITS], l, Y;//最大DIGITS位
	BigNum() { l = 1, memset(n, 0, sizeof(n)); }
	void init()
	{
		string s; cin >> s;
		int now = 0, ct = 0, c1 = 1;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			n[now] += (s[i] - '0')*c1; c1 *= 10; ct++;
			if (ct == P && i != 0) { now++; c1 = 1; ct = 0; }
		}
		l = now + 1;
	}
	void print()
	{
		if (n[l - 1] == 0) { printf("0"); exit(0); }//对0特殊处理
		printf("%d", n[l - 1]);
		for (int i = l - 2; i >= 0; i--) printf("%0*d", P, n[i]);
		printf("\n");
	}
	BigNum operator +(BigNum x)const
	{
		   BigNum t=*this;
		   if(x.l>t.l)t.l=x.l;
		   for(int i=0;i<t.l;i++)
		   {
			t.n[i]+=x.n[i];
			if(t.n[i]>=M){t.n[i+1]+=t.n[i]/M;t.n[i]%=M;}
		   }
		   while(t.n[t.l])
		   {
			   t.n[t.l+1]+=t.n[t.l]/M;
			   t.n[t.l++]%=M;
		   }
		   return t;
	}
	bool operator < (BigNum x) const
	{
		BigNum t=*this;
		if(t.l!=x.l)return t.l<x.l;
		for(int i=t.l-1;i>=0;i--)
		{
		   if(t.n[i]!=x.n[i])return t.n[i]<x.n[i];
		}
		return 0;
	}
	BigNum operator -(BigNum x)const
	{
		BigNum t=*this;
		if(t<x){printf("-");swap(t,x);}
		for(int i=0;i<t.l;i++)
		{
		 t.n[i]-=x.n[i];
		 if(t.n[i]<0)
		 {
			 t.n[i]+=M;
			 --t.n[i+1];
		 }
		}
		while(!t.n[t.l-1]&&t.l>1)t.l--;
		return t;
	}
	
	BigNum operator * (BigNum x) const
	{
		BigNum c, t = *this;
		c.l = t.l + x.l - 1;
		for (int i = 0; i < t.l; i++)
			for (int j = 0; j < x.l; j++)
			{
				c.n[i + j] += t.n[i] * x.n[j];
				if (c.n[i + j] >= M)
				{
					c.n[i + j + 1] += c.n[i + j] / M;
					c.n[i + j] %= M;
				}
			}
		while (c.n[c.l])
		{
			c.n[c.l + 1] += c.n[c.l] / M;
			c.n[c.l++] %= M;
		}
		return c;
	}
 void Add(int x){if(x||l)n[l++]=x;}
 void Re(){reverse(n,n+l);}
 BigNum operator /(const BigNum &x)const
 {
	 BigNum t=*this,r,y;
	 y.l=0,r.l=t.l;
	 for(int i=t.l-1;i>=0;--i)
	 {
		 y.Add(t.n[i]);
		 y.Re();
		 while(!(y<x))y=y-x,r.n[i]++;
		 while(!y.n[y.l-1] && y.l>1)--y.l;
		 y.Re();
	 }
	 while(!r.n[r.l-1] && r.l>1)--r.l;
	 return r;
 }
 BigNum operator /(const int &x)const
 {
	 BigNum t=*this,r;
	 r.l=t.l;
	 int tmp=0;
	 for(int i=t.l-1;i>=0;--i)
	 {
		 tmp+=t.n[i];
		 if(tmp>=x)
			 r.n[i]+=tmp/x,tmp%=x;
		 tmp*=M;
	 }
	 while(!r.n[r.l-1] && r.l>1)--r.l;
	 return r;
 }
}a, b, c;//给a,b,c定义

int main()
{
	a.init();
	b.init();
	c = a * b;
	c.print();//自带换行
	c = a - b;
	c.print();
	c = a + b;
	c.print();
	c = a / b;
	c.print();
	return 0;
}