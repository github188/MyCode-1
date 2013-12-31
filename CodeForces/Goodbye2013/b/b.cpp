#include<stdio.h>

int a[300];
int n;

int main()
{
    scanf("%d",&n);
    int sum=0;
    for (int i=0;i<n;i++) {scanf("%d",&a[i]);sum+=a[i];}
    char last='0';
    int cur=0;
    while (sum>0)
    {
        if ((last!='P')&&(a[cur]>0))
        {
            sum--;
            a[cur]--;
            last='P';
        } else
        if ((cur>0)&&((a[cur-1]>0)||(cur+1>=n)))
        {
            cur--;
            last='L';
        } else
        {
            cur++;
            last='R';
        }
        printf("%c",last);
    }
    return 0;
}
