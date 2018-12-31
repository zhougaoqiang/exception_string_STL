#include <iostream>
#include <cstring>  //or else string.h
#include <cmath>
#include <iomanip>

void write();  //using cout.write()

void defaults();  //cout default format

void manip(); //using format manipulators(控制符)

void width(); //using width method 调整字段宽度

void fill();   //changing fill character for fields

void precise();  //setting the precision显示精度

void setf_Test();  //using setf() to contorol formatting

void setf_Test2();  //using setf() with 2 arguments to control formatting

void iomanip(); //using manipulators from iomanip
//some systems require explictitly link the math library

/*






*/

void write() {
	using std::cout;
	using std::endl;

	const char *state1 = "Florida";
	const char *state2 = "Kansas";
	const char *state3 = "Euphoria";

	int len = std::strlen(state2);
	cout << "Increasing loop index:\n";
	int i;
	for (i = 1; i <= len; i++)
	{
		cout.write(state2, i);   //i 代表streamsize及-显示前i位
		cout << endl;
	}

	//concatenate output 连接输出
	cout << "decreasing loop index:\n";
	for (i = len; i > 0; i--)
		cout.write(state2, i) << endl;

	//exceed string length
	cout << "Exceeding string length:\n";
	cout.write(state2, len + 5) << endl;
}

void defaults() {
	using std::cout;

	cout << "12345678901234567890\n";   //output: 12345678901234567890
	char ch = 'k';
	int t = 273;
	cout << ch << ":\n";    //output: k
	cout << t << ":\n";   //output: 273
	cout << -t << ":\n";   //output: -273

	double f1 = 1.200;
	cout << f1 << ":\n";   //output: 1.2
	cout << (f1 + 1.0 / 9.0) << ":\n";   //output: 1.31111

	double f2 = 1.67E2;
	cout << f2 << ":\n";   //output: 167
	f2 += 1.0 / 9.0;
	cout << f2 << ":\n";  //output:  167.111
	cout << (f2*1.0e4) << ":\n";  //output: 1.67111e+06

	double f3 = 2.3e-4;
	cout << f3 << ":\n";  //output: 0.00023
	cout << f3 / 10 << ":\n";  //output:2.3e-05
}

void manip() {
	using namespace std;
	cout << "enter an integer: ";
	int n;
	cin >> n;

	cout << "n     n*n\n";
	cout << n << "    " << n * n << " (decimal)\n";  //默认10进制

	//set to hex mode
	cout << hex;
	cout << n << "    ";
	cout << n * n << " (hexadecimal)\n";   //16进制

	//set to octal mode
	cout << oct << n << "   " << n * n << " (octal)\n"; //8进制

	//alternative way to call a manipulator
	dec(cout);
	cout << n << "    " << n * n << " (decimal)\n"; //10进制
} 

void width() {
	using std::cout;
	int w = cout.width(30);
	cout << "default field width = " << w << ":\n";
	cout.width(5);
	cout << "N" << ':';
	cout.width(8);
	cout << "N*N" << ":\n";

	for (long i = 1; i <= 100; i *= 10)
	{
		cout.width(5);
		cout << i << ":";
		cout.width(8);
		cout << i * i << ":\n";
	}
}

void fill() {
	using std::cout;

	cout.fill('*');
	const char * staff[2] = { "Waldo Whipsnade", "wilmarie Wooper" };
	long bonus[2] = { 900,1350 };

	for (int i = 0; i < 2; i++)
	{
		cout << staff[i] << ": $";
		cout.width(7);
		cout << bonus[i] << "\n";
	}
}

void precise() {
	using std::cout;

	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout << "\"Furry Friends\" is $" << price1 << "!\n";  //output:$20.4
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";  //output:$2.78889  (默认小数点后5位）

	cout.setf(std::ios_base::showpoint);
	cout << "\"Furry Friends\" is $" << price1 << "!\n";  //output:$20.4000(默认小数点后5位）
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";  //output:$2.78889(默认小数点后5位）

	cout.precision(2);
	cout << "\"Furry Friends\" is $" << price1 << "!\n";  //output:$20
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";  //output:$2.8
}

void setf_Test() {
	using std::cout;
	using std::endl;
	using std::ios_base;

	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);  //show plus sign
	cout << temperature << endl;

	cout << "For our programming friends, that's\n";
	cout << std::hex << temperature << endl;  //use hex
	cout.setf(ios_base::uppercase);  //use uppercase in hex
	cout.setf(ios_base::showbase);   //use 0X prefix for hex
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "!  oops -- How ";   //此处true为“1” 可和下面的对比
	cout.setf(ios_base::boolalpha);
	cout << true << "!\n";
}

void setf_Test2() {
	using namespace std;
	//use left justification, show the plus sign, show trailing
	//zeros, with a precision of 3

	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);
	//use e-notation and save old format setting
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << "Left Justification: \n";
	long n;
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}


	cout << endl;
	cout << endl;
	//change to internal justification
	cout.setf(ios_base::internal, ios_base::adjustfield);
	//restore default floating-point display style
	cout.setf(old, ios_base::floatfield);

	cout << "Internal Justification: \n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout << endl;
	cout << endl;
	//use right justification, fixed notation
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Right Justification: \n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}


/*
output:
	Left Justification:
+1  |+1.000e+00  |
+11 |+3.317e+00  |
+21 |+4.583e+00  |
+31 |+5.568e+00  |
+41 |+6.403e+00  |


Internal Justification:
+  1|+       1.00|
+ 11|+       3.32|
+ 21|+       4.58|
+ 31|+       5.57|
+ 41|+       6.40|


Right Justification:
  +1|      +1.000|
 +11|      +3.317|
 +21|      +4.583|
 +31|      +5.568|
 +41|      +6.403|
	*/
}

void iomanip() {
	using namespace std; //use new standard manipulators
	cout << fixed << right;

	//use iomanip manipulators
	cout << setw(6) << "N" << setw(14) << "square root"
		<< setw(15) << "fourth root\n";

	double root;
	for (int n = 10; n <= 100; n += 10)
	{
		root = sqrt(double(n));
		cout << setw(6) << setfill('*') << n << setfill(' ')
			<< setw(12) << setprecision(3) << root
			<< setw(14) << setprecision(4) << sqrt(root)
			<< endl;
	}
}