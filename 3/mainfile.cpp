#include <iostream>

using namespace std;

class Length
{
private:
	int ft;
	double in;

public:
	//constructors
	Length(): ft(0), in(0)
	{}
	Length(int f, double i): ft(f), in(i)
	{}

	//access functions
	int getFeet()
	{return ft;}
	double getInches()
	{return in;}
	double getLength()
	{return (ft * 12) + in;}
	Length Add(Length l);
	bool LessThan(Length l);
	bool GreaterThan(Length l);
	bool EqualTo(Length l);

	//modifier functions
	void setFeet(int f)
	{ft = f;}
	void setInches(double i)
	{in = i;}                 //cast used here to avoid warning message
	void setValue(int f, double i)
	{ft = f; in = i;}         //cast used here to avoid warning message
	void AddTo(Length l);

	//input/output functions
	void Read();
	void Write();
};                 //end of Length class specification

//Length class member function definitions
Length Length::Add(Length l)
{
	Length temp;
	temp.ft = ft + l.ft;
	temp.in = in + l.in;
	if (temp.in >= 12) {
		temp.ft++;
		temp.in = temp.in - 12;
	}

	return temp;
}

bool Length::LessThan(Length l)
{
	bool result;

	if ((ft < l.ft) || ((ft==l.ft) && (in < l.in)))
		result = true;
	else
		result = false;

	return result;
}

bool Length::GreaterThan(Length l)
{
	return (ft > l.ft) || ((ft==l.ft) && (in > l.in));
}

bool Length::EqualTo(Length l)
{
	return (ft == l.ft) && (in == l.in);
}

void Length::AddTo(Length l)
{
	ft = ft + l.ft;
	in = in + l.in;

	if (in >=12) {
		ft++;
		in -= 12;
	}
}

void Length::Read()
{
	char skip;
	cin >> ft >> skip >> in >> skip;
}

void Length::Write()
{
	cout << ft << "'" << in << '"';
}

void main()
{
    Length len1, len2, len3;      //The 3 values to be sorted

    cout << "Enter first value to be sorted: ";
    len1.Read();
    cout << "Enter second value to be sorted: ";
    len2.Read();
    cout << "Enter third value to be sorted: ";
    len3.Read();

    cout << "\nThe 3 values in sorted order are\n\n";

    if (len1.LessThan(len2) && len1.LessThan(len3)) {
        len1.Write();
        cout << endl;
        if(len2.LessThan(len3)) {
            len2.Write();
            cout << endl;
            len3.Write();
            cout << endl;
        }
        else {
            len3.Write();
            cout << endl;
            len2.Write();
            cout << endl;
        }
    }
    else if(len2.LessThan(len1) && len2.LessThan(len3)) {
        len2.Write();
        cout << endl;
        if (len1.LessThan(len3)) {
            len1.Write();
            cout << endl;
            len3.Write();
            cout << endl;
        }
        else {
            len3.Write();
            cout << endl;
            len1.Write();
            cout << endl;
        }
    }
    else {
        len3.Write();
        cout << endl;
        if (len1.LessThan(len2)) {
            len1.Write();
            cout << endl;
            len2.Write();
            cout << endl;
        }
        else {
            len2.Write();
            cout << endl;
            len1.Write();
            cout << endl;
        }
    }

    cout << endl;
}

    