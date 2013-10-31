#ifndef SNOWCLEANING_H
#define SNOWCLEANING_H
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

class SnowCleaning
{
    public:
        SnowCleaning();
        virtual ~SnowCleaning();
        int init(int boardSize, int salary, int snowFine);
        vector < string > nextDay(vector < int  > snowFalls);
    protected:
    private:
};

#endif // SNOWCLEANING_H
