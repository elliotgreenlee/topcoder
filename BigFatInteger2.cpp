#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

class BigFatInteger2{

public:
	int isDivisible(int A, int B, int C, int D);
};


int BigFatInteger2::isDivisible(int A, int B, int C, int D){

   int i = 2;
   map <int, long long> Cmap;
   map <int, long long>::iterator cit;
   map <int, long long> Amap;
   map <int, long long>::iterator ait;

   while(i < sqrt(A))
   {
      if(A % i == 0)
      {
         ait = Amap.find(i);
         if(ait == Amap.end())
         {
            Amap.insert(make_pair(i, 1));
         }
         else
         {
            ait->second++;
         }
      }
      else
      {
         i++;
      }
   } 
   
   i = 2;
   
   while(i < sqrt(C))
   {
      if(C % i == 0)
      {
         cit = Cmap.find(i);
         if(cit == Cmap.end())
         {
            Cmap.insert(make_pair(i, 1));
         }
         else
         {
            cit->second++;
         }
      }
      else
      {
         i++;
      }
   }
   
return D*B;
}