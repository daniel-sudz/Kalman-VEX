using namespace std; 
#include <vector>

class matrix {
	matrix(vector<vector<float>> &input) {
		data = input; 
	}
public: 
	vector<vector<float>> data;
	vector<float>& operator[](int);
	matrix multiply(matrix mb) {
		int r1_count = data.size();
		int c1_count = data[0].size(); 
		int r2_count = mb.data.size();
		int c2_count = mb.data[0].size(); 
		if (c1_count != r2_count) throw "cannot multiply matrix"; 
		vector<vector<float>>* new_v; 
		for (int i = 0; i < r1_count; i++) {
			vector<float>* new_row; 
			for (int j = 0; j < c2_count; j++) {
				
			}
		}

	}
};

vector<float>& matrix::operator[](int index) {
	return data[index];
}
