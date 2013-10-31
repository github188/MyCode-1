#include<stdio.h>

bool a[100][100][100];

int main()
{
    //for (int i=1;i<100;i++) a[0][i]=a[i][0]=true;
    a[0][0][0]=true;
    for (int i=0;i<100;i++) for (int j=0;j<100;j++)for (int k=0;k<100;k++)// for (int l=0;l<100;l++)
    if (i+j+k!=0)
    {
        bool b,c,d,e;
        if (i>0) {b=a[i-1][j][k];} else {b=false;}
        if (j>0) {c=a[i][j-1][k];} else {c=false;}
        if (k>0) {d=a[i][j][k-1];} else {d=false;}
       // if (l>0) {e=a[i][j][k][l-1];} else {e=false;}
        
        if (!(((b^c)^d))) {a[i][j][k]=false;} else {a[i][j][k]=true;}
    }
    int sum=0;
    for (int i=0;i<=89;i++) {
     for (int j=0;j<=37;j++) for (int k=0;k<=23;k++)if (a[i][j][k]) {sum++;} }   
    printf("%d\n",sum);
    return 0;
    
}
