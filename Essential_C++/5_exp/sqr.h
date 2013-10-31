#ifndef SQR_H_INCLUDED
#define SQR_H_INCLUDED

#include<iostream>
#include<vector>
#include<string.h>
#include"seq.h"
using namespace std;

class sqr : public seq
{
    public:
      int elem(int pos=1);
      char* what_I_am()
      {
          return "sqr";
      }
      void printf(int i=1)
      {
          if (i<=seq1.size()) gen_elem(i);
          cout<<"The Sqr ith Elem is:"<<seq1[i-1]<<endl;
      }
    private:
      void gen_elem(int pos=1 )
      {
          if (pos<=seq1.size()) return;
          for (int i=seq1.size();i<=pos;i++) seq1.push_back(i*i+i*2+1);
      }
      vector<int> seq1;
};


#endif // SQR_H_INCLUDED
