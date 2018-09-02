const int maxy=100;
int isrun(int y){
	return (y%400==0)||(y%4==0&&y%100);
}
int monthday[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
struct date{
	int y,m,d;
	void nextday(){
		++d;
		if(d>monthday[m][isrun(y)]){
			d=1;
			++m;
		}
		if(m>12){
			++y;
			m=1;
		}
	}
};
int cnt[maxy][13][32];
void getymd(int &y,int &m,int &d,int days){
	for( y=0;y<maxy;++y){
		for(m=1;m<=12;++m){
			for(d=1;d<=31;++d){
				if(cnt[y][m][d]==days) {
					y+=1970;
					return ;
				}
			}
		}
	}
}
int main(){
	date d; 
	d.y=1970; d.m=1; d.d=1;
	int cur=0;
	while(d.y-1970<maxy){
		cnt[d.y-1970][d.m][d.d]=cur++;
		d.nextday();
	}
}
