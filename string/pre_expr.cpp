#include<cstdlib>
#include<cstdio>
using namespace std;
char s[100];
double exp(){
    scanf("%s",s);
    char c=s[0];
    if(c=='+') return exp()+exp();
    else if(c=='-') return exp()-exp();
    else if(c=='*') return exp()*exp();
    else if(c=='/') return exp()/exp();
    else return atof(s);
}
int main(){
    printf("%f\n",exp());
}



//#include<cstdlib> 
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<iostream>
//#include<queue>
//#include<stack>
//#include<sstream>
//using namespace std;
//typedef long long ll;
//stack<string> stk;  //这个方法有问题
//string s,s1;
//bool isnum(string str){
//    return (str.size()>1)||(str[0]>='0'&&str[0]<='9');
//}
//bool isop(string str){
//    char op=str[0];
//    return (op=='+'||op=='-'||op=='*'||op=='/');
//}
//double getres(double a,double b,string op){
//    if(op[0]=='+' ) return a+b;
//    if(op[0]=='-' ) return a-b;
//    if(op[0]=='*' ) return a*b;
//   else return a/b;
//}
//void calu(){
//    while(stk.size()>=3){
//        string s3,s2,s1;
//        s3=stk.top(); stk.pop();
//        s2=stk.top(); stk.pop();
//        s1=stk.top(); stk.pop();
//        if(isnum(s3)&&isnum(s2)&&isop(s1)){
//            double a=stod(s2),b=stod(s3);
//            stk.push(to_string(getres(a,b,s1)));
//        }else{
//            stk.push(s1); stk.push(s2); stk.push(s3);
//            break;
//        }
//    }
//}
//int main(){
//    while(getline(cin,s)){
//        stringstream ss(s);
//        while(stk.size()) stk.pop();
//        while(ss>>s1){
//            stk.push(s1);
//            calu();
//        }
//        printf("%f\n",stod(stk.top()));
//    }
//    return 0;
//}

