#include <string>
#include <iostream>
using namespace std;

class MagicalStringDiv2{

public:
	int minimalMoves(string S);
};

int MagicalStringDiv2::minimalMoves(string S){

int changes = 0;
cout << S << endl;
S.c_str();
cout << S << endl;

for(int i = 0; i < S.size(); i++){
	if((i < S.size()/2) && (S[i] != '>')){S[i] = '>'; changes++;}
	cout << changes << endl;
	if((i >= S.size()/2) && (S[i] != '<')){S[i] = '<'; changes++;}
	cout << changes << endl;
}

return changes;
}