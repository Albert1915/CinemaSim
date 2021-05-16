#ifndef __NZ_CUSTSERV__
    #define __NZ_CUSTSERV__
    #define TIC_PRICE 45000
    struct queue_t{
        char* iden;
        struct queue_t *link;
    };
    typedef struct queue_t* queue;

    struct stack_t {
        int top;
        int *data;
    };
    typedef struct stack_t* stack;

    void getPayment();
    void enter_q(queue* cust, char* cusin);
    void display_q(queue cust);
    char* getCust(queue* cust);
    void getPayment(char* name, char* film);
    int getQueueSize(queue cust);
    static void initStack(stack* eqStack, size_t size);
    static int isEmpty(stack eqStack);
    static int peek(stack eqStack);
    static void push(stack* eqStack, int val);
    static int pop(stack* eqStack);
    static int isOperand(char val);
    static int calculate(char* exp);
#endif