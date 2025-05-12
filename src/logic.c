#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100 // Max operator/operand size
#define MAXVAL  100 // Max depth for value stack
#define NUMBER  '0' //Signal for found number  


/*  Reverse Polish calculator:
    Each operand is pushed onto stack
    When operator arrives, valid num of operands is popped, then the operator is applied
    Result gets pushed back onto stack
*/

// Stack pointer
int sp = 0;
double val[MAXVAL];

// Push value to stack
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, cannot push %g\n", f);
    }
}

// Pop value and return value from the stack
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: cannot pop value, stack empty %d", sp);
        return 0.0;
    }
}

int getop(char s[]);

int main() {
    printf("startup ...");
    int type;
    // Stores values for calculations that need to be performed in order (division and subtracting)
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