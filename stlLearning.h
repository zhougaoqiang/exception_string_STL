//vect1 -- introducing the vector template

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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