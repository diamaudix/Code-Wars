#include <string>
#include <vector>
using namespace std;
std::string range_extraction(std::vector<int> args) {
	
	std::string answer = "";

	std::vector<int> vector = args;

	for (unsigned int i = 0; i < vector.size(); i++) {

		if (vector[i + 1] != vector[i] + 1) {

			answer.append(to_string(vector[i]));
			
			if (i<vector.size()-1) answer.push_back(',');
		}
		else{  // start of a sequence
			answer.append(to_string(vector[i]));
			int k = i + 1;
			while (k < vector.size() - 1 && vector[k + 1] == vector[k] + 1) {
				k++;
			}
			
			if (k - i == 1) {
				answer.push_back(',');
			}
			else{
				answer.push_back('-');
			}

			answer.append(to_string(vector[k])); 
			if(k<vector.size()-1)answer.push_back(',');
			i = k;
		}
	}

	
	return answer;
}

int main(){


	std::string z = range_extraction({ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 });// , Equals("-6,-3-1,3-5,7-11,14,15,17-20"));
	std::string y = range_extraction({ -3,-2,-1,2,10,15,16,18,19,20 });//, Equals("-3--1,2,10,15,16,18-20"));
	return 0;

}