#include <bits/stdc++.h>
using namespace std;

int random(int a, int b){
	return a+rand()%(b-a+1);
}

int main() {
	srand(time(0));
	int n=random(50, 100);
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		cout<<random(-10, 10)<<' '<<random(-10, 10)<<endl;
	}
	cout<<random(1, 5)<<endl;
	return 0;
}