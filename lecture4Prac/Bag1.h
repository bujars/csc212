#ifndef __BAG1_H__
#define __BAG1_H__



#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


	class Bag1{
		public:
			typedef int bagDataType;
			static const std::size_t SIZE = 100;
			Bag1();
			void insert(const bagDataType& num);
			size_t erase(const bagDataType& num);
			bool eraseOne(const bagDataType& num);
			void operator +=(const Bag1& addend);
			size_t occurances(const bagDataType& num) const;
			size_t totVals() const;
		private:
			size_t used;
			bagDataType data[SIZE];

	
	};
	Bag1 operator +(const Bag1& b1, const Bag1& b2);





#endif
