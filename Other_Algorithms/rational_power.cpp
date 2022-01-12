#include <bits/stdc++.h>
using namespace std;

float power(int a,int n){
    float den = (float)n;
    float num = (float)1;
    float x;    				// Next x - Newton's method
	float x0 = 1;				// Current x - Newton's method, initial value set to 1
	float tol = 1;				// Tolerance - Newton's method
	float atonum = a;			// Variable for computing a^(num)
	float xtoden;				// Variable for computing x0^(den)
	
	for (int i=1; i<num; i++) atonum = atonum*a;
	
	while (tol > 0.0001){							//
		xtoden = x0;							//
		for (int i=1; i<den; i++) xtoden = xtoden*x0;			//
		x = x0 - (xtoden-atonum) / ((den)*(xtoden/x0));			//
		tol = ((x-x0)/x0)*100;						//  Newton's Method Iterations
		if (tol < 0) tol = tol*(-1);					//
		x0 = x;								//
	}
    return x;
}

int main(){

    //code goes here

    return 0;
}