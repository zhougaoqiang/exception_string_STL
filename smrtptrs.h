//smrtptrs.cpp -using three kinds of smart pointers
//requires support of C++11 shared_ptr and unique_ptrt

#include <iostream>
#include <string>
#include <memory>

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) :str(s)
	{
		std::cout << "Object created!\n";
	}

	~Report()
	{
		std::cout << "Object deleted!\n";
	}

	void comment() const { std::cout << str << "\n"; }
};

void smrtptrs();
void fowl();

void smrtptrs()
{
	{
	std::auto_ptr<Report> ps(new Report("using auto_ptr"));
	ps->comment();      //use -> to invoke a member function. 调用成员函数。
	}
	std::cout << std::endl;
	std::cout << std::endl;

	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
}
void fowl(){
	using namespace std;
	shared_ptr<string> films[5] =
	{
		shared_ptr<string>(new string("Fowl Balls")),
		shared_ptr<string>(new string("Duck Walks")),
		shared_ptr<string>(new string("Chicken Runs")),
		shared_ptr<string>(new string("Turkey Errors")),
		shared_ptr<string>(new string("Goose Eggs"))
	};

	shared_ptr<string> pwin;
	pwin = films[2];   //films[2] loses ownership

	cout << "The nominees for best avian baseball film are\n";
	for (int i = 0; i < 5; i++)
		cout << *films[i] << endl;

	cout << "The winner is " << *pwin << "!\n";
	cin.get();
}