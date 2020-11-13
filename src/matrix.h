#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class matrix{
private:
	int n,m;
	vector<vector<double>> pts;
public:
	matrix(int n, int m){
		this->n=n;
		this->m=m;
		pts.resize(n, vector<double>(m, 0.0));
	}

	matrix(vector<vector<double>>& v){
		pts=v;
		n=pts.size();
		if(n!=0){
			m=pts[0].size();
		}else{
			n=0;
			m=0;
		}
	}

	int getN(){	return n; }
	int getM(){ return m; }
	double get(int a, int b){
		return pts[a][b];
	}
	void set(int a, int b, double val){
		pts[a][b]=val;
	}

	void get_points();
	void display_pts();
	matrix trans();
	double determinant();
	matrix mul(matrix&);
	matrix inverse();

};

void matrix::get_points(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>pts[i][j];
	}
}

void matrix::display_pts(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<pts[i][j]<<' ';
		cout<<endl;
	}
}

matrix matrix::trans(){
	matrix c(m, n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c.set(j, i, this->get(i, j));
		}
	}
	return c;
}

double matrix::determinant(){
	double ans=0;
	assert(this->n == this->m);

	if(this->n==2){
		int val1=this->get(0, 0)*this->get(1, 1);
		int val2=this->get(0, 1)*this->get(1, 0);
		return val1-val2;
		// return a[0][0]*a[1][1] - a[0][1]*a[1][0];
	}
	if(this->n < 2)
		return this->get(0, 0);

	for(int i=0;i<m;i++){
		matrix c(this->n-1, this->m-1);
		for(int j=1;j<n;j++){
			int l=0;
			for(int k=0;k<m;k++){
				if(k==i)
					continue;
				c.set(j-1, l, this->get(j, k));
				l++;
			}
		}
		if(i%2==0)
			ans+=this->get(0, i)*c.determinant();
		else
			ans-=this->get(0, i)*c.determinant();
	}
	return ans;
}

matrix matrix::mul(matrix &a){
	assert(m==a.n);

	matrix c(n, a.m);

	for(int i=0;i<n;i++){
		for(int j=0;j<a.m;j++){
			double cur=0;
			for(int la=0;la<m;la++){
				cur+=pts[i][la]*a.pts[la][j];
			}
			c.pts[i][j]=cur;
		}
	}
	
	return c;
}

matrix matrix::inverse(){
	double det=determinant();
	srand(time(0));
	int cnt=0;
	while(det==0){
		int nn=rand()%n, mm=rand()%m;
		double c=0.01;
		if(rand()%2)
			c*=-1;
		set(nn, mm, get(nn, mm)+c);
		det=determinant();
		// display_pts();
		cnt++;
		if(cnt>100)
			break;
		// cout<<"--"<<endl;
	}
	if(det==0){
		cout<<"inverse doesn't exist"<<endl;
	}
	assert(det!=0);

	matrix c(n, m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int l=0;
			matrix d(n-1, m-1);
			for(int la=0;la<n;la++){
				if(la==i)
					continue;
				int r=0;
				for(int lb=0;lb<m;lb++){
					if(lb==j)
						continue;
					d.set(l,r,get(la,lb));
					r++;
				}
				l++;
			}
			double val=d.determinant();
			if((i+j)&1)
				val*=-1;
			c.set(i,j,val/det);
		}
	}
	c=c.trans();
	return c;
}