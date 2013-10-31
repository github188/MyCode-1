#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string.h>
#include<functional>
using namespace std;

struct check
{
  const bool operator()(int a)
  {
    return ((a&1)==0);
  }
};

/*
bool check(int a)
{
    return ((a&1)==0);
}
*/

int main()
{
    ifstream if1("if1.txt");
    ofstream of1("of1.txt"),of2("of2.txt");
    vector<int> vec;
    istream_iterator<int> is(if1);
    istream_iterator<int> eof;
    copy(is,eof,back_inserter(vec));
    vector<int>::iterator d=partition(vec.begin(),vec.end(),check());

    ostream_iterator<int> os1(of1," "),os2(of2,"\n");
    copy(vec.begin(),d,os1);
    copy(d,vec.end(),os2);

    return 0;
}
