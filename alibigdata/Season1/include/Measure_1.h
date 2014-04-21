/***
The class is calculating the value.

CreatedBy: Chenjiyuan,20140315
***/
#include "../include/Base.h"
#ifndef MEASURE_1_H
#define MEASURE_1_H


class Measure : public BasedMeasure

{
    public:
        Measure();
        virtual ~Measure();
        void Work(char*,double,double,double);
    protected:
    private:
};

#endif // MEASURE_1_H
