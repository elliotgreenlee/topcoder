#include <string>
#include <iostream>
using namespace std;

class PersistentNumber{

public:
	int getPersistence(int n);
};

int PersistentNumber::getPersistence(int n){

   int count = 0;
   int pn = 1;
  
   while(1){
      if(n < 10){
         return count;
      }
      else{
         pn = 1;
         while(n > 0){
            pn *= (n%10);
            //cout << pn << endl;
            cout << n << endl;
            n = n / 10;
         }
         n = pn;
         count++;
         cout << "count is: " << count;
      }
   }
}