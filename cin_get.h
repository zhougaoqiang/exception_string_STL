#include <iostream>

void check_it();  //checking for valid input

void cinexcep();  //having cin throw an exception

void get_fun(); //using get() and getline()

void peeker();  //some istream methods

void truncate(); //using get() to truncate input line, if necessary 如有必要，截断输入行
inline void eatline() { while (std::cin.get() != '\n') continue; }


/*









*/
void check_it() {
	using namespace std;

	cout << "Enter numbers: ";

	int sum = 0;
	int input;

	while (cin >> input)
	{
		sum += input;
	}

	cout << "LAst value entered = " << input << endl;
	cout << "Sum = " << sum << endl;
}

void cinexcep() {
	using namespace std;

	//have failbit cause an exception to be thrown 有failbit导致抛出异常
	cin.exceptions(ios::ios_base::failbit);
	cout << "Enter numbers: ";
	int sum = 0;
	int input;

	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure &bf)
	{
		cout<<bf.what() << endl;
		cout << "O! the horror!\n";
	}

	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;

}

void get_fun() { 
	const int Limit = 255;

	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];

	cout << "Enter a string for getLine() processing: \n";
	cin.getline(input, Limit, '!');
	cout << "Here is your input: \n";
	cout << input << "\nDone with phase 1 \n";

	cout << endl;
	cout << endl;

	char ch;
	cin.get(ch);
	cout << "The next input character is " << ch << endl;

	if (ch != '\n')
		cin.ignore(Limit, '\n');  //discard reset of line

	cout << "Enter a string for get() processing: \n";
	cin.get(input, Limit, '#');
	cout << "Here is your input: \n";
	cout << input << "\nDone with phase 2\n";

	cin.get(ch);
	cout << "The next input character is " << ch << endl;
}

void peeker() {
	using std::cout;
	using std::cin;
	using std::endl;

	//read and echo input up to a # character
	char ch;

	while (cin.get(ch))   //terminates on EOF
	{
		if (ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch);  //reinsert character
			break;
		}
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		std::exit(0);
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	while (cin.peek() != '#')   //look ahead 继续读取
	{
		cin.get(ch);
		cout << ch;
	}
	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
		cout << "End of file reached.\n";
}

void truncate() {
	const int SLEN = 10;

	using std::cout;
	using std::cin;
	using std::endl;

	char name[SLEN];
	char title[SLEN];
	cout << "Enter your name: ";
	cin.get(name, SLEN);

	if (cin.peek() != '\n')
		cout << "Sorry, we only have enough room for "
		<< name << endl;

	eatline();
	cout << "Dear " << name << ", enter your title: \n";

	cin.get(title, SLEN);
	if (cin.peek() != '\n')   //第9个字符停止或遇到回车
		cout << "We were forced to truncate yout title.\n";

	eatline();
	cout << " Name: " << name << "\nTitle: " << title << endl;
}