#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlength 100

typedef struct Address{
      char name[20];
      char tel[11];
      char email[20];
}address;

typedef struct queue{
      address SV[maxlength];
      int front,rear;
}queue;

void makenullqueue(queue *Q){
    Q->front=-1;
    Q->rear=-1;
}
int emptyqueue(queue Q){
    return Q.front==-1;
}
int isfullqueue(queue Q){
    return Q.rear-Q.front+1==maxlength;
}
address front1(queue Q){
    if (!emptyqueue(Q))
        return (Q.SV[Q.front]);
    else printf("Hang rong\n");
}
void dequeue(queue *Q){
    if (emptyqueue(*Q))
    printf("Hang rong\n");
    else if(Q->front==Q->rear)
            makenullqueue(Q);
        else Q->front++;
}
void enqueue(queue *Q,address X){
    if (!isfullqueue(*Q)){
        if (emptyqueue(*Q)) Q->front=0;
        if (Q->rear==maxlength-1)
        {
            int i;
            for(i=Q->front;i<Q->rear;i++)
              Q->SV[i-Q->front]=Q->SV[i];
              Q->rear=Q->rear-Q->front;
              Q->front=0;
        }
        Q->rear++;
        Q->SV[Q->rear]=X;
    }else
    printf("\nHang day!!\n");
}
void printQueue(queue Q){
    address Z;
    printf("cac sinh vien trong tep:");
    while(!emptyqueue(Q)){
        Z=front1(Q);
        printf("%s\n",Z.name);
        dequeue(&Q);
    }
}

int main(){
    FILE *fi,*fo;
    queue Q;
    address temp;
    char s[23];
    makenullqueue(&Q);
    fi=fopen("input.txt","r");
    fo=fopen("output.txt","w+");
    while(fscanf(fi,"%s %s %s",temp.name,temp.tel,temp.email)!=EOF){
           enqueue(&Q,temp);
    }
    printf("Nhap ten can tim kiem:");
    fflush(stdin);
    gets(s);
   while (!emptyqueue(Q))
   {
       temp=front1(Q);
       if(strcmp(temp.name,s)==0)
       fprintf(fo,"%s %s %s\n",temp.name,temp.tel,temp.email);
       dequeue(&Q);
   }
   
   fclose(fi);
   fclose(fo);
   return 0;      
}