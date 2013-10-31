#ifndef PEEK_STACK_H_INCLUDED
#define PEEK_STACK_H_INCLUDED

#include"stack.h"
#include<stdio.h>

class Peek_stack : public Stack
{
    public:
        virtual int peek(int o) {return o<=Size?a[o-1]:-1;}
        virtual void print()
        {
            if (Size>0) printf("Peek_STACK's top element is %d !\n",a[Size-1]);
        }

};


#endif // PEEK_STACK_H_INCLUDED
