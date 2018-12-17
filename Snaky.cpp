#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Snaky{

public:
	int longest(vector <string> snake);
};

int Snaky::longest(vector <string> snake){
   int length = 1;
   int longestLength = 0;
   bool portion = false;
   
   for(int k = 0; k < snake.size(); k++)
   {
      snake[k].push_back('.');
   }
   
   string dots(snake[0].size(), '.');
   
   snake.push_back(dots);
   
   for(int i = 0; i < snake.size(); i++)
   {
      length = 1;
      portion = false;
      for(int j = 0; j < snake[i].size(); j++)
      {
      
         if(portion)
         {
            if(snake[i][j] == 'x')
            {
               length++;
            }
            else
            {
               portion = false;
               if(length > longestLength)
               {
                  longestLength = length;
               }
               length = 0;
            }
         }
         else
         {
            if(snake[i][j] == 'x')
            {
               portion = true;
               length = 1;
            }
         }
      }
   }
   
   for(int j = 0; j < snake[0].size(); j++)
   {
      length = 1;
      portion = false;
      for(int i = 0; i < snake.size(); i++)
      {
       if(snake[i][j] == 'x' && portion)
         {
            length++;
            
         }
         else if(snake[i][j] == 'x')
         {
            portion = true;
            length = 1;
            
         }
         else if(snake[i][j] == '.')
         {
            portion = false;
            
            if(length > longestLength)
            {
               longestLength = length;
            }
            length = 1;
            
         }
      }
   }
  return longestLength;
}