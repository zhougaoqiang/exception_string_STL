//sales.cpp -- sales implementation

#include "pch.h"
#include "sales.h"
#include <iostream>
using std::string;

Sales::bad_index::bad_index(int ix, const string &s)
	:std::logic_error(s), bi(ix)
{
}

Sales::Sales(int yy)
{
	year == yy;
	for (int i = 0; i < MONTHS; i++)
		gross[i] = 0;
}

Sales::Sales(int yy, const double * gr, int n)
{
	year = yy;
	int lim = (n < MONTHS) ? n : MONTHS;
	int i;
	for (i = 0; i < lim; ++i)
		gross[i] = gr[i];

	//for i > n and i < MONTHS
	for (; i < MONTHS; i++)
		gross[i] = 0;
}

double Sales::operator[] (int i) const
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

double & Sales::operator[] (int i)
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

LabeledSales::nbad_index::nbad_index(const string & lb, int ix, const string & s)
	:Sales::bad_index(ix, s)
{
	lbl = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy)
	: Sales(yy)
{
	label = lb;
}

LabeledSales::LabeledSales(const string & lb, int yy, const double * gr, int n)
	: Sales(yy, gr, n)
{
	label = lb;
}

double LabeledSales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
}


void use_sales() {
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334, 2884, 2399, 3302, 2922, 3002, 3544
	};
	double vals2[12] =
	{
		12,11,22,21,32,34,28,29,33,29,32,35
	};
	Sales sales(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "first try block: \n";
	try
	{
		int i;
		cout << "Year = " << sales.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Lable = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (LabeledSales::nbad_index &bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.Label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index &bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch (LabeledSales::nbad_index &bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.Label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "done\n";
}