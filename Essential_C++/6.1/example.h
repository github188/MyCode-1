#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
template<typename elemtype>
class example
{
    public:
      example(elemtype min,elemtype max):_min(min),_max(max)
      {
          _size=2;
          parray=(elemtype*)malloc(2*sizeof(elemtype));
      }
      example(const elemtype* array,int size):parray(array),_size(size) {}
      elemtype& operator[](int index) { return index<_size?parray[index]:-1;}
      elemtype min() {return _min;}
      elemtype max() {return _max;}
      void min(elemtype o)
      {
          _min=o;
          for (int i=0;i<_size;i++) if (parray[i]<o) parray[i]=o;
      }
      void max(elemtype o)
      {
          _max=o;
          for (int i=0;i<_size;i++) if (parray[i]>o) parray[i]=o;
      }
      int count(elemtype value)
      {
          int ans=0;
          for (int i=0;i<_size;i++) if (parray[i]==value) ans++;
          return ans;
      }
      bool insert(elemtype o)
      {
          parray=(elemtype*)malloc((_size+1)*sizeof(elemtype));
          parray[_size-1]=o;
          if (o<_min) _min=o;
          if (o>_max) _max=o;
      }
      bool insert(elemtype* arr,int size)
      {
          parray=(elemtype*)malloc((_size+size)*sizeof(elemtype));
          for (int i=0;i<size;i++)
          {
              parray[_size+i]=arr[i];
              if (arr[i]>_max) _max=arr[i];
              if (arr[i]<_min) _min=arr[i];
          }
          _size+=size;
      }

      ~example() {free(parray);}

    private:
      int _size;
      elemtype *parray;
      elemtype _min;
      elemtype _max;
};

#endif // EXAMPLE_H_INCLUDED
