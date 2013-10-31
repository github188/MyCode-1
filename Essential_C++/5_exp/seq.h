#ifndef SEQ_H_INCLUDED
#define SEQ_H_INCLUDED

class seq
{
    public:
      virtual int elem(int pos)=0;
      virtual char* what_I_am() = 0;
      virtual void printf(int i=1) = 0;
    private:
      virtual void gen_elem(int pos=1 ) = 0;

};

#endif // SEQ_H_INCLUDED
