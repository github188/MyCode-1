/***
This is the main function. The algorithm has 4 steps:
1. Transform the raw data to matrix data;
2. Calculte the measure for used-item pair;
3. CF;
4. Output the result;
***/

#include<stdio.h>
#include<math.h>

///The following libs are from this project
/*
#include "./include/Base.h"
#include "./include/Init_1.h"
#include "./include/Measure_1.h"
#include "./include/SVD_1.h"
#include "./include/Output_1.h"
#include "./include/CalcF1.h"
*/
///The following part is a new method after Apr. 8th
#include "./include/SecFactory.h"
int main()
{
    /*
    int o=1;
    int fav_num=30;
    int brand_num_left=3000,brand_num_right=4000,brand_click=2000;
    double a1=0.025,a2=0.075,a3=0.125;
    int last_month=8;
    //Init t1;t1.Work("t_alibaba_data.csv",last_month);
    Measure t2;t2.Work("matrix.txt",a1,a2,a3);
    SVD t3;t3.Work("matrix.txt","item_fav.txt","user_fav.txt",fav_num);
    Output t4;t4.Work("item_fav.txt","user_fav.txt","result9_140404.txt",fav_num,brand_num_left,brand_num_right,last_month,brand_click);
    if (last_month<8) CalcF1("result8.txt");
    */

    ///Apr 8th
    ///4月10号更改了一个规则，就是只考虑最后一周的情况
    ///4月11号把品牌数2500->3000
    ///4月12号把a1 0.05->0.1
    ///4月13号把品牌数3000->3200
    double a1=0.05,a2=2,a3=0.15,a4=0.25;
    int last_month=8,brand_num=3200;
    SecFactory a;
    //a.Stat.GetTimeForEachAction();
    //a.Stat.ConditionalPossibility();
    a.Stat.work(a1,a2,a3,a4,last_month);  ///Get some statistic information about the dataset.
    a.Out.work(brand_num,"result9_140413.txt");
    return 0;
}
