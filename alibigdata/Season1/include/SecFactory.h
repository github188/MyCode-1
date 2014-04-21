#ifndef SECFACTORY_H
#define SECFACTORY_H

#include "../include/SecStat.h"
#include "../include/SecCalc.h"
#include "../include/SecOutput.h"

class SecFactory
{
    public:
        SecFactory();
        virtual ~SecFactory();
        SecStat Stat;
        SecCalc Calc;
        SecOutput Out;
    protected:
    private:
};

#endif // SECFACTORY_H
