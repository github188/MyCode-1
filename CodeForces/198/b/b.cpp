#include"stdio.h"
unsigned int j,n,p,i,k1,k2,k3,len,a,D[100002];

int main(void)
{
          scanf("%u",&p);
          len=0;

          for(i=1;i<=p;i++)
          {
               scanf("%u",&a);

               if(a>D[len]){
                  len++;
                  D[len]=a;
               }
               else{
                  k1=0; k2=len;

                  while(k2-k1>1){
                     k3=(k2+k1)/2;
                     if(D[k3]>=a) k2=k3;
                     else         k1=k3;
                  }

                  D[k2]=a;
               }
          }
          printf("%u\n",len);


     return 0;
}
