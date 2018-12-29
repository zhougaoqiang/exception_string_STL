//vect1 -- introducing the vector template

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <list>
#include <map>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

struct Review
{
	std::string title;
	int rating;
};

void vect1();

void vect2();
bool FillReview(Review & rr);
void ShowReview(const Review &rr);

void vect3();
bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);

void copyit();

void output(const std::string & s) { std::cout << s << " "; }
void inserts();

void list1();
void outint(int n) { std::cout << n << " "; }

void setops();

void multimap();
/*






*/
void vect1()
{
	const int NUM = 5;

	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;

	vector<int> ratings(NUM);
	vector<string> titles(NUM);

	cout << "You will do exactly as told. You will enter\n"
		<< NUM << "book titles and your ratings(0-10). \n";

	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << "Enter title #" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "Enter your raing (0-10): ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "Thank you. You enter the following: \n"
		<< "rating\tBool\n";
	for (i = 0; i < NUM; i++)
	{
		cout << ratings[i] << "\t" << titles[i] << std:: endl;
	}
}

void vect2()
{
	using std::cout;
	using std::vector;

	vector<Review> books;
	Review temp;
	while (FillReview(temp))
	{
		books.push_back(temp);   //将元素添加到矢量末尾
	}

	int num = books.size();
	
	if (num > 0)
	{
		cout << "thank you. You enter the following: \n"
			<< "rating\tBook\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);

		cout << "Reprising: \n"
			<< "Rating\t\Book\n";
		vector<Review>::iterator pr;   //将pr声明为一个迭代器
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);

		vector<Review> oldlist(books); //copy constructor used 保存旧数据

		if (num > 3)
		{
			cout << std::endl;
			cout << std::endl;
			//remove 2 items
			books.erase(books.begin() + 1, books.begin() + 3);  //删除第二位到第四位之间的数据，但不包括第四位
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);

			cout << std::endl;
			cout << std::endl;
			//insert 1 item
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);  
			//添加原数据中第二位到第三位之间的数据（不包括第三位）到本数据的第一位

			cout << "After insertion: \n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			cout << std::endl;
			cout << std::endl;
		}
		books.swap(oldlist);   //将原数据交换给books
		cout << "Swapping oldlist with books: \n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "nothing enterd, nothing gained.\n";

}
bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;

	//get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}
void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

void vect3()
{
	using namespace std;
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);

	if (books.size() > 0)
	{
		cout << "Thank you. You enter the following "
			<< books.size() << " rating:\n"
			<< "Rating\tBook\n";

		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;
		cout << endl;

		sort(books.begin(), books.end());   //sorted by operator <
		cout << "Sorted by title:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;
		cout << endl;

		sort(books.begin(), books.end(),worseThan);   //sorted by worseThan
		cout << "Sorted by title:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;
		cout << endl;

		random_shuffle(books.begin(), books.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
		cout << endl;
		cout << endl;
	}
	else
		cout << "No entries.";

	cout << "Bye.\n";
}
bool operator<(const Review & r1, const Review & r2)    //use for default sort
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)   
		return true;
	else
		return false;
}
bool worseThan(const Review & r1, const Review & r2)  //use for sort
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

void copyit() {
	using namespace std;

	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);

	//copu from array to vector

	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";     //cast:投

	ostream_iterator<int, char>out_iter(cout, " ");    //create an ostream iterator创建一个ostream迭代器
	copy(dice.begin(), dice.end(), out_iter);    //copy from vector to output从矢量复制到输出
	cout << endl;
	cout << "Implicit use of reverse iterator.\n";   //隐式使用反向迭代器。
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "Explicit use of reverse iterator.\n";  //显式使用反向迭代器
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;
}

void inserts() {
	using namespace std;
	string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;
	cout << endl;

	//construct annoymous back_insert_iterator object
	copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));   //在words数组最后加上s2的字符串
	for_each(words.begin(), words.end(), output);
	cout << endl;
	cout << endl;

	//construct anonymous insert_iterator object
	copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin())); //在words数组最前加上s2的字符串
	for_each(words.begin(), words.end(), output);
	cout << endl;
	cout << endl;
}

void list1() {
	using namespace std;

	list<int> one(5, 2);   //list of 5 2s
	int stuff[5] = { 1,2,4,8,6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6,4,2,4,6,5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "list one: ";
	for_each(one.begin(), one.end(), outint);

	cout << endl << "List two: ";
	for_each(two.begin(), two.end(), outint);

	cout << endl << "List three: ";
	for_each(three.begin(), three.end(), outint);

	three.remove(2);
	cout << endl << "List three minus 2s: ";
	for_each(three.begin(), three.end(), outint);

	three.splice(three.begin(), one);    //splice:拼接
	cout << endl << "List three after splice: ";
	for_each(three.begin(), three.end(), outint);

	cout << endl << "List one: ";
	for_each(one.begin(), one.end(), outint);
	three.unique();

	cout << endl << "List three after unique: ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout<< endl << "List three aftre sort & unique: ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "Sorted two merged into three: ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
}

void setops() {
	using namespace std;
	const int N = 6;

	string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	set<string> A(s1, s1 + N);    //initialize set A using a range from array 排序，删除重复
	set<string> B(s2, s2 + N);

	ostream_iterator<string, char> out(cout, " ");  //在字符串中添加空格
	cout << "Set A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << endl;

	cout << "Set B:";
	copy(B.begin(), B.end(), out);
	cout << endl;
	cout << endl;

	cout << "Union of A and B: \n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);  //讲两个集合合并
	cout << endl;
	cout << endl;

	cout << "Intersection of A and B: \n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);  //两个集合的交集
	cout << endl;
	cout << endl;

	cout << "Difference of A and B: \n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);  //两个集合的差
	cout << endl;
	cout << endl;
	cout << endl;

	set<string> C;
	cout << "Set C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	//讲集合A，B合并后插入C中
	copy(C.begin(), C.end(), out);
	cout << endl;
	cout << endl;

	string s3("grungy");
	C.insert(s3);           //添加S3
	cout << "Set C after insertion:\n";   
	copy(C.begin(), C.end(), out);
	cout << endl;
	cout << endl;

	cout << "Showing a range: \n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);   //将“ghost"和”spook“之间的字符串保留
	cout << endl;
	cout << endl;
}

void multimap() {
	using namespace std;
	MapCode codes;
	//pair:对
	codes.insert(Pair(415, "San Francisco"));   
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Staten Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Berkeley"));

	cout << "Number of cities with area code 415: "
		<< codes.count(415) << endl;
	cout << endl;

	cout << "Number of cities with area code 718: "
		<< codes.count(718) << endl;
	cout << endl;

	cout << "Number of cities with area code 510: "
		<< codes.count(510) << endl;
	cout << endl;

	cout << "Area Code  City\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
		cout << "   " << (*it).first << "   "
		<< (*it).second << endl;
	cout << endl;

	pair<MapCode::iterator, MapCode::iterator>range
		= codes.equal_range(718);
	cout << "Cities with area code 718: \n";
	for (it = range.first; it != range.second; ++it)
		cout << (*it).second << endl;
	cout << endl;
}