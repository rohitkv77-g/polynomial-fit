#include <iostream>
#include "./src/points.h"
#ifndef MATRIX
	#define MATRIX
	#include "./src/matrix.h"
#endif

using namespace std;

double cost(matrix a, matrix b){
	int n=a.getN();
	double cur=0;
	for(int i=0;i<n;i++){
		double v1=a.get(i, 0);
		double v2=b.get(i, 0);
		cur+=(v1-v2)*(v1-v2);
	}
	return cur;
}

int main(){

	points p;
	cout<<"Enter degree of polynomial"<<endl;
	int d;
	cin>>d;
	
	matrix X=p.matX(d);
	// X.display_pts();
	matrix Y=p.matY();

	matrix T=X.trans();
	matrix b=(((T.mul(X)).inverse()).mul(T)).mul(Y);

	matrix Z=X.mul(b);
	
	cout<<"The equation would be: \n\n";

	for(int i=0;i<b.getN();i++){
		cout<<b.get(i, 0)<<"x^"<<i;
		if(i<b.getN()-1)
			cout<<" + ";
	}
	cout<<endl;
	
	cout<<"\nThe cost would be: ";
	cout<<cost(Y, Z)<<endl;
	return 0;
}