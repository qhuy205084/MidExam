#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define Maxlength 100
typedef struct{
    char Elements[Maxlength];
    int top_idx;
}Stack;
void makenullStack(Stack *pS){
    pS->top_idx=-1;
}
int emptyStack(Stack S){
    return S.top_idx==-1;
}
int fullStack(Stack S){
    return S.top_idx==Maxlength;
}
void push(char X,Stack *pS){
    if (fullStack(*pS))
    printf("Nhan xep day\n");
    else 
    pS->Elements[++pS->top_idx]=X;
}
void pop(Stack *pS){
    if (emptyStack(*pS))
      printf("Ngan Xep Rong \n");
      else 
      pS->top_idx--;
}
char top(Stack S){
    if (emptyStack(S))
    printf("Ngan xep rong\n");
    else return S.Elements[S.top_idx];
}
int isOperand(char ch){
    return (ch>=48)&&(ch<=57);
}
int priority(char ch){
    if (ch=='+'||ch=='-')
    return 1;
    if (ch=='*'||ch=='/'||ch=='%')
    return 2;
    return 0;
}
void strAdd(char *Str,char ch){
    int L=strlen(Str);
    Str[L]=ch;
    Str[L+1]=' '; 
    Str[L+2]='\0';

}
void Infix2pofix(char *Infix,char *Postfix){
    Stack S;
    makenullStack(&S);
    int i,L=strlen(Infix);
    char Token;
    for (i=0;i<L;i++){
        Token=Infix[i];
        if (Token!=32)
        if (isOperand(Token))
        strAdd(Postfix,Token);
        else if (Token=='(')
        push('(',&S);
        else if (Token==')'){
            while(top(S)!='('){
                strAdd(Postfix,top(S));
                pop(&S);
            }
            pop(&S);
        }
        else{
            while(!emptyStack(S)&&(priority(top(S))>=priority(Token))){
                strAdd(Postfix,top(S));
                pop(&S);
            }
            push(Token,&S);
        }
    }
    while(!emptyStack(S)){
        strAdd(Postfix,top(S));
        pop(&S);
    }
    
}
int calculate(int a,int b,char Operator){
    switch(Operator){
        case '+':
        return a+b;
        case '-':
        return a-b;
        case '*':
        return a*b;
        case '/':
        return a/b;
        case '%':
        return a%b;
    }
}
int Eval(char *St){
    Stack S;
    char Token;
    int tren,duoi;
    makenullStack(&S);
    int L=strlen(St);
    int i;
    for(i=0;i<L;i++){
        Token=St[i];
        if(Token!=32){
        if (isOperand(Token))
        push(Token-48,&S);
        else{
            tren=top(S);
            pop(&S);
            duoi=top(S);
            pop(&S);
            push(calculate(duoi,tren,Token),&S);
        }
        }
    }
    return top(S);
}
int main(){
    char Posfix[255];
    char Infix[255];
    printf("\nNhap bieu thu toan hoc:");
    fflush(stdin);
    gets(Infix);
    strcpy(Posfix,"");
    Infix2pofix(Infix,Posfix);
    printf("\n");
    puts(Posfix);
    printf("\n");
    printf("Gia tri bieu thuc la :%d",Eval(Posfix));
    return 0;
}
