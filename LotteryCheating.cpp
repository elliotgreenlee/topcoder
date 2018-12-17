#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class LotteryCheating{
   public:
      int minimalChange(string ID);
};


int LotteryCheating::minimalChange(string ID)
{
   char str[13];
   string strr;
   int diff;
   int smallDiff = 11;
   long long big;
   string temp = "0";
   stringstream iss;

   cout << ID << endl;
   
   for (long long i = 0; i < 100000; i++) {
      big = i*i;
      if (i == 65536) cout << big << endl;
      sprintf(str, "%lld", big);
      strr = str;
      if (i == 65536) {cout << strr << endl;}
      
      if (strr.length() > ID.length()) {continue;}
      while (strr.length() < ID.length()) {
         strr = temp + strr;
      }
      //cout << big << " " << str << " " << strr << endl;
      
      diff = 0;
      for (int j = 0; j < strr.length(); j++) {
         if (strr[j] != ID[j]) {
            diff++;
         }
      }
      
      if (diff < smallDiff) {
         smallDiff = diff;
      }
   }
      
   return smallDiff;
}