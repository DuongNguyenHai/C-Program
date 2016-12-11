#include <iostream>

class foo
{
public:
	foo();
	~foo();
	friend void bar(foo &a);
	void set(foo &a);
private:
	int size;
};

foo::foo() {};
foo::~foo() {}
void foo::set(foo &a) {
	size = 10;
	bar(a);
}

void bar(foo &a) {
	std::cout << "size: " << a.size << "\n";
}

int main(int argc, char const *argv[])
{
	foo a;
	a.set(a);
	// bar(a);
	return 0;
}