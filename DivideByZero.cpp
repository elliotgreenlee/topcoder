#include <vector>
using namespace std;

class DivideByZero{

public:
	int CountNumbers(vector <int> numbers);
};

int DivideByZero::CountNumbers(vector <int> numbers){

vector <int> N = numbers;
vector <int> T;
vector <int> P;
int k = 0;

T.resize(101, 0);

for(int i = 0; i < N.size(); i++){
	T[N[i]] = 1;
}

for(int i = 0; i < N.size(); i++){
	for(int j = 0; j < P.size(); j++){
		if(N[i] / P[j] == 0){k = P[j] / N[i];}
		else{k = N[i] / P[j];}
		
		if(T[k] == 0){T[k] = 1; N.push_back(k);}
	}
	P.push_back(N[i]);
}

return P.size();
}
		
