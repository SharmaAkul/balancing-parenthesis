#include<iostream>

#include<string.h>
using namespace std;

char st[100];
int top=-1;
void push(char r){
top++;
st[top]=r;}
char pop(){
    char a;
    if(top==-1){
        cout<<"under flow"<<endl;
        return 0;}
a=st[top];
top--;
return a;}

int main(){
int flag=0;
char p[200];
char a1;
cout<<"enter the expression"<<endl;
cin.getline(p,200);
for(int i=0;p[i]!='\0';i++){
         if(p[0]=='}'||p[0]==')'||p[0]==']'){
            push(p[i]);
            break;
        }
    if(p[i]=='(' || p[i]=='{' || p[i]=='['){
        push(p[i]);
       }
    else{
        if(p[i]==')'){
            a1=pop();
            if(a1!='('){
                push(a1);
                break;
            }
           }
        else if(p[i]=='}'){
            a1=pop();
            if(a1!='{'){
            push(a1);
                break;
            }
            }
        else if(p[i]==']'){
            a1=pop();
            if(a1!='['){
               push(a1);
                break;
            }
            }
        }
    }
 if(top>=0 || flag==1){
    cout<<"unbalanced";
 }
 else
    cout<<"balanced";
}
