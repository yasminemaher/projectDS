#include <string>
#include"client.h"
#include <Math.h>
#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition) /*implementation defined*/
#endif

class queue{
private:
int capacity; // default value is 50
client * p; //pointer for the dynamic array
int length; // number of actual elements in the queue
int head; // index of the head element in the array
int tail; // index of the tail element in the array
public:
queue() {capacity = 50;}
queue(int cap){
capacity = cap;
p = new client[capacity];
length=0; head=0; tail=0;
};
int size( ){return length;}
bool isEmpty( ) {return (length==0);}
client peekHead( ){assert(length>0);return p[head];}
client peekTail( ){assert(length>0); return p[tail];}
void enqueue(client x){
	if (length==0)
	{
		p[tail]=x; length++;
	}
	else if (length<capacity)
	{
		length++;
		tail=(tail+1) % capacity;
		p[tail]=x;
 }
	else
	{// Filled. Create a new array twice big.
	// Copy current array to it. Add x.
	client *q= new client[2*capacity];
	int j = head; // copy filled array p (from head to tail) to array q[0…]
	
	for (int i=0;i<capacity; i++)
	{q[i]=p[j]; j=(j+1) % capacity;}
	head = 0;
	tail = capacity; // pointing to the first empty slot for now
	q[tail]=x; // put x in the first empty slot
	length++; // account for adding x
	capacity = 2*capacity;// the capacity is now doubled
	delete [] p; // deletes the old array pointed to by p
	p =q; // makes p point to the new array.
	}
}

client dequeue( ){
assert(length>0);
client x= p[head];
head=(head+1) % capacity;
return x;
}



};


