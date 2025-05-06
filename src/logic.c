#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100
#define NUMBER  '0' //Signal for found number  


/*  Reverse Polish calculator:
    Each operand is pushed onto stack
    When operator arrives, valid num of operands is popped, then the operator is applied
    Result gets pushed back onto stack
*/


void push(double f);
double pop(void);
int getop(char s[]);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
             printf("error: zero divisor\n");
            break;     
        case '\n':
            printf("\t.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
        return 0;
    }
}
