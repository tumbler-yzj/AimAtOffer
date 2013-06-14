//copy constructor
#include <iostream>
#include <cstdlib>

using namespace std;

class A{
	private:
		int value;
	public:
		A(int n) {
			value = n;
		}
		A(const A& other) {
			value = other.value;
		}
		void print() {
			cout << value << endl;
		}
};

int main()
{
	A a(10);
	A b = a;
	a.print();
	b.print();
	system("pause");
	return 0;
}

