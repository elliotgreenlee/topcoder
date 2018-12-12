#include <vector>
using namespace std;

class BoundingBox{

public:
	int smallestArea(vector <int> X, vector <int> Y);
};

int BoundingBox::smallestArea(vector <int> X, vector <int> Y){
int minX, minY, maxX, maxY;
int i;
int j;
int area;
minX = X[0];
maxX = X[0];
minY = Y[0];
maxY = Y[0];


for(i = 1; i < X.size(); i++){
	if(X[i] > maxX){maxX = X[i];}
	if(X[i] < minX){minX = X[i];}
}
for(j = 1; j < Y.size(); j++){
	if(Y[j] > maxY){maxY = Y[j];}
	if(Y[j] < minY){minY = Y[j];}
}

area = (maxX - minX) * (maxY - minY);



return area;
}