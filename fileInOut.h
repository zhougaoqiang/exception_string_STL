#include <iostream>  //no need for many systems
#include <fstream>
#include <string>
#include <cstdlib> //for exit()
#include <iomanip>
#include <sstream> 

void fileio();   //saving to a file

void append();  //appending information to a file

inline void eatline1() { while (std::cin.get() != '\n') continue; }
struct planet
{
	char name[20];  //name of planet
	double population;  //its population
	double g; //its acceleration of gravity
};
void binary_File(); //binary fole I/O

void random();

void strout();  //incore formatting(output)内容格式化（输出）

void strin();  //formatted reading from a char array从char数组格式化读取

/*









*/

void fileio() {
	using namespace std;

	string filename;
	cout << "Enter name for new file: ";
	cin >> filename;


	//create output stream object for new file and call it fout
	ofstream fout(filename.c_str());

	fout << "For your eyes only!\n";   //write to file
	cout << "Enter your secret number； ";  //write to screen
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();  //close file

	//create input stream object for new file and call it fin
	ifstream fin(filename.c_str());
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))   //read character from file and 
	{
		cout << ch;   //write to screen
	}

	cout << "Done\n";
	fin.close();
}

void append() {
	const char * file = "guests.txt";

	using namespace std;
	char ch;
	//show initial contents
	ifstream fin;
	fin.open(file);

	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file: \n";
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}
	//add new names;
	ofstream fout(file, ios::out | ios::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names (enter a blank line to quit): \n";
	string name;
	while (getline(cin, name) && name.size()>0)
	{
		fout << name << endl;
	}
	fout.close();

	//show revised file显示修改后的文件
	fin.clear();  //not necessary for some compilers
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the " << file << " file: \n";
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}
	cout << "Done.\n";
}

void binary_File() {

	const char *file = "planets.dat";

	using namespace std;
	planet p1;
	cout << fixed << right;

	//show initial contents
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);  //binary file
	//NOTE: some system's don't accept the ios_base::binary mode
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		while (fin.read((char *)&p1, sizeof p1))  //(char *)&p1 --> &p1为引用，char * 代表指针？？？
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}


	//add new data
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	//note: some system's don't accept the ios_base::binary mode
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output: \n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatline1();
		cout << "Enter planetary population: ";
		cin >> p1.population;
		cout << "Enter planet's acceleration of gravity: ";
		cin >> p1.g;
		eatline1();
		fout.write((char *)&p1, sizeof p1);
		cout << "Enter planet name (Enter a blank line to quit:\n";
		cin.get(p1.name, 20);
	}
	fout.close();


	//show revised file
	fin.clear();   //not required for some implementations, but won't hurt
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "here are the new contents of the " << file << " file:\n";
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name << ": "
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	cout << "Done.\n";
}

void random() {
	const char * file = "plants1.dat";  //assumed to exist (binary.cpp example)

	using namespace std;
	planet pl;
	cout << fixed;

	//show initial contents
	fstream finout; //read and write streams
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	//Note: Some unix systems require omitting | ios::binary
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);  //go to beginning
		cout << "Here are the current contents of the " << file << " file:\n";
		while (finout.read((char *)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}

		if (finout.eof())
			finout.clear();   //clear eof flag
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " could not be opened -- bye.\n";
		exit(EXIT_FAILURE);
		/*
		cout << "Enter planet name (enter a blank line to quit):\n";
		cin.get(pl.name, 20);
		while (pl.name[0] != '\0')
		{
			eatline1();
			ct++;
			cout << "Enter planetary population: ";
			cin >> pl.population;
			cout << "Enter planet's acceleration of gravity: ";
			cin >> pl.g;
			eatline1();
			finout.write((char *)&pl, sizeof pl);
			cout << "Enter planet name (Enter a blank line to quit:\n";
			cin.get(pl.name, 20);
		}
		finout.close();
		*/
	}


	//change a record
	cout << "Enter the record number you wish to change: ";
	long rec;
	cin >> rec;
	eatline1();   //get rid of newline
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number -- bye\n";
		exit(EXIT_FAILURE);
	}

	streampos place = rec * sizeof pl; //convert to streampos type
	finout.seekg(place);  //random access
	if (finout.fail())
	{
		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)&pl, sizeof pl); 
	cout << "Your selection: \n";
	cout<<rec<<": "<<setw(20)<<pl.name<<": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
	{
		finout.clear(); //clear eof flag
	}
		

	cout << "Enter planet name: ";
	cin.get(pl.name, 20);
	eatline1();
	cout << "Enter planetary population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekp(place); //go back
	finout.write((char *)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "Error on attempted write\n";
		exit(EXIT_FAILURE);
	}

	//show revised file
	ct = 0;
	finout.seekg(0);   //go to beginning of file
	cout << "Here are the new contents of the " << file
		<< " file:\n";
	while (finout.read((char *)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(20) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}

	finout.close();
	cout << "Done.\n";
}

void strout()
{
	using namespace std;
	ostringstream outstr;  //manages a string stream
	string hdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's its capacity in GB? ";
	cin >> cap;

	//write formmated information to string stream
	outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gigabytes.\n";
	string result = outstr.str();   //save result;
	cout << result;   //show contents
}

void strin() {
	using namespace std;
	string lit = "It was a dark and stormy day, and the full moon glowed brilliantly. ";
	istringstream instr(lit);  //use buf for input
	string word;
	while (instr >> word)   //read a word a time
		cout << word << endl;
}