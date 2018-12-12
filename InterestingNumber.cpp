#include <string>
#include <vector>
#include <iostream>
using namespace std;

class InterestingNumber{

public:
	string isInteresting(string x);
};

string InterestingNumber::isInteresting(string x){

int index1 = -1;
int index2 = -1;
bool second = false;
vector <int> presentVector;

presentVector.resize(10, 0);


for(int i = 0; i < x.size(); i++){
	presentVector[(int)(x[i] - '0')]++;
}

for(int i = 0; i < presentVector.size(); i++){
	if(presentVector[i] != 2 && presentVector[i] != 0){return "Not interesting";}
	cout << "i: " << i << " " << presentVector[i] << endl;
}

for(int i = 0; i < presentVector.size(); i++){
	if(presentVector[i] == 2){
		second = false;
		index1 = -1;
		index2 = -1;
		for(int j = 0; j < x.size(); j++){
			
			if(x[j] == (char)(i + '0') && second == false){index1 = j; second = true;}
			cout << "index1 " << index1 << endl;
			if(x[j] == char(i + '0') && second == true){index2 = j;}
			cout << "index2 " << index2 << endl;	
			
			
		}
		cout << index2-index1 << endl;
			if((index2 - index1) != i+1){return "Not interesting";}
		
}
		
}


return "Interesting";
}