#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
class Solution {
public:
    int getNum(int A[],int n,int i,int status)
    {
        if (status) return A[i-1];
        return A[n-i];
    }
    double getAns(int A[],int m,int a1,int B[],int n,int b1,int x,int y)
    {
        if (x==0)
        {
            if ((m+n)&1) return getNum(B,n,y,b1);
            else
            {
                if ((y>1)&&(getNum(B,n,y-1,b1)>=getNum(A,m,m,a1))) return (double)(getNum(B,n,y,b1)+getNum(B,n,y-1,b1))/2.0;
                else return (double)(getNum(B,n,1,b1)+getNum(A,m,m,a1))/2.0;
            }
        }
        if (y==0)
        {
            if ((m+n)&1) return getNum(A,m,x,a1);
            else return (double)(getNum(A,m,1,a1)+getNum(B,n,n,b1))/2.0;
        }
        if ((m+n)&1) return (getNum(A,m,x,a1)<getNum(B,n,y,b1)?getNum(A,m,x,a1):getNum(B,n,y,b1));
        else
        {
            double d[4];
            d[0]=getNum(A,m,x,a1);
            d[1]=getNum(B,n,y,b1);
            d[0]=d[0]<d[1]?d[0]:d[1];
            if (x-1>0) d[2]=getNum(A,m,x-1,a1);
            else d[2]=getNum(B,n,1,b1);
            if (y-1>0) d[3]=getNum(B,n,y-1,b1);
            else d[3]=getNum(A,m,1,a1);
            d[2]=d[2]>d[3]?d[2]:d[3];
            sort(d,d+4);
            return (d[0]+d[2])/2.0;
        }
    }

    int compNum(int A[],int m,int a1,int B[],int n,int b1,int x,int y)
    {
        return getNum(A,m,m-x+1,a1)<getNum(B,n,n-y+1,b1)?getNum(A,m,m-x+1,a1):getNum(B,n,n-y+1,b1);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m>n)
        {
            int *c=A;A=B;B=c;
            int tmp=m;m=n;n=tmp;
        }
        if (m+n==1) return B[0];
        if (n==0) return 0;
        int a1=0,b1=0;
        if ((m>1)&&(A[0]<A[m-1])) a1=1;
        if ((n>1)&&(B[0]<B[n-1])) b1=1;
        int k=(m+n)/2;
        if (m==0)
        {
            if (n==2) return double(B[0]+B[1])/2.0;
            return getAns(A,m,a1,B,n,b1,0,k+1);
        }
        if (k>=m)
        {
            if (getNum(B,n,k-m+1,b1)>=getNum(A,m,m,a1)) return getAns(A,m,a1,B,n,b1,0,k-m+1);
        }
        if (k<=n)
        {
            if (getNum(B,n,k,b1)<=getNum(A,m,1,a1)) return getAns(A,m,a1,B,n,b1,1,k<n?k+1:0);
        }
        k=m+n-k;
        int l=1,r=min(m-1,k-1);
        while (l<r)
        {
            int x,y;
            if (r-l==1) {x=l;y=r;}
            else {x=l+(r-l+1)/3-1;y=r-(r-l+1)/3+1;}
            if (compNum(A,m,a1,B,n,b1,x,k-x)>=compNum(A,m,a1,B,n,b1,y,k-y)) r=y-1;
            else l=x+1;
        }
        return getAns(A,m,a1,B,n,b1,m-l+1,n-(k-l)+1);
    }
} a;
int main()
{
    int b[3],c[3];
    b[0]=1;b[1]=2;b[2]=2;
    c[0]=1;c[1]=2;c[2]=3;
    printf("%.2f\n",a.findMedianSortedArrays(b,3,c,3));
    return 0;
}
