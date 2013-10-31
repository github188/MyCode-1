#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
string s;
int a[5],b[5];

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        for (int i=0;i<5;i++) a[i]=b[i]=0;
        //gets(s);
        cin>>s;
        int len=s.length();
        for (int i=0;i<len;i++)
        {
            if (s[i]=='4') {a[1]++;continue;}
            if (s[i]=='7') {a[3]++;continue;}
            if (s[i]<'4') {a[0]++;continue;}
            if (s[i]<'7') {a[2]++;continue;}
            a[4]++;continue;
        }
        cin>>s;
        for (int i=0;i<len;i++)
        {
            if (s[i]=='4') {b[1]++;continue;}
            if (s[i]=='7') {b[3]++;continue;}
            if (s[i]<'4') {b[0]++;continue;}
            if (s[i]<'7') {b[2]++;continue;}
            b[4]++;continue;
        }
        int a7,a4;
        a7=a4=0;
        if (a[3]>=b[2]) {a7+=b[2];a[3]-=b[2];b[2]=0;}
        else {a7+=a[3];b[2]-=a[3];a[3]=0;}
        if (a[3]>=b[0]) {a7+=b[0];a[3]-=b[0];b[0]=0;}
        else {a7+=a[3];b[0]-=a[3];a[3]=0;}

        if (b[3]>=a[2]) {a7+=a[2];b[3]-=a[2];a[2]=0;}
        else {a7+=b[3];a[2]-=b[3];b[3]=0;}
        if (b[3]>=a[0]) {a7+=a[0];b[3]-=a[0];a[0]=0;}
        else {a7+=b[3];a[0]-=b[3];b[3]=0;}

        if (a[3]>=b[1]) {a7+=b[1];a[3]-=b[1];b[1]=0;}
        else {a7+=a[3];b[1]-=a[3];a[3]=0;}
        if (b[3]>=a[1]) {a7+=a[1];b[3]-=a[1];a[1]=0;}
        else {a7+=b[3];a[1]-=b[3];b[3]=0;}
        if (a[3]<=b[3]) a7+=a[3]; else a7+=b[3];

        if (a[1]>=b[0]) {a4+=b[0];a[1]-=b[0];b[0]=0;}
        else {a4+=a[1];b[0]-=a[1];a[1]=0;}
        if (b[1]>=a[0]) {a4+=a[0];b[1]-=a[0];a[0]=0;}
        else {a4+=b[1];a[0]-=b[1];b[1]=0;}
        if (a[1]<=b[1]) a4+=a[1]; else a4+=b[1];

        for (int i=0;i<a7;i++) printf("7");
        for (int i=0;i<a4;i++) printf("4");
        printf("\n");
    }
    return 0;
}
