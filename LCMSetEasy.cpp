#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

class LCMSetEasy{
public:
	string include(vector <int> S, int x);
};


string LCMSetEasy::include(vector <int> S, int x)
{
   string rv = "Possible";
   int sub = x;
   int iLCM = 1;
   int j = 2;
   vector <int> divs;
   map <int, int> prime;
   map <int, int>::iterator pit;
   map <int, int> LCM;
   map <int, int>::iterator lit;
   
   
   for (int i = 0; i < S.size(); i++) {
      if (x % S[i] == 0) {
         divs.push_back(S[i]);
      }
   }
   
   for (int i = 0; i < divs.size(); i++) {
      printf("%d\n", divs[i]);
      fflush(stdout);
   }
   
   for (int i = 0; i < divs.size(); i++) {
      prime.clear();
      j = 2;
      while (j * j <= divs[i]) {
         while (divs[i] % j == 0) {
            if (prime.find(j) == prime.end()) {
               prime.insert(make_pair(j, 1));
            }
            else {
               prime.find(j)->second++;
            }
            divs[i] /= j;
         }
         j++;
      }
      if (divs[i] != 1) {
         prime.insert(make_pair(divs[i], 1));
      }
      
      for (pit = prime.begin(); pit != prime.end(); pit++) {
         if (LCM.find(pit->first) != LCM.end()) {
            if (pit->second > LCM.find(pit->first)->second) {
               LCM.find(pit->first)->second = pit->second;
            }
         }
         else {
            LCM.insert(*pit);
         }
      }
   }
   
   for (lit = LCM.begin(); lit != LCM.end(); lit++) {
      printf("%d, %d\n", lit->first, lit->second);
      fflush(stdout);
   }
   
   prime.clear();
   j = 2;
   while (j * j <= x) {
      while (x % j == 0) {
         if (prime.find(j) == prime.end()) {
            prime.insert(make_pair(j, 1));
         }
         else {
            prime.find(j)->second++;
         }
         x /= j;
      }
      j++;
   }
   if (x != 1) {
      prime.insert(make_pair(x, 1));
   }
   
   for (lit = LCM.begin(); lit != LCM.end(); lit++) {
      for (int i = 0; i < lit->second; i++) {
         iLCM *= lit->first;
      }
   }
   
   printf("iLCM = %d, x = %d", iLCM, sub);
   if (iLCM == sub) {
      return "Possible";
   }
   else {
      return "Impossible";
   }      
   
}