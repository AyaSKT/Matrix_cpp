#include "matrix.h"


int main(){
	matrix c(3),d(3);

	int k[] = {
				1,0,0,
				0,1,0,
				0,0,1,
	};
	int k2[]= {
				1,2,3,
				4,9,6,
				7,8,9,
	};

	c = k;
	d = k2;

	c = 2 * c * d;

	c.print();




	return 0;
}