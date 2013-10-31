#include<stdio.h>
#include<string.h>
struct node
{
    int a[26];
    bool ended,must,mustnot;
    int v;
};

node a[1700];
int f[1700][100][260];

