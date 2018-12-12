#include <string>
using namespace std;

class DistanceBetweenStrings{

public:
	int getDistance(string a, string b, string letterSet);
};

int DistanceBetweenStrings::getDistance(string a, string b, string letterSet){

string normalA = a.c_str();
string normalB = b.c_str();
string normalLetter = letterSet.c_str();
int distanceSum = 0;
int distance = 0;
int n1 = 0;
int n2 = 0;



for(int i = 0; i < letterSet.size(); i++){
	n1 = 0;
	n2 = 0;
	for(int j = 0; j < a.size(); j++){
		if(normalLetter[i] == normalA[j] || normalLetter[i] == (normalA[j] - 'A' + 'a')){
			n1++;
		}
	}
	for(int k = 0; k < b.size(); k++){
		if(normalLetter[i] == normalB[k] || normalLetter[i] == (normalB[k] - 'A' + 'a')){
			n2++;
		}
	}
	distance = (n1 - n2)*(n1 - n2);
	distanceSum += distance;
}

return distanceSum;
}