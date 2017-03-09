#include <iostream>

using namespace std;

class Length
{
private:
    int ft;
    double in;

public:
    //constructors
    Length() : ft(0), in(0)
    {}
    Length(int f, double i) : ft(f), in(i)
    {}

    //access functions
    int getFeet()
    {
        return ft;
    }
    double getInches()
    {
        return in;
    }
    double getLength()
    {
        return (ft * 12) + in;
    }
    Length Add(Length l);
    bool LessThan(Length l);
    bool GreaterThan(Length l);
    bool EqualTo(Length l);

    //modifier functions
    void setFeet(int f)
    {
        ft = f;
    }
    void setInches(double i)
    {
        in = i;
    }                 //cast used here to avoid warning message
    void setValue(int f, double i)
    {
        ft = f; in = i;
    }         //cast used here to avoid warning message
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

    if ((ft < l.ft) || ((ft == l.ft) && (in < l.in)))
        result = true;
    else
        result = false;

    return result;
}

bool Length::GreaterThan(Length l)
{
    return (ft > l.ft) || ((ft == l.ft) && (in > l.in));
}

bool Length::EqualTo(Length l)
{
    return (ft == l.ft) && (in == l.in);
}

void Length::AddTo(Length l)
{
    ft = ft + l.ft;
    in = in + l.in;

    if (in >= 12) {
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


class Rectangle
{
private:
    Length ln;          //length of rectangle
    Length wd;          //width of rectangle

public:
    //constructors
    Rectangle() : ln(0, 0), wd(0, 0)
    {}
    Rectangle(Length l, Length w) : ln(l), wd(w)
    {}

    //access functions
    Length getLength()                 //retrieves value of ln data member
    {
        return ln;
    }
    Length getWidth()                  //retrieves value of wd data member
    {
        return wd;
    }
    double getArea()                   //retrieves (computed) area of rectangle
    {
        return ln.getLength() * wd.getLength() / 144;
    }

    bool EqualAreaTo(Rectangle r)
    {
        return getArea() == r.getArea();
    }
    bool GreaterAreaThan(Rectangle r)
    {
        return getArea() > r.getArea();
    }
    bool LessAreaThan(Rectangle r)
    {
        return getArea() < r.getArea();
    }


    //modifier functions

    void setLength(Length l)           //sets value of ln data member to l
    {
        ln = l;
    }
    void setWidth(Length w)            //set value of wd data member to w
    {
        wd = w;
    }



    //input/output functions
    void Read();                       //to input Rectangle objects value
    void Write();                      //to output Rectangle objects value

};

void Rectangle::Read()
{
    cout << "Length? ";
    ln.Read();
    cout << "Width? ";
    wd.Read();
}

void Rectangle::Write()
{
    cout << "Length ";
    ln.Write();
    cout << ", Width ";
    wd.Write();
    cout << endl;
}


void ReadData(Rectangle rArray[], int &size);
void SortData(Rectangle rArray[], int size);
void WriteData(Rectangle rArray[], int size);

void main()
{
    //here you should define the data needed to complete this
    //function

    Rectangle rList[100];
    int rCount;

    ReadData(rList, rCount);
    SortData(rList, rCount);
    WriteData(rList, rCount);
}

void ReadData(Rectangle rArray[], int &size)
{
    cout << "Enter the number of rectangle values to be sorted: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Enter dimensions of rectangle " << i+1 << endl;
        rArray[i].Read();
    }
}

void SortData(Rectangle rArray[], int size)
{
    for (int i = size - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (rArray[j].GreaterAreaThan(rArray[j + 1]))
                swap(rArray[j], rArray[j + 1]);
}

void WriteData(Rectangle rArray[], int size)
{
    cout << "\nRectangles in Ascending Order by Area\n\n";

    for (int i = 0; i < size; i++)
        rArray[i].Write();

    cout << "\n\nEnd of List\n" << endl;
}