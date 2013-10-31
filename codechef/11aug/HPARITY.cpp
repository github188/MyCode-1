#include<stdio.h>

bool a[100][100];

int main()
{
    for (int i=1;i<100;i++) a[0][i]=a[i][0]=true;
    a[0][0]=true;
    for (int i=1;i<100;i++) for (int j=1;j<100;j++)
    {
        if (a[i][j-1]==a[i-1][j]) {a[i][j]=false;} else {a[i][j]=true;}
    }
    int sum=0;
    for (int i=0;i<=15;i++) {
     for (int j=0;j<=15;j++) if (a[i][j]) {sum++;printf("1");} else {printf("0");}printf("\n"); }  
    printf("%d\n",sum);
    return 0;
    
}
