#include <string>
using namespace std;

class InsertZ{

	public:
		string canTransform(string init, string goal);
};

string InsertZ::canTransform(string init, string goal)
{

string s = "";
string answer = "";

goal = goal.c_str();

for(int i = 0; i < goal.size(); i++){
	if(!(goal[i] == 'z')){s.push_back(goal[i]);}
}

if(s == init){answer = "Yes";}
else{answer = "No";}

return answer;
}