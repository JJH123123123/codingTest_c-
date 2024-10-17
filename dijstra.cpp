// algorithm : dijstra
// header?

#include <iostream>
#include <utility>
#include <priorityqueue>

using namespace std;
using pii = pair<int, int>;

priorityqueue<pii, vector<pii>> pq;
const int INF = 987654321;
int n;
int dist[100001];
vector<pii> G[100001];

void dijstra(int start){
	
	fill(dist, dist+n+1, INF);
	dist[start] = 0;
	
	pq.push({0,start}); // dist, node
	
	while(!pq.empty()){
		pair<int, int> cur = pq.front(); pq.pop();
		
	} 
}

int main(void){

	cin >> n;
	int a, b, c;
	for(int i = 0;i<n;i++){
		cin >> a >> b >> c;
		G[a].push_back({b,c}); // node dist a-b 
		// bidirectional ?
	}
}
0ad84xf016
 
