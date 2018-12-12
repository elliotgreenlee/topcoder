#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class ColorfulRabbits{

public:
	int getMinimum(vector <int> replies);
};

int ColorfulRabbits::getMinimum(vector <int> replies){

vector <int> repliesInc = replies;
map <int, int> count;
map <int, int>::iterator cit;
int rabbits = 0;

for(int i = 0; i < repliesInc.size(); i++){
	repliesInc[i]++;
	count[repliesInc[i]]++;
}

for(cit = count.begin(); cit != count.end(); cit++){
	cout << " " << cit->first << " " << cit->second << endl;
	if(cit->second <= cit->first){
		rabbits += cit->first;
	}
	else{
		rabbits += ((cit->first + cit->second - 1) / cit->first) * cit->first;
	}
		
}


	return rabbits;
}