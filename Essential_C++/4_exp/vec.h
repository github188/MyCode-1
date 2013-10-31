#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED
#include "it.h"

class Vec
{
    public:
    typedef Vec_It itearator;
    void push(int);
    void pop(int);
    int size();
    int get_elem(int);

    private:
      int num[3000];
      int len;
};

#endif // VEC_H_INCLUDED
