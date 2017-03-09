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
	Length operator+(Length l);
	bool operator<(Length l);
	bool operator>(Length l);
	bool operator==(Length l);

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

    //friend declarations
    friend istream& operator>>(istream& strm, Length& ln);
    friend ostream& operator<<(ostream& strm, Length ln);
};                 //end of Length class specification

//Length class member function definitions
Length Length::operator+(Length l)
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

bool Length::operator<(Length l)
{
	bool result;

	if ((ft < l.ft) || ((ft==l.ft) && (in < l.in)))
		result = true;
	else
		result = false;

	return result;
}

bool Length::operator>(Length l)
{
	return (ft > l.ft) || ((ft==l.ft) && (in > l.in));
}

bool Length::operator==(Length l)
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

istream& operator>>(istream& strm, Length& ln)
{
	char skip;
	strm >> ln.ft >> skip >> ln.in >> skip;

    return strm;
}

ostream& operator<<(ostream& strm, Length ln)
{
	strm << ln.ft << "'" << ln.in << '"';

    return strm;
}

bool MoreData();
void ToLower(char s[]);
void Sort(Length list[], int count);

void main()
{
    Length lengthList[100];       //list of array values to be sorted
    int lengthCount = 0;

    while (MoreData()) {
        cout << "Enter length value (ft\"in'): ";
        cin >> lengthList[lengthCount++];
    }

    Sort(lengthList, lengthCount);

    cout << "\nLength values in sorted order" << endl;
    for (int i=0; i < lengthCount; i++)
        cout << lengthList[i] << endl;

    cout << endl;
}

void ToLower(char s[])
{
    for (int i=0; s[i]; i++)
        if ((s[i] >= 'A') && (s[i] <= 'Z'))      //if uppercase
            s[i] |= 0x20;
}

bool MoreData()
{
    char yesNoResponse[4];

    do {
        cout << "Do you have a length value to be sorted? (yes/no): ";
        cin >> yesNoResponse;
        ToLower(yesNoResponse);
    } while (strcmp(yesNoResponse, "yes") && strcmp(yesNoResponse, "no"));

    return (strcmp(yesNoResponse, "yes") == 0);
}

void Sort(Length list[], int count)
{
    for (int i=count-1; i; i--)
        for (int j=0; j < i; j++)
            if (list[j] > list[j+1])
                swap(list[j], list[j+1]);
}