//singleton
#include <iostream>
#include <cstdlib>

using namespace std;


class Singleton{
	private:
		 static Singleton* instance;
		 Singleton() {}
	public:
		 static Singleton* getInstance() {
			if(instance == NULL) 
				instance = new Singleton();
			return instance;
		 }
	//its function is calling gc
	class CGarbo {
		public:
			~CGarbo() {
				if(Singleton::instance)
					delete Singleton::instance;
			}
	};
	static CGarbo Garbo; //define a static member, the system will call
			     //its destructor when the propram is ending.
};


int main() {
	return 0;
}
