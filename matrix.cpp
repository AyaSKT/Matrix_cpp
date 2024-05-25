#include "matrix.h"


matrix::matrix(int n) : size(n){
	//std::cout<<"Successfully\n";

	for(int i=0; i<=size; i++)
		for(int j=0; j<=size; j++)
			entries[i].push_back(0);
	//std::cout<<"Successfully\n";
};
matrix::~matrix() = default;

matrix & matrix::operator=(const int para[]){

	for(int i=0; i<size; i++){
		entries[i+1].clear();
		entries[i+1].push_back(0);
		for(int j=0; j<size; j++){
			entries[i+1].push_back(para[i*3+j]);
		}
	}

	return *this;
}

void matrix::print(){

	for(int i=1;i<=size;i++){

		for(auto iter = 1; iter <= size; iter++){
			std::cout << entries[i][iter] << ' ';
		}

		std::cout<<std::endl;
	}
}

matrix matrix::operator+(const matrix & para)const{

	matrix res(para.size);

	for(int i=1; i<=size; i++){
		for(int j=1; j<=para.size; j++){
			res.entries[i][j] = para.entries[i][j] + entries[i][j];
		}
	}

	return res;
}
matrix operator*(int a, const matrix & b){
	matrix res(b.size);
	res = b;
	for(int i=1; i<=b.size; i++){
		for(int j=1; j<=b.size; j++){
			res.entries[i][j] *= a;
		}
	}

	return res;
}

matrix operator*(const matrix & b, int a){
	matrix res(b.size);
	res = b;
	for(int i=1; i<=b.size; i++){
		for(int j=1; j<=b.size; j++){
			res.entries[i][j] *= a;
		}
	}

	return res;
}

matrix matrix::operator*(const matrix & b){
	matrix res(b.size);


	for(auto row =1; row<=size; row++){

		res.entries[row].clear();
		res.entries[row].push_back(0);

		for(auto column=1; column<=size; column++){
			int temp = 0;
			for(auto kcr = 1; kcr<=size; kcr++){
				temp += this->entries[row][kcr] * b.entries[kcr][column];
			}
			res.entries[row].push_back(temp);
		}
	}

	return res;
}