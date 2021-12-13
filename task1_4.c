#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlength 10
typedef struct {
	char name[20];
	char tel[13];
	char email[20];
}address;
typedef struct queue{
    address element[maxlength];
    int front,rear;
}queue;
void makenullqueue(queue *Q){
    Q->front=-1;
    Q->rear=-1;
}
int isEmpty(queue Q){
    return Q.front==-1;
}
int isFull(queue Q){
    return Q.rear-Q.front+1==maxlength;
}

void printRmAdd (address *r)
{
    printf("Du lieu da bi xoa:\n");
    printf("%s\t%s\t%s\n", r->name, r->tel, r->email);
}

void enqueue(queue *Q,address X){
    if (!isFull(*Q)){
        if (isEmpty(*Q)) Q->front=0;
        if(Q->rear==maxlength-1){
            int i;
            for (i=Q->front;i<=Q->rear;i++)
                Q->element[i-Q->front] = Q->element[i];
            Q->rear = Q->rear - Q->front;
            Q->front=0;
        }
        Q->rear++;
        Q->element[Q->rear]=X;
    } else{
        printRmAdd(&Q->element[0]);
        int i;
        for (i=0; i<9; i++)
            Q->element[i] = Q->element[i+1];
        Q->rear--;
        enqueue(Q,X);
    }
}

void fillqueue(queue *Q){
    address X;
    FILE *fi;
    fi=fopen("input.txt","r");
    while(fscanf(fi,"%s %s %s",X.name,X.tel,X.email)!=EOF)
    {
        enqueue(Q,X);
    }
    fclose(fi);
}

int main(){
    queue Q;
    makenullqueue(&Q);
    fillqueue(&Q);
    address X;
    char k;
    printf("Nhap '1' de tiep tuc nhap du lieu.\n");
    fflush(stdin);
    scanf("%c", &k);
    do{
        printf("Name: "); fflush(stdin); gets(X.name);
        printf("Telephone number: "); fflush(stdin); gets(X.tel);
        printf("Email: "); fflush(stdin); gets(X.email);
        enqueue(&Q,X);
        int i;
        printf("----------\n");
        printf("Cac phan tu trong hang doi hien tai:\n");
        for (i=0; i<10; i++)
            printf("%d) %s\t%s\t%s\n",i+1, Q.element[i].name, Q.element[i].tel, Q.element[i].email);
        printf("Nhap '1' de tiep tuc nhap du lieu.\n");
        fflush(stdin);
        scanf("%c", &k);
    } while (k=='1');
    return 0;
}