#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Cryptography{

public:
	long long encrypt(vector <int> numbers);
};

long long Cryptography::encrypt(vector <int> numbers){

vector <int> nums = numbers;

long long product = 1;
int min;
int least = 0;

	for(int i = 0; i < nums.size(); i++){
		if(i == 0){min = nums[0];}
		if(nums[i] < min){
			min = nums[i];
			least = i;
		}
	}

	nums[least] = nums[least]++;

	for(int i = 0; i < nums.size(); i++){
		product = product * nums[i];
	}

return product;
}