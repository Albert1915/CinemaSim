#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "custServ.h"


void getPayment(char* name, char* film) {
    int money;
    int changes;
    char* eq = calloc(255, sizeof(char));

    printf("Nama: %s\nFilm: %s\nBiaya: %d\n", name, film, TIC_PRICE);
    printf("Masukkan nominal pembayaran: Rp. ");
    scanf("%d", &money);
    if (money < TIC_PRICE) return;
    snprintf(eq, 255, "%d %d -", money, TIC_PRICE);
    changes = calculate(eq);
    
    if (changes != 0) {
        printf("Kembalian anda: %d\nTerima kasih! :)\n\n", changes);
    }
};

void enter_q(queue* cust, char* cusin) {
    queue newCust = malloc(sizeof(struct queue_t));
    if (newCust == NULL) {
        printf("ERROR Occured!\n");
        return;
    }

    newCust->iden = strdup(cusin);
    newCust->link = NULL;

    if (*cust == NULL) {
        *cust = newCust;
        if (cust == NULL) {
            printf("E!\n");
            exit(-1);
        }
    } else {
        queue temp = *cust;
        while (temp->link) {
            temp = temp->link;
        }
        temp->link = newCust;
    }
}

void display_q(queue cust) {
    if (cust == NULL) return;
    queue temp = cust;
    printf("Luminous Cinema's Queue:\n");
    do {
        printf("[ ] %s\n", temp->iden);
        temp = temp->link;
    } while (temp != NULL);
}

char* getCust(queue* cust) {
    if (*cust == NULL) return NULL;
    char* name = calloc(255, sizeof(char));
    name = strdup((*cust)->iden);
    if (!(*cust)->link) {
        *cust = NULL;
        return name;
    } else {
        *cust = (*cust)->link;
        return name;
    }
}

int getQueueSize(queue cust) {
    if (!cust) return 0;
    queue temp = cust;
    int ctr = 1;
    while (temp->link) {
        ctr++;
        temp = temp->link;
    } 
    return ctr;
}

static void initStack(stack* eqStack, size_t size) {
    *eqStack = malloc(sizeof(stack));
    (*eqStack)->top = -1;
    (*eqStack)->data = malloc(size*sizeof(int));
}

static int isEmpty(stack eqStack) {
    return eqStack->top == -1;
}

static int peek(stack eqStack) {
    return eqStack->data[eqStack->top];
}

static void push(stack *eqStack, int val) {
    (*eqStack)->data[++(*eqStack)->top] = val;
}

static int pop(stack *eqStack) {
    if (!isEmpty(*eqStack)) {
        return (*eqStack)->data[(*eqStack)->top--];
    }
    return -1;
}

static int isOperand(char val) {
    return ((val - '0') >= 0 && (val - '0') <= 9);
}

static int calculate(char* exp) {
    stack* eqStack; 
    initStack(eqStack, strlen(exp));

    if (!eqStack) return -1;

    for (int i=0; exp[i]; i++) {
        if (exp[i] == ' ') continue;
        else if (isOperand(exp[i])) {
            int num = 0;
            while (isOperand(exp[i])) {
                num = num*10 + (int)(exp[i]-'0');
                i++;
            }
            i--;

            push(eqStack, num);
        } else {
            int val1 = pop(eqStack);
            int val2 = pop(eqStack);

            switch (exp[i]) {
                case '+': push(eqStack, val2+val1); break;
                case '-': push(eqStack, val2-val1); break;
                case '*': push(eqStack, val2*val1); break;
                case '/': push(eqStack, val2/val1); break;
            }
        }
    }
    return pop(eqStack);
}
