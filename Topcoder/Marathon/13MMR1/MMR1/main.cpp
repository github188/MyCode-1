#include "SnowCleaning.h"
#include<fstream>
using namespace std;
SnowCleaning SC;
ofstream f1;

int main()
{
    int boardSize,salary,snowFine;
    scanf("%d%d%d",&boardSize,&salary,&snowFine);
    SC.init(boardSize, salary, snowFine);
    for (int t=0; t < 2000; t++)
    {
        int snowCnt;
        scanf("%d",&snowCnt);
        vector< int > snowFalls;snowFalls.clear();
        for (int i=0; i < 2*snowCnt; i++)
        {
            int x;scanf("%d",&x);snowFalls.push_back(x);
        }

        vector< string > ret = SC.nextDay(snowFalls);
        printf("%d\n",ret.size());
        for (int i=0; i < ret.size(); i++)
        {
            f1.open("1.txt",ios::app);
            f1<<ret[i]<<endl;
            f1.close();
            cout<<ret[i]<<endl;
        }
        fflush(stdout);
    }
    return 0;
}
