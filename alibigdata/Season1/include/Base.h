/***
The class is only the interface for other class.

CreatedBy: Chenjiyuan,20140315
***/

#ifndef BASE_H
#define BASE_H

class BasedInit
{
    virtual void Work(char*,int) {};
};

class BasedMeasure
{
    virtual void Work(char*,double,double,double) {};
};


class BasedCF
{
    virtual void Work(char*,char*,char*,int) {};
};


class BasedOutput
{
    virtual void Work(char*,char*,char*,int,int,int,int,int) {};
};
#endif // BASE_H
