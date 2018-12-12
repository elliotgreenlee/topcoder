#include <string>
using namespace std;

class AlienAndPassword{

public:
	int getNumber(string S);
};

int AlienAndPassword::getNumber(string S){
int answer = 0;
string reduced = "";
reduced = reduced.c_str();
S = S.c_str();

for(int i = 0; i < S.size(); i++){
	if(!(S[i] == S[i+1])){reduced.push_back(S[i]);}
}
	
answer = reduced.size();
	

return answer;
}