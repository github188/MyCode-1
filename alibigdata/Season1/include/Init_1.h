/***
The class is transform the raw data to 4 matrix. Different matrix means the different status.

CreatedBy: Chenjiyuan,20140315
***/

#ifndef INIT_1_H
#define INIT_1_H

#include"Base.h"

class Init : public BasedInit
{
    public:
        Init();
        virtual ~Init();
        void Work(char*,int);
};

#endif // INIT_1_H
