#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Bigital{

public: 
   double energy(string tStart, string tEnd);
   string IntToString(int time);
   int StringToInt(string time);
   int DigitToLights(char digit);
         
};

int Bigital::DigitToLights(char digit)
{
   int rv = 0;
   unsigned int iDigit = digit - '0';
   
   for (int i = 1; i <= 8; i*=2) {
      if (iDigit & i) {
         rv++;
      }
   }
   return rv;
}

string Bigital::IntToString(int time)
{
   string rv = "Hello";
   char str[9];
   int hours = time / 3600;
   time = time % 3600;
   int minutes = time / 60;
   time = time % 60;
   int seconds = time;
   
   if (hours > 12) { hours = hours - 12;}
   sprintf(str, "%02d:%02d:%02d", hours, minutes, seconds); 
   
   rv = str;
   
   return rv;
}

int Bigital::StringToInt(string time)
{
   int rv = 0;
   const char *str;
   int hours;
   int minutes;
   int seconds;
   
   str = time.c_str();
   
   sscanf(str, "%d:%d:%d", &hours, &minutes, &seconds);
   
   rv = hours * 3600 + minutes * 60 + seconds;
   
   return rv;
}

double Bigital::energy(string tStart, string tEnd)
{
   double rv = 0;
   int start = StringToInt(tStart);
   int end = StringToInt(tEnd);
   int lightNumber = 0;
   string lights;
   
   if (start > end) {
      end += 12*3600;
   }
   
   for (int i = start; i <= end; i++) {
      lights = IntToString(i);
      lights.erase(5,1);
      lights.erase(2,1);
      cout << lights << endl;
      lightNumber = 0;
      for (int j = 0; j < lights.length(); j++) {
         lightNumber += DigitToLights(lights[j]);
         //cout << "lightNumber = " << lightNumber << endl;
      }
      rv += (lightNumber / 1000.0000) / 3600.000;
   } 
   
  // cout << DigitToLights('9') << endl;
  // cout << IntToString(3601) << endl;
  // cout << IntToString(StringToInt("05:20:13")) << endl;

   return rv;
}
