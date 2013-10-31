
#ifndef IT_H_INCLUDED
#define IT_H_INCLUDED

class Vec_It
{
    public:
      Vec_It operator--()
      {
          if (index>0)
          {
              index--;
          } else
          {
              index=-1;
          }
          return *this;
      }


      Vec_It operator++()
      {
          index++;
          return *this;
      }

    private:
      int index;
};

#endif // IT_H_INCLUDED
