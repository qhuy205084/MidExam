#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAXlength 10
typedef struct Address{
	char name[20];
	char tel[11];
	char email[20];
}address;

address A[MAX];

int BinarySearch(address *A, char name[], int n)
{
    int low, mid, high;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(strcmp(A[mid].name,name)<0)
            low = mid + 1;
        else if(strcmp(A[mid].name,name)>0)
            high = mid - 1;
        else return mid;
    }
    return -1;
}

void input()
{
    FILE *fi = fopen("input.txt", "r");
    if(fi == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            fscanf(fi,"%s %s %s\n", A[i].name, A[i].tel, A[i].email);
        }
        fclose(fi);
    }
}

void output(int i)
{   
    if(i==-1)
    {
        printf("Ten khong co trong danh sach.\n");
    }
    else
    {
        FILE *fo = fopen("output.txt","w+");
        fprintf(fo,"%s %s %s\n", A[i].name, A[i].tel, A[i].email);
        fclose(fo);
    }
}

int main()
{
    input();
    char name[20];
    printf("Nhap ten can tim kiem: ");
    gets(name);
	fflush(stdin);
    output(BinarySearch(A,name,10));
	return 0;
}