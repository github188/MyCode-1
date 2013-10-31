#ifndef LIFO_STACK_H_INCLUDED
#define LIFO_STACK_H_INCLUDED

#include"stack.h"
#include<stdio.h>

class LIFO_stack : public Stack
{
    public:
        virtual int peek(int o) {return -1;}
        virtual void print()
        {
            if (Size>0) printf("LIFO_STACK's top element is %d !\n",a[Size-1]);
        }

};

#endif // LIFO_STACK_H_INCLUDED
