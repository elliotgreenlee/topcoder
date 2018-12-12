#include <string>
using namespace std;

class SwappingDigits{

public:
	string minNumber(string num);
};

string SwappingDigits::minNumber(string num){

string smallestNum;

string numSwap;
string tempSwap;

smallestNum = num;


for(int i = 0; i < num.size(); i++){
	for(int j = i+1; j < num.size(); j++){
		numSwap = num;
		if(i != j){
		tempSwap = numSwap;
		numSwap[i] = tempSwap[j];
		numSwap[j] = tempSwap[i];
		if(numSwap < smallestNum && numSwap[0] != '0'){smallestNum = numSwap;}
		}
	}
}

return smallestNum;
}