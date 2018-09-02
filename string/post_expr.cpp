char s[610];
stack<char> ops;
stack<int> num;
int calu(int a,int b,char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/') return a/b;
    return -10000000;
}
bool higher(char op1,char op2){
    if(op2=='(') return 1;
    if((op1=='*'||op1=='/')&&(op2=='+'||op2=='-')) return 1;
    return 0;
}
int solve(){
    while(ops.size())   ops.pop();
    while(num.size())  num.pop();
    int n=strlen(s);
    for(int i=0;i<n;++i){
        if(s[i]=='(') ops.push(s[i]);
        else if(s[i]>='0'&&s[i]<='9'){
            int x=s[i]-'0';
            while(i+1<n&&s[i+1]>='0'&&s[i+1]<='9'){
                ++i;
                x=x*10+s[i]-'0';
            }
            num.push(x);
        }else if(s[i]==')'){
           while(ops.size()&&ops.top()!='('){
               int b,a; 
               b=num.top(); num.pop();
               a=num.top(); num.pop();
               num.push(calu(a,b,ops.top()));
               ops.pop();
           }
           if(ops.size()&&ops.top()=='(') ops.pop();
        }else{
            char op1=s[i];
            while(ops.size()&&!higher(op1,ops.top())){
                int b,a; 
               b=num.top(); num.pop();
               a=num.top(); num.pop();
               num.push(calu(a,b,ops.top()));
               ops.pop();
            }
            ops.push(op1);
        }
    }
    return num.top();
}