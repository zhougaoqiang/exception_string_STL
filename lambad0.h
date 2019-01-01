//lambda0 -- using lambda expression 使用lambda表达式


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x) { return x % 3 == 0; }
bool f13(int x) { return x % 13 == 0; }

void lambda0();

/*







*/

void lambda()
{
	using namespace std;
	vector<int> numbers(Size1);

	srand(time(0));
	generate(numbers.begin(), numbers.end(), rand);

	//using function pointers
	cout << "Sample size = " << Size1 << '\n';

	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "count of numbers divisible by 3: " << count3 << '\n';
	int count13 = count_if(numbers.begin(), numbers.end(), f13);
	cout << "count of numbers divisible by 13: " << count13 << "\n\n";



	//increase number of numbers
	numbers.resize(Size2);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size2 << '\n';

	//using a functor
	class f_mod
	{
	public:
		f_mod(int d = 1) :dv(d) {};
		bool operator() (int x) { return x % dv == 0; }
	private:
		int dv;
	};

	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << "count of numbers divisible by 3: " << count3 << '\n';
	count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));
	cout << "count of numbers divisible by 13: " << count13 << "\n\n";


	//increase number of numbers again
	numbers.resize(Size3);
	generate(numbers.begin(), numbers.end(), rand);
	cout << "Sample size = " << Size3 << '\n';

	//using lambdas
	count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << "count of numbers divisible by 3: " << count3 << '\n';
	count13 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 13 == 0; });
	cout << "count of numbers divisible by 13: " << count13 << "\n\n";
}




