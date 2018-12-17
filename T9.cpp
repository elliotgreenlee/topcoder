#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

class T9
{
   public:
      string message(vector <string> part, vector <string> dict, vector <string> keystr);
};

string T9::message(vector <string> part, vector <string> dict, vector <string> keystr)
{
   vector <char> letter2digit('z' + 1);
   map <string, vector <string> > num2word;
   map <string, vector <string> >::iterator nit;
   string rv = "";
   string numerical = "";
   string allKeystr = "";
   string key = "";
   int n = 0;
   
   for (int i = 0; i < part.size(); i++) {
      for (int j = 0; j < part[i].length(); j++) {
         letter2digit[part[i][j]] = i + '1'; 
      }
   }
   
   for (int i = 0; i < dict.size(); i++) {
      numerical = "";
      for (int j = 0; j < dict[i].size(); j++) {
         numerical += letter2digit[dict[i][j]];
      }
      num2word[numerical].push_back(dict[i]);
   }
   
   for (int i = 0; i < keystr.size(); i++) {
      allKeystr += keystr[i];
   }
   
   for (nit = num2word.begin(); nit != num2word.end(); nit++) {
      sort(nit->second.begin(), nit->second.end());
      for (int i = 0; i < nit->second.size(); i++) {
         cout << nit->first << " " << nit->second[i] << endl;
      }
   }
   
   //cout << allKeystr << endl;
   allKeystr += '0';
   
   for (int i = 0; i < allKeystr.length(); i++) {
      if (allKeystr[i] == '0') {
         cout << i << " " << key << " " << n << endl;
         
         if (key != "") {
            rv += num2word[key][n];
            rv += ' ';
         
            key = "";
            n = 0;
         }
         else {
            rv += ' ';
         }
      }
      else if (allKeystr[i] == '#') {
         n++; 
      }
      else if (allKeystr[i] == '*') {
         n += 5;
      }
      else {
         key += allKeystr[i];
      }
   }
   
   rv = rv.substr(0, rv.length() - 1);
   return rv;
}
