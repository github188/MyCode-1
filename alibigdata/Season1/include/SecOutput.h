#ifndef SECOUTPUT_H
#define SECOUTPUT_H
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

class SecOutput
{
    public:
        SecOutput();
        virtual ~SecOutput();
        void work(int,char*);
    protected:
    private:
};

#endif // SECOUTPUT_H
