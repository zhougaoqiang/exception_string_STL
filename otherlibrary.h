
#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <initializer_list>

void valvect();  //valvect--comparing vector and valarray

void vslice(); //using valarray slices Ƭ
typedef std::valarray<int> vint; //simplify declarations
void show(const vint &v, int cols);

void ilist();
double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double> &ril);
/*





*/

void valvect() {
	using namespace std;
	vector<double>data;
	double temp;

	cout << "Enter numbers (<=0 to quit): \n";
	while (cin>>temp && temp >0)
	{
		data.push_back(temp);
	}
	sort(data.begin(), data.end());
	int size = data.size();

	valarray<double> numbers(size);
	int i;
	for (i = 0; i < size; i++)
		numbers[i] = data[i];

	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0*sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);
	for (i = 0; i < size; i++)
	{
		cout.width(8);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}
	cout << "done\n";
}

void vslice()
{
	const int SIZE = 12;

	using std::slice;   //from <valarray>
	using std::cout;
	vint valint(SIZE);  //think of as 4 rows of 3

	int i;
	for (i = 0; i < SIZE; ++i)
		valint[i] = std::rand() % 10;

	cout << "Original array: \n";
	show(valint, 3);  //show in 3 columns
	vint vcol(valint[slice(1, 4, 3)]); //extract 2nd row

	cout << "Second row:\n";
	show(vcol, 1);  //show in 1 column

	vint vrow(valint[slice(3, 3, 1)]);  //extract 2nd row
	cout << "Second column:\n";
	show(valint, 3);
	valint[slice(2, 4, 3)] = 10; //assign to 2nd column
	cout << "Set last column to 10:\n";
	show(valint, 3);
	cout << "Set first column to sum of next two: \n";
	//+ not defined for slices, so convert to valarray<int>
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
	show(valint, 3);
}
void show(const vint &v, int cols) {
	using std::cout;
	using std::endl;

	int lim = v.size();
	for (int i = 0; i < lim; ++i)
	{
		cout.width(3);
		cout << v[i];
		if (i %cols == cols - 1)
			cout << endl;
		else
			cout << ' ';
	}
	if (lim % cols != 0)
		cout << endl;
}

void ilist()
{
	using std::cout;
	using std::endl;

	cout << "List 1: sum = " << sum({ 2,3,4 })
		<< ", ave = " << average({ 2,3,4 }) << '\n';
	cout << endl;
	cout << endl;

	std::initializer_list<double> d1 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	cout << "List 2: sum = " << sum(d1)
		<< ", ave = " << average(d1) << '\n';
	cout << endl;
	cout << endl;

	d1 = { 16.0, 25.0,36.0,40.0,64.0};
	cout << "List 3: sum = " << sum(d1)
		<< ", ave = " << average(d1) << '\n';
}
double sum(std::initializer_list<double> il)
{
	double tot = 0;
	for (auto p = il.begin(); p != il.end(); p++)
		tot += *p;
	return tot;
}
double average(const std::initializer_list<double> &ril)
{
	double tot = 0;
	int n = ril.size();
	double ave = 0.0;
	if (n > 0)
	{
		for (auto p = ril.begin(); p != ril.end(); p++)
			tot += *p;
		ave = tot / n;
	}
	return ave;
}