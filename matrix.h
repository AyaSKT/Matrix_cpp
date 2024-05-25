#ifndef __MATRIX_H
#define __MATRIX_H

#include "iostream"
#include "vector"

class matrix{
	private:
		int size;
		std::vector<int> entries[10];
	public:
		explicit matrix(int n);
		~matrix();
		void print();
		matrix & operator=(const int para[]);
		matrix operator+(const matrix & para)const;
		friend matrix operator*(int a, const matrix & b);
		friend matrix operator*(const matrix & b, int a);
		matrix operator*(const matrix & b);

};

#endif
