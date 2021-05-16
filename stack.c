#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h> // pow()

const int MAX_STACK = 50;

typedef struct {
    int top;
    int *data;
} stack;

// Stack Op
stack *createStack(size_t size);
int isFull(stack *obj);
int isEmpty(stack *obj);
int push(stack *obj, char val);
char pop(stack *obj);
char peek(stack *obj);
void clear(stack *obj);
// Utils
int calculate(char *val);
int opVal(char val);
int isOperand(char val);
// Operation
int add(int a, int b);
int sub(int a, int b);
int multi(int a, int b);
int division(int a, int b);
int changes(int cash, int cus);
int find (int div[], int size, int money);
double power(int a, int b);
int shared[100];
// Main Program
int main() {
    char op[MAX_STACK];
    char ml[MAX_STACK];
    char cl[MAX_STACK];
    int tot_price;
    int pay;
    printf("Masukkan harga tiket (hanya angka selain 0 tanpa Rp  dan tanpa . ataua , dan): ");
    scanf("%s", op);
    printf("Masukkan banyak tiket yang dibeli(awali dengan *):");
    scanf("%s", ml);
    strcpy(cl,strcat(op, ml));
    tot_price = calculate(op);
    printf("\nTotalnya %d Kak", tot_price);
    printf("Masukkan uang yang diberikan:");
    scanf("%d", &pay);
    changes(tot_price,pay);
    return 0;
}
//changes
int changes(int cash, int cus){
    int money,mod,i;
    if (cash > cus){
        printf("Uang kurang");
    }
    else if(cash == cus){
        printf("Uang pas");
    }
    else{
        money = cus - cash;
        int div[]={100000, 50000, 20000, 10000, 5000, 2000, 1000, 500};
        int size = sizeof(div)/sizeof(div[0]);
        int MinChanges = find(div,size,money);
        printf("Total Lembar : %d", MinChanges);
        printf("Pecahannya adalah: \t");
        for(i=0; i<MinChanges;i++){
            printf("%d ", shared[i]);
        }
    }
    return 0;

}
//optimal changes
int find(int div[], int size, int money){
    int i, count = 0;
    for(i = 0; i<size; i++){
        while (money >= div[i]){
            money -= div[i];
            shared[count] = div[i];
            count++;

        }
        if(money ==0){
            break;
        }
    }
    return count;
}
// Implementation
int calculate(char *val) {
    char a, b;
    int i, j;
    int res = 0;
    size_t len = strlen(val);
    char save[len];
    stack *postfix = createStack(MAX_STACK);
    if (!postfix) return -1;

    // Conversion
    for (i=0, j = -1; val[i]; ++i) {
        if (isOperand(val[i])) {
            val[++j] = val[i];
        } else if (val[i] == '(') {
            push(postfix, val[i]);
        } else if (val[i] == ')') {
            while (!isEmpty(postfix) && peek(postfix) != '(') {
                val[++j] = pop(postfix);
            }
            pop(postfix);
        } else {
            while(!isEmpty(postfix) && opVal(val[i]) <= opVal(peek(postfix))) {
                val[++j] = pop(postfix);
            }
            push(postfix, val[i]);
        }
    }

    while (!isEmpty(postfix)) {
        val[++j] = pop(postfix);
    }
    val[++j] = '\0';
    clear(postfix);
    printf("Postfix: %s\n", val);

    // Calculation
    for (i = 0; i < len; i++) {
        if (isOperand(val[i])) {
            push(postfix, val[i]-'0');
        } else {
            b = pop(postfix);
            a = pop(postfix);
            if (val[i] == '+') res = add(a, b);
            if (val[i] == '-') res = sub(a, b);
            if (val[i] == '*') res = multi(a, b);
            if (val[i] == '/') res = division(a, b);
            if (val[i] == '^') res = power(a, b);
            push(postfix, res);
        }
    }
    printf("Result: %d", res*10000);
    return res*10000;
}

stack *createStack(size_t size) {
    stack *Stack = malloc(sizeof(stack));
    
    Stack->top = -1;
    Stack->data = malloc(size * sizeof(int *));

    return Stack;
}

int isFull(stack *obj) {
    if (obj->top == MAX_STACK-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(stack *obj) {
    if (obj->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int push(stack *obj, char val) {
    if (!isFull(obj)) {
        obj->data[++obj->top] = val; 
    } else {
        return -1;
    }
}

char pop(stack *obj) {
    if (!isEmpty(obj)) {
        obj->top--;
        return obj->data[obj->top+1];
    } else {
        return -1;
    }
}

int opVal(char val) {
    switch(val) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void clear(stack *obj) {
    obj->top = -1;
}

char peek(stack *obj) {
    return obj->data[obj->top];
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int multi(int a, int b) {
    return a*b;
}

int division(int a, int b) {
    return a/b;
}

double power(int a, int b) {
    return pow(a, b);
}

int isOperand(char val) {
    return ((val - '0') >= 0 && (val - '0') <= 9);
}
