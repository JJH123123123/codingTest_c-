#include <iostream>
#include <vector>

using namespace std;

int n;
int query;
vector<int> vec;
vector<int> fenwick;

// 7 :  111_2
// 8 : 1111_2
int sum(int pos){

	//pos++; // 1-idx 
	int ret = 0;
	while(pos>0){
		ret += fenwick[pos];
		pos &= (pos-1); // pos -= (pos & -pos)
	}
	return ret; 
}
 
int partial_sum(int s, int e){
	return sum(e) - sum(s-1);
}

void add(int pos, int val){
	
	//pos++; // 1-idx 
	while(pos<=n){
		fenwick[pos] += val;
		// 101 -> 100 -> 0  
		pos += (pos & -pos);
	}
}	

void toString(){
	for(int i=1;i<=n;i++){
		cout << fenwick[i] << " ";
	}
	cout << '\n';
}

int main(void){
	cin >> n;
	cin >> query;

	fenwick.resize(n+1,0);
	vec.resize(n+1,0);
	for(int i = 1;i<=n;i++){
		cin >> vec[i];
	}

	for(int i=1;i<=n;i++){
		add(i, vec[i]);
	}

	int p, q;
	for(int i = 0;i<query;i++){
		cin  >> q;
		cout << sum(q) << '\n';
	}

	toString();
	// 101 
}
