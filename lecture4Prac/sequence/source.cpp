#include "sequence.h"

int main(){
	sequence seq;
	/*MUST use attach to initially place stuff in?*/
	
	//seq.remove_current();
	seq.insert(10);
	seq.remove_current();
	seq.attach(1.0);
	//seq.attach(1.5);
	//seq.remove_current();
	//seq.attach(2.0);
	//seq.attach(3.0);
	seq.insert(2.5);
	//seq.attach(4.0);
	//seq.remove_current();
	//seq.attach(5.0);
	//seq.attach(0);
	//cout << seq.is_item() << endl;
	seq.start();
	cout << seq.current() << endl;
	seq.advance();
	cout << seq.current() << endl;
	//seq.advance();
	//cout << seq.current() << endl;
	
	cout<< "Printing items" << endl;
	for(seq.start(); seq.is_item(); seq.advance()){
		cout << seq.current() << endl;
	}

	return 0;
}
