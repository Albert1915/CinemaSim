#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char iden[100];
    struct node *link;
}*front=NULL, *rear=NULL;

void enter_q(struct node *start, char*cusin);
void display_q(struct node *start);
void keluar(struct node *start);

// void main()
// {
//     char cusin[100];
//     struct node *start = NULL;
//     int pilih;
//     //masuk antrian
//     puts("Cinema XXI Queue");
//     //Gimana caranya input beberapa string ke linkedlist sekaligus
//     printf("\nCustemer Identity: ");
//     while(1){
//         gets(cusin);
//         fflush(stdin);
//         enter_q(start,cusin);
//         display_q(start);
//         keluar(start);
//         display_q(start);
//     }
// }

void enter_q(struct node *start,char *cusin){
    struct node*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL){
        printf("ERROR");
        return;
    }
    strcpy(temp->iden,cusin);
    temp->link=NULL;
    if(front==NULL){
        front = temp;
    }
    else{
        rear->link = temp;
    }
    rear = temp;
}

void display_q(struct node*start)
{
    int i = 0;
    struct node *dp;
    if(front == NULL)
    {
        printf("\nUnderflow");
        return;
    }
    dp = front;
    printf("\nCinema Queue XXI:\n");
    while(dp!=NULL){
        printf("%s",dp->iden);
        dp = dp->link;
        i++;
    }
}

void keluar(struct node*start)
{
    char cusin[100];
    struct node *del;
    del = (struct node*)malloc(sizeof(struct node));
    if (front == NULL)
    {
        printf("\nUnderflow");
        return;
    }
    del = front;
    strcpy(cusin,del->iden);
    front = front ->link;
    free(del);
}
