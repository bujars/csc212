#include "Bag1.h"

int main(){

	typedef int bagDataType;
	static const size_t SIZE = 100;
	/* Testing Bag1()*/
	Bag1 b1;
	Bag1 b2;
	Bag1 b3;
	/*NOTE...cannot really test this out because 
	 * there is nothing to print from it. 
	 * ie no public variable that we can access. So lets check totVals before we insert*/
	cout << "Testing constructor" << endl;
	cout << b1.totVals() << "\n";
	cout << b2.totVals() << "\n";
	cout << b3.totVals() << "\n";




	/* Testing void insert(const bagDataType& num)*/
	cout << "Testing insert\n";
	b1.insert(1);
	cout << b1.totVals() << "\n";
	b1.insert(100);
	cout << b1.totVals() << "\n";
	b1.insert(0);
	cout << b1.totVals() << "\n";
	b2.insert(0);
	b2.insert(0);
	b2.insert(0);
	b3.insert(-1);
	b3.insert(-100);
	b3.insert(-2);

	/*Testing size_t erase(const bagDataType& num)*/
	cout << "Testing erase\n";
	cout << b2.erase(0) << endl;
	cout << b2.totVals() << "\n";
	cout << b2.erase(0) << endl;
	cout << b1.erase(0) << endl;

	/* Testing bool eraseOne(const bagDataType& num)*/
	cout << "Testing eraseOne\n";
	cout << b2.eraseOne(0) << endl;
	cout << b1.eraseOne(1) << endl;
	cout << b1.eraseOne(0) << endl;
	cout << b1.eraseOne(-1) << endl;
	cout << b3. eraseOne(-1) << endl;	

	/* Testing void operator +=(const Bag1& addend);*/																											
	cout << "Testing +=\n";
	b1+=b2;
	cout << b1.totVals() << endl;
	b2+=b2;
	cout << b2.totVals() << endl;
	b2+= b1;
	cout <<  b2.totVals() << endl;
	b1+=b3;
	cout << b1.totVals() << endl;
	b3+=b3;
	cout << b3.totVals() << endl;
	
	/* Testing size_t occurances(const bagDataType& num) const*/
	cout << "Testing occurances\n";
	cout << b1.occurances(-100) << endl; 
	cout << b1.occurances(100) << endl;
	cout << b2. occurances(0) << endl;
	cout << b3.occurances(-2) << endl;
	
	/* Testing size_t totVals() const*/
	cout << "Testing totVals\n";
	cout << b1.totVals() << "\n";
	cout << b2.totVals() << "\n";
	cout << b3.totVals() << "\n";
	/* Testing Bag1 operator +(const Bag1& b1, const Bag1& b2)*/ 
	cout << "Testing +\n";
	Bag1 bag; 
	bag = b1 + b2;
	cout << bag.totVals() << endl;
	bag = b1+b3;
	cout << bag.totVals() << endl;
	bag = b2+b2;
	cout << bag.totVals() << endl;

	return 0;
}
