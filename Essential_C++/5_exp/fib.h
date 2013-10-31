#ifndef FIB_H_INCLUDED
#define FIB_H_INCLUDED

#include<iostream>
#include<vector>
#include<string.h>
#include"seq.h"
using namespace std;

class fib : public seq
{
    public:
      int elem(int pos=1);
      char* what_I_am()
      {
          return "fib";
      }
      void printf(int i=1)
      {
          if (i<=seq1.size()) gen_elem(i);
          cout<<"The Fib ith Elem is:"<<seq1[i-1]<<endl;
      }
    private:
      void gen_elem(int pos=1 )
      {
          if (pos<=seq1.size()) return;
          for (int i=seq1.size();i<=pos;i++)
          {
              if (i<2) {seq1.push_back(1);continue;}
              seq1.push_back(seq1[i-1]+seq1[i-2]);
          }
      }
      vector<int> seq1;
};

#endif // FIB_H_INCLUDED
