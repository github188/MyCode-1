#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

class Stack
{
    public:
        Stack() {Size = 0;}

        virtual int pop()
        {
            if (Size==0) throw -1;
            return a[--Size];
        }

        virtual void push(int o)
        {
            if (Size>=max_size) throw 0;
            a[Size++] = o;
        }

        virtual int size() {return Size;}

        virtual bool empty() {return Size==0;}

        virtual bool full() {return Size==max_size;}

        virtual int peek(int o) = 0;
        virtual void print() = 0;

    protected:
        static const int max_size=1024;
        int Size;
        int a[1024];
};

#endif // STACK_H_INCLUDED
