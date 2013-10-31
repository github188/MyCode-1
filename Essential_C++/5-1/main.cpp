#include"LIFO_stack.h"
#include"stack.h"
#include"Peek_Stack.h"

void test(Stack* a)
{
    try{
    a->pop();
    a->push(1);
    a->print();
    printf("%d\n",a->full());
    a->push(2);
    a->push(3);
    printf("%d\n",a->peek(2));
    printf("%d\n",a->pop());}
    catch (int o)
    {
        if (o==0) printf("The Stack is full!\n");
        if (o==-1) printf("The Stack is empty!\n");
    }
}

int main()
{
    LIFO_stack a;
    Peek_stack b;

    printf("The test is LIFO.\n");
    test(&a);

    printf("The test is Peek.\n");
    test(&b);

    return 0;
}
