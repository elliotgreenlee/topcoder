#include <vector>
#include <iostream>
using namespace std;

class PackingParts{

public:
	int pack(vector <int> partSizes, vector <int> boxSizes);
};

int PackingParts::pack(vector <int> partSizes, vector <int> boxSizes){

int partsPacked = 0;
bool packed = false;
int i = 0;
int j = 0;

for(i = 0; i < partSizes.size(); i++){
	packed = false;
	while(!(packed) && j < boxSizes.size()){
		if(partSizes[i] <= boxSizes[j]){partsPacked++; j++; packed = true;}
		else{j++;}
	}
}

return partsPacked;
}