#ifndef BITWISE_H_
#define BITWISE_H_

#include <iostream>
using namespace std;

typedef unsigned long bits;
const int BITS_IN_BYTE = 8;

class Bitwise {
	bits b;

public:
	Bitwise(int _b = 0) : b(_b) {}

	int length() const { return sizeof(bits) * BITS_IN_BYTE; }

	// Мутатори
	void set(int i);
	void reset(int i);

	// Селектор
	bool get(int i) const;


};

ostream& operator<<(ostream&, Bitwise const&);

#endif /* BITWISE_H_ */
void Bitwise::set(int i)
{
	b=b|(1<<i);
}
void Bitwise::reset(int i)
{
	b = b&(~(1 << i));
}
bool Bitwise::get(int i)const
{
	return (b&(1 << i)) >> i;
}


int main()
{
	system("pause");
	return 0;
}
