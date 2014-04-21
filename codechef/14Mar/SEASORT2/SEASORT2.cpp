#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10000],b[10000],Ans[10000][2];
int Ans_Num=0;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);b[i]=a[i];
    }
    sort(b,b+n);
    for (int i=n-1;i>=0;i--)
    if (b[i]!=a[i])
    {
        int j=i-1;
        while (a[j]!=b[i]) j--;
        Ans[Ans_Num][0]=j;Ans[Ans_Num++][1]=i;
        for (int k=0;k<(i-j+1)/2;k++)
        {
            int tmp=a[j+k];a[j+k]=a[i-k];a[i-k]=tmp;
        }
    }
    printf("%d\n",Ans_Num);
    for (int i=0;i<Ans_Num;i++) printf("%d %d\n",Ans[i][0]+1,Ans[i][1]+1);
    return 0;
}
