#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main() {
	int i, j, n = 1, m = 1, g = 1, h = 1;;
	float M[3][3] /* ={{ 4,-3, 0 },
				       { 2,-1, 2 },
				       { 1, 5, 7 } }*/;

	for (i = 0; i < 1; i++)
		for (j = 0; j < 3; j++) {
			cout << "input the value (" <<n<<","<<m++<<")" << endl;
			cin >> M[i][j];
		}
	
	for (i = 1; i < 2; i++)
		for (j = 0; j < 3; j++) {
			cout << "input the value (" << n+1 << "," << h++<<")" << endl;
			cin >> M[i][j];
		}
	for (i = 2; i < 3; i++)
		for (j = 0; j < 3; j++) {
			cout << "input the value (" << n+2  << "," << g++ << ")" << endl;
			cin >> M[i][j];
		}

	/*  { 00 01 02  }
        { 10 11 12	}
         {20 21 22} */

	double determinant = (M[0][0] * M[1][1] * M[2][2]) + (M[1][0] * M[2][1] * M[0][2]) + (M[0][1] * M[1][2] * M[2][0])
		- M[0][2] * M[1][1] * M[2][0] - M[2][1] * M[1][2] * M[0][0] - M[0][1] * M[1][0] * M[2][2];
	cout <<"The determinant is " << determinant << endl;
	if (determinant == 0) { cout << "Thus an inverse of this matrix does not exist" << endl; exit(0); }
	float Min[3][3];
	Min[0][0] = M[1][1] * M[2][2] - M[1][2] * M[2][1];
	Min[0][1] = M[1][0] * M[2][2] - M[1][2] * M[2][0];
	Min[0][2] = M[1][0] * M[2][1] - M[1][1] * M[2][0];
	Min[1][0] = M[0][1] * M[2][2] - M[0][2] * M[2][1];
	Min[1][1] = M[0][0] * M[2][2] - M[0][2] * M[2][0];
	Min[1][2] = M[0][0] * M[2][1] - M[0][1] * M[2][0];
	Min[2][0] = M[0][1] * M[1][2] - M[0][2] * M[1][1];
	Min[2][1] = M[0][0] * M[1][2] - M[1][0] * M[0][2];
	Min[2][2] = M[0][0] * M[1][1] - M[0][1] * M[1][0];

	 /* int i, j;
	for (i = 0; i < 3; i++)
	for (j = 0; j < 3;j++) {
		cout << Min[i][j]<<endl;
	}*/
	float Alg[3][3] = { {Min[0][0],-Min[0][1],Min[0][2]},
				   {-Min[1][0],Min[1][1],-Min[1][2]},
				   {Min[2][0],-Min[2][1],Min[2][2]} };

	float inv[3][3] = { {Alg[0][0] / 40,Alg[1][0] / 40,Alg[2][0] / 40 },
				   {Alg[0][1] / 40,Alg[1][1] / 40,Alg[2][1] / 40},
				   {Alg[0][2] / 40,Alg[1][2] / 40,Alg[2][2] / 40 } };

	
	cout << "\nThe inverse matrix values are\n"<<endl;
	for (i = 0; i < 1; i++)
		for (j = 0; j < 3; j++) {
		
				cout << inv[i][j] << " ,";
		}
	cout << endl;
	for (i = 1; i < 2; i++)
		for (j = 0; j < 3; j++) {

			cout << inv[i][j] << " ,";
		}
	cout << endl;
	for (i = 2; i < 3; i++)
		for (j = 0; j < 3; j++) {

			cout << inv[i][j] << " ,";
		}

	return 0; 
}