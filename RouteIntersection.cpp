#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <set>
using namespace std;

class RouteIntersection{

public:
	string isValid(int N, vector <int> coords, string moves);
};

string RouteIntersection::isValid(int N, vector <int> coords, string moves){

	string validity = "VALID";
	string point;
	string fullPoint = "";
	map <int, int> dime;
	map <int, int>::iterator dit;
	set <string> points;
	set <string>::iterator pit;
	stringstream ss;
	
	for(dit = dime.begin(); dit != dime.end(); dit++){
		ss.clear();
		ss << "";
			if(dit->second != 0){
				//printf("[%d,%d]", dit->first, dit->second);
				ss << "[" << dit->first << "," << dit->second << "]";
				ss >> point;
				//cout << point;
				fullPoint += point;	
			}
		}
		cout << fullPoint;
		points.insert(fullPoint);
		cout << endl;
		
	for(int i = 0; i < coords.size(); i++){
	
		if(moves[i] == '+'){
			dime[coords[i]]++;
		}
		if(moves[i] == '-'){
			dime[coords[i]]--;
		}
		
		fullPoint = "";
		for(dit = dime.begin(); dit != dime.end(); dit++){
			ss.clear();
			ss << "";
			if(dit->second != 0){
				//printf("[%d,%d]", dit->first, dit->second);
				ss << "[" << dit->first << "," << dit->second << "]";
				ss >> point;
				//cout << point;
				fullPoint += point;
				
			}
		}
		cout << fullPoint;
		if(points.find(fullPoint) != points.end()){
			return "NOT VALID";
		}
		else{
			points.insert(fullPoint);
		}
		cout << endl;
	}
	
	
	cout << endl;
	cout << endl;
	for(pit = points.begin(); pit != points.end(); pit++){
		cout << *pit << endl;
	}
	

	return validity;
}