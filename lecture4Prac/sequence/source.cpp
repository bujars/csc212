#include "sequence.h"

int main(){
	sequence seq;
	cout << seq.is_item() << endl;
	cout << seq.current() << endl;
	seq.advance();
	cout << seq.current() << endl;
	
	return 0;
}
