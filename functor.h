//functor -- using a functor

#include <iostream>
#include <string>
#include <list>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

template<class T>  //functor class defines operator()()
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T &t) : cutoff(t) {}
	bool operator() (const T &v) { return v > cutoff; }
};

void outint1(int n) { std::cout << n << " "; }
void functor();

void funadap();
void Show(double);

void strgst1();

void listrmv();
void Show1(int);


char toLower(char ch) { return tolower(ch); }
void usealgo();
std::string & ToLower(std::string &st);
void display(const std::string &s);

/*






*/

void functor() {
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100);   //limit = 100
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10); //range constructor
	list<int> etcetera(vals, vals + 10);
	//C++ can use the following instead
	//list<int> yadayada = {50,100,90,180,60,210,415,88,188,201 };
	//list<int> etcetera{50,100,90,180,60,210,415,88,188,201 };

	cout << "original lists: \n";
	for_each(yadayada.begin(), yadayada.end(), outint1);
	cout << endl;
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint1);
	cout << endl;
	cout << endl;

	yadayada.remove_if(f100);   //use a named function object  移出超过100的
	etcetera.remove_if(TooBig<int>(200)); //construct a function object 移除超过200的
	cout << "Trimmed lists:\n";    //Trimmed：修剪
	for_each(yadayada.begin(), yadayada.end(), outint1);
	cout << endl;
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint1);
	cout << endl;
	cout << endl;
}

void funadap() {
	const int LIM = 6;

	using namespace std;
	double arr1[LIM] = { 28,29,30,35,38,59 };
	double arr2[LIM] = { 63,65,69,75,80,99 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);

	cout.setf(ios_base::fixed);
	cout.precision(1);
	cout << "gr8:\t";
	for_each(gr8.begin(), gr8.end(), Show);
	cout << endl;
	cout << endl;

	cout << "m8: \t";
	for_each(m8.begin(), m8.end(), Show);
	cout << endl;
	cout << endl;

	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());  
	//arr1和arr2中的每个对应的元素相加并赋值到sum中
	cout << "sum:\t";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;
	cout << endl;

	vector<double> prod(LIM);
	transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5)); 
	//将gr8中的每个元素乘以2.5
	cout << "prod:\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;
	cout << endl;
}
void Show(double v) {
	std::cout.width(6);
	std::cout << v << ' ';
}

void strgst1() {
	using namespace std;

	string letters;
	cout << "Enter the letter grouping (quit to quit): ";
	while (cin >> letters && letters != "quit")
	{
		cout << "Permutations of " << letters << endl;  //排列
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))  //next_permutation:下一个排列
		{
			cout << letters << endl;
		}

		cout << "Enter next sequence (quit to quit): ";
	}

	cout << "Done.\n";
}

void listrmv() {
	using namespace std;

	const int LIM = 10;
	int ar[LIM] = { 4,5,4,2,2,3,4,8,1,4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);
	cout << "Original list contects:\n\t";
	for_each(la.begin(), la.end(), Show1);
	cout << endl;
	cout << endl;

	la.remove(4);
	cout << "After using the remove() methods: \n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), Show1);
	cout << endl;
	cout << endl;

	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "After using the remove() function: \n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), Show1);
	cout << endl;
	cout << endl;

	lb.erase(last, lb.end());
	cout << "After using the erase() methods: \n";
	cout << "lb: \t";
	for_each(lb.begin(), lb.end(), Show1);
	cout << endl;
	cout << endl;
	cout << endl;
}
void Show1(int v) {
	std::cout << v << " ";
}

void usealgo() {
	using namespace std;

	vector<string> words;
	cout << "Enter words (enter quit to quit): \n";
	string input;
	while (cin>>input && input != "quit")
	{
		words.push_back(input);
	}

	cout << "You entered the following words:\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;
	cout << endl;

	//place words in set, converting to lowercase
	set<string>wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
	cout << "\nAlphabetic list of words:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;
	cout << endl;

	//place word and frequency in map
	map<string, int>wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);

	//display map content
	cout << "\nWord frequency\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
	{
		cout << *si << ": " << wordmap[*si] << endl;
	}
	cout << endl;
	cout << endl;

}
std::string & ToLower(std::string &st) {
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}
void display(const std::string &s) {
	std::cout << s << " ";
}