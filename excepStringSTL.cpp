// excepStringSTL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "sales.h"
#include "smrtptrs.h"
#include "stlLearning.h"
#include "functor.h"
#include "otherlibrary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>

void str1();
void strfile();
void hangman();
void str2();
/*
int main()
{
	//use_sales();
	//str1();
	//strfile();
	//hangman();
	//str2();
	//smrtptrs();
	//fowl();
	//vect1();
	//vect2();
	//vect3();
	//copyit();
	//inserts();
	//list1();
	//setops();
	//multimap();
	//functor();
	//funadap();
	//strgst1();
	//listrmv();
	//usealgo();
	//valvect();
	//vslice();
	ilist();
}
*/
void str1() {
	using namespace std;

	string one("Lottery Winner!"); //ctor #1
	cout << one << endl;					//output:Lottery Winner!
	string two(20, '$'); //ctor #2
	cout << two << endl;					//output:$$$$$$$$$$$$$$$$$$$$
	string three(one);
	cout << three << endl;  //ctor #3		//output: Lottery Winner!
	one += " Oops!";   //overloaded +=
	cout << one << endl;					//output: Lottery Winner! Oops!
	two = "Sorry! that was ";
	three[0] = 'P';
	string four;//ctor #4					
	four = two + three;  //overloaded +, =
	cout << four << endl;						//output: Sorry! that was Pottery Winner!
	char alls[] = "All's well that ends well";
	string five(alls, 20);  //ctor #5
	cout << five << "!\n";						//output: All's well that ends!
	string six(alls + 6, alls + 10); //ctor #6
	cout << six << ", ";						//output: well,
	cout << endl;
	cout << endl;
	string seven(&five[6], &five[10]);  //ctor #6 again
	cout << seven << "...\n";					//output: well...
	string eight(four, 7, 16);   //ctor #7
	cout << eight << " in motion!" << endl;		//output: that was Pottery in motion!

}
void strfile() {
	using namespace std;

	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)   //while input is good
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n";
	fin.close();
}
void hangman() {
	using namespace std;

	const int NUM = 26;
	const string wordlist[NUM] = { "apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage",
	"health", "insult", "jackal", "keeper", "loaner", "manage", "nonce", "onset", "plaid", "quilt", "remote",
	"stolid", "train", "useful", "valid", "whence", "xenon", "yearn", "zippy" };

	std::srand(std::time(0));
	char play;
	cout << "will you play a word game? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;


		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "You already gussed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; //add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				//check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		
		cout << "Will you play another? <y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye\n";
}
void str2() {
	using namespace std;

	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "Size: \n";
	cout << "\tempty:" << empty.size() << endl;   //0
	cout << "\tsmall:" << small.size() << endl;    //3
	cout << "\tlarger:" << larger.size() << endl;    //34
	cout << "Capacities: \n";
	cout << "\tempty:" << empty.capacity() << endl;   //15
	cout << "\tsmall:" << small.capacity() << endl;    //15
	cout << "\tlarger:" << larger.capacity() << endl;  //47
	empty.reserve(50);
	cout << "Capacity afer empty.reserve(50): "
		<< empty.capacity() << endl;    //63
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
