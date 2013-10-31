int n, k;
char p[20];
int DFS(int c){
    char tmp[20];
    FF(i,n+1)   tmp[i]= p[i];
    int j= -1;
    bool flag= false;
    if (c==0){
        FD(i,n,1){
            if (p[i]=='_')   {
                j= i;
            }else if (p[i]=='a' && j!=-1){
                p[j]= 'a';
                p[i]= '_';
                flag= true;
                int t= DFS(1);
                if (t==0)   return i;   // 找到最右的 导致B先手必败策略,那么这就是必胜的
                FF(x,n+1)   p[x]= tmp[x];
            }
        }
        if (flag== true)    // 没找到 导致B先手必败的策略，则这是个A先手必败
            return 0;
        else
            return 1;       //  这是 A没法移动的情况，就是获胜喽

    }else {
        FOR(i,1,n){
            if (p[i]=='_') j= i;
            else if (p[i]=='b' && j!=-1){
                p[j]= 'b';
                p[i]= '_';
                flag= true;
                int t= DFS(0);
                if (t==0)   return 1;
                FF(x,n+1)   p[x]= tmp[x];
            }
        }
        if (flag)   return 0;
        else return 1;

    }

}

int main(){

    for(n=3;n<=10;n++) for(k=1;k<=n/2;k++){
        printf("\n n= %d  k= %d ",n,k);
        p[0]= p[n+1] = '|';
        FOR(i,1,n)  p[i]= '_';
        FF(i,k) p[i+1]= 'a';
        FF(i,k) p[i+n-k+1]= 'b';
        int t= DFS(0);
        if (t>0)    printf("Alice  t=%d\n", t);
        else printf("Bob\n");
    }


}
