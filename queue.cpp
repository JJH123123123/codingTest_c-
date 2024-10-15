
#include <iostream>

using namespace std;

struct Node{
	int val;
	Node* prev;
	Node* nxt;
	explicit Node(int val):	
	 	val(val),
		prev(nullptr),
		nxt(nullptr)
	{}
	virtual ~Node(){
		delete this;
	}
};	


class DLL
{

public:
	explicit DLL() // constructor for DLL
	{
		this->head = new Node(-1);
		this->tail = new Node(-1);
		this->head -> nxt = this->tail;
		this->tail -> prev = this->head;	 		
	}
	void init(Node* node){
		node->nxt = head;
		node->prev = head;
	}

	void addLast(int val){ 
		// ... -- Node(val) -- tail
		// -- ... -- .. -/- tail 
		Node* cur = new Node(val);
		cur->prev = tail->prev;
		tail->prev->nxt = cur;
		cur->nxt = tail;
		tail->prev = cur;
	}
	
	 void addFirst(int val){
          // head -|- .. ... -- Node(val) -- tail
          // head -- Node -- ... -- ... -- .. --  tail
          Node* cur = new Node(val);
		  cur->nxt = head->nxt; 
		  cur->nxt->prev = cur;
		  cur->prev  = head;
		  head->nxt = cur;
     }

	void popBack(){
	
		Node* cur = tail->prev;
		if(cur == head){
			return;
		}

		cur->nxt->prev = cur->prev;
		cur->prev->nxt = cur->nxt;
		cur->nxt = nullptr;
		cur->prev = nullptr;
		free(cur);
		//  ㅇ = ㅇ = ㅇ 
		// => o === o 
		//		o 
		// 1 2 3 - > 1 2 -> 1 
		// 	 	 - > 2 3 -> 3
		return; // cur
	}

	void popFront(){
		
		Node* cur = head->nxt; 
		if(cur == tail) return;
		
		cur->nxt->prev = cur->prev;
		cur->prev->nxt = cur->nxt;
		cur->nxt = nullptr;
		cur->prev = nullptr;
		free(cur);
	}

	void insert(int place, int val){
		if(place<=0){
			return;
		}
		int i = 0;
		Node* cur = head;
		while(i<place && cur->nxt!=nullptr){
			i++;
			cur = cur->nxt;
		}

		if(cur==nullptr){ // when place is exceeded 
			// this->addLast(place);			
			return;
		}
		Node* item = new Node(val);
		item->nxt = cur; 
		item->prev = cur->prev; 
		cur->prev->nxt = item;
		cur->prev = item;
	}
	
	int getValueByIndex(int idx){
		Node* cur = this->head;
		int i = 0;
		while (i<idx){
			i++;
			cur = cur->nxt;
		}
		return cur->val;
	}
	
	void toString(){
		Node* cur = head;
		while(cur->nxt!=tail){
			cur = cur->nxt; // 2 10 1 tail  
			cout << cur->val << " ";
		}
		cout << '\n';
	}

	private:
		Node* head = nullptr;
		Node* tail = nullptr;
}; // how to connect between head and edit 

int main(void){
	DLL* dll = new DLL();
	dll->addLast(1);
	dll->addFirst(2);
	dll->insert(2,10);
	dll->toString();
}
