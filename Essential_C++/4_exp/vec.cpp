#include"vec.h"

void Vec::push(int o)
{
    num[len++]=o;
}

void Vec::pop(int o)
{
    if (len!=0) len--;
}

int Vec::size()
{
    return len;
}

int Vec::get_elem(int o)
{
    if ((o<0)||(o>=len)) return -1;
    return num[o];
}
