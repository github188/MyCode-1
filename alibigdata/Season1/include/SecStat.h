#ifndef SECSTAT_H
#define SECSTAT_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<vector>

class SecStat
{
    public:
        SecStat();
        virtual ~SecStat();
        void work(double,double,double,double,int);
        void GetTimeForEachAction();
        void ConditionalPossibility();
    protected:
    private:
};

#endif // SECSTAT_H
