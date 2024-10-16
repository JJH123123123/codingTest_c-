#include <iostream>

using namespace std;

int n;
int arr[100001];

class fenwick{
	
	public:
		explicit fenwick(){

		}	
		fenwick(int size){
			this->size = size;
			fill(this->tree, this->tree +size+1,0);
		}

		void init(int arr1[]){
			int n = sizeof(arr1)/sizeof(arr1[0]);
			for(int i = 1;i<= n;i++){
				// fenwick init
				add(i,arr1[i-1]);
			}
		}

		int sum(int pos){
				
			int ret = 0;
			pos++; // 0-idx
			while(pos>0){
				ret += this->tree[pos];
				pos &= (pos-1);
			}
			return ret; 
		}

		int partial_sum(int s, int e){
			return sum(e) - sum(s);
		}

		void add(int pos, int val){
			
			pos++; // 1-idx
			while(pos<=this->size){
				this->tree[pos]+= val;
				pos += (pos & -pos); 
			}
		}
		void toString(){
			cout << "This is size of fenwick tree " << this->size << '\n';
			for(int i = 0;i<this->size;i++){
				cout << this->tree[i+1] << " ";
			}
			cout << '\n';
		}

	private:
		int size;	
		int  tree[100001];
};

int main(void){
	fenwick* fw = new fenwick(10);	
	int arr[5] = {1,2,3,4,5};
	fw->init(arr);
	fw->toString();
}	

