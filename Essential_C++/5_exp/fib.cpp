#include"fib.h"

int fib::elem(int pos)
      {
          if (pos<=seq1.size()) return seq1[pos-1];
          gen_elem(pos);
          return seq1[pos-1];
      }
