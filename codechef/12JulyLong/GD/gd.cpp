#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char s[200],t[200];
int main()
{

    int n=100,m=10000;

    while (true)
    {
        srand(time(NULL));
        n=rand()%m+1;
        while (n==1) n=rand()%m+1;
        FILE* f=fopen("1.txt","w");
        fprintf(f,"%d\n",n);
        for (int i=1;i<n;i++) fprintf(f,"%d %d\n",i,rand()%i);
        for (int i=0;i<n;i++) fprintf(f,"%d ",rand()%10000+1);
        fprintf(f,"\n%d\n",m);
        for (int i=0;i<m;i++)
        {
            int k=(rand()&3);
            if (k==1)
            {
                fprintf(f,"C %d %d %d\n",rand()%n,rand()%n,rand()%10000);
            } else fprintf(f,"F %d %d\n",rand()%n,rand()%n);
        }
        fclose(f);

        system("DGCD.exe");
        system("DGCD_test.exe");
        FILE* f1=fopen("2(1).txt","r");
        FILE* f2=fopen("2(2).txt","r");
        bool check=true;
        int k=0;
        while (fgets(s,200,f1)!=NULL)
        {
            fgets(t,200,f2);
            if (strlen(s)!=strlen(t)) {check=false;break;}
            for (int i=0;i<strlen(s);i++) if (s[i]!=t[i]){check=false;break;}
            k++;
            if (!check) break;
        }
        if (check==false) {printf("%d\n",k);break;}
        fclose(f1);
        fclose(f2);
    }
    return 0;
}
