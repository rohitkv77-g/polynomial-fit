#include <bits/stdc++.h>
using namespace std;

int random(int a, int b){
	return a+rand()%(b-a+1);
}

int main() {
	srand(time(0));
	int n=random(10, 30);
	cout<<n<<endl;
	int cnt=0;
	set<int> s;
	while(cnt<n){
		int temp=random(-50, 50);
		if(s.find(temp)==s.end()){
			s.insert(temp);
			cnt++;
			cout<<temp<<' '<<random(-50, 50)<<endl;
		}
	}
	cout<<random(1, 5)<<endl;
	return 0;
}