#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class InsertSort{
   public:
      int calcMinimalCost(vector <int> theArray);
};

int InsertSort::calcMinimalCost(vector <int> theArray)
{
   int answer = 0;
   int index;
   int newWeight;
   bool smallest;
   bool There;
   multimap <int, string> mmap;
   multimap <int, string>::iterator mit;
   multimap <int, string>::iterator mit2;
   string initial;
   string newNode;
   
   initial.resize(theArray.size(), '-');
   
   //printf("%s\n", initial.c_str());
   mmap.insert(make_pair(0, initial));
   
   while(mmap.size()) {
      mit = mmap.begin();
      printf("processing %d, %s\n", mit->first, mit->second.c_str());
      
      index = -1;
      for (int i = 0; i < (mit->second).size(); i++) {
         if (mit->second[i] == '-') {
            index = i;
            break;
         }
      }
      
      if (index == -1) {
         return mit->first;
      } 
      
      smallest = true;
      for (int i = 0; i < (mit->second).size(); i++) {
         if (mit->second[i] == '-') {
            if (theArray[index] > theArray[i]) {
               smallest = false;
            }
         }
      }
      
      if (smallest) {
         newNode = mit->second;
         newNode[index] = 'X';
         There = false;
         for (mit2 = mmap.begin(); mit2 != mmap.end(); mit2++) {
            if (newNode == mit2->second) {
               There = true;
               if (mit->first < mit2->first) {
                  mmap.insert(make_pair(mit->first, newNode));
                  printf("smallest %d, %s\n", mit->first, newNode.c_str());
                  fflush(stdout);
                  break;
               }
            }
         }
         if (!There) {
            mmap.insert(make_pair(mit->first, newNode));
            printf("smallest there %d, %s\n", mit->first, newNode.c_str());
            fflush(stdout);
         }
      }
      else {
         newNode = mit->second;
         newNode[index] = 'X';
         mmap.insert(make_pair(mit->first + theArray[index], newNode));
         printf("ns first %d %s\n", mit->first + theArray[index], newNode.c_str());
         fflush(stdout);
         
         newNode = mit->second;
         newNode[index] = 'X';
         newWeight = 0;
         for (int j = 0; j < mit->second.size(); j++) {
            if (mit->second[j] == '-' && theArray[j] < theArray[index]) {
               newNode[j] = 'X';
               newWeight += theArray[j];
            }
         }
         mmap.insert(make_pair(mit->first + newWeight, newNode));
         printf("ns second %d, %s\n", mit->first + newWeight, newNode.c_str());
         fflush(stdout);
      }  
      
      mmap.erase(mit);
   }
   
   return answer;
}