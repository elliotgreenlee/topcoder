#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class OneRegister
{
   public:
      string getProgram(int s, int t);

};

string OneRegister::getProgram(int s, int t)
{
   string answer;
   queue < pair <string, unsigned long long> > q;
   
   if (s == t) { //this also covers s==t==0
      answer = "";
      return answer;
   }
   
   if (s == 0) {
      answer = ":-(";
      return answer;
   }
   
   if (t == 0) {
      answer = "-";
      return answer;
   }
   
   if (t == 1) {
      answer = "/";
      return answer;
   }
   
   q.push(make_pair("", s));
   q.push(make_pair(q.front().first + "*", q.front().second*q.front().second));
   q.push(make_pair(q.front().first + "+", q.front().second + q.front().second)); 
   q.push(make_pair(q.front().first + "/", q.front().second / q.front().second));  
   q.pop();
   
   while (q.size()) {
      answer = q.front().first;
      if (q.front().second == t) {
         return answer;
      }
      if (q.front().second > t) {
         q.pop();
      }
      else {
         if (q.front().second == 1) {
            q.push(make_pair(q.front().first + "+", q.front().second + q.front().second));
         }
         else {
            q.push(make_pair(q.front().first + "*", q.front().second*q.front().second));
            q.push(make_pair(q.front().first + "+", q.front().second + q.front().second));
         } 
         q.pop();  
      }
      
   }
   
   
   answer = ":-(";
   
   
   return answer;
}