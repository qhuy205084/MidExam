#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Address{
    char name[20];
    char tel[11];
    char email[20];
}address;

struct list{
    address data;
    struct list *next;
};
typedef struct list Node;
Node *makenewnode(address X){
    Node *temp;
    temp=(Node *)malloc(sizeof(struct list));
    temp->data=X;
    temp->next=NULL;
    return temp;
}
Node *addhead(Node *head,address X){
    Node *new;
    new=makenewnode(X);
    if (head==NULL)
        head=new;
    else{
        new->next=head;
    } 
    return new;
}

void search(Node *head,char s[],FILE *fo){
     while(head!=NULL){
        if (strcmp(head->data.name,s)==0)
            fprintf(fo,"%s  %s %s",head->data.name,head->data.tel,head->data.email);
        head=head->next;
     }
}
int main(){
    Node *head=NULL;
    address X;
    char s[30];
    FILE *fi,*fo;
    fi=fopen("input.txt","r");
    fo=fopen("output.txt","w+");
    while(fscanf(fi,"%s %s %s",X.name,X.tel,X.email)!=EOF){
       head=addhead(head,X);
    }
    printf("Nhap ten can tim kiem: ");
    fflush(stdin);
    gets(s);
    search(head,s,fo);
    fclose(fi);
    fclose(fo);
    return 0;
}