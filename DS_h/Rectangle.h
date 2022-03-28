#include <iostream>

using namespace std;

/*
 * Rectangle r(1, 3, 6, 6), t(1, 32, 6, 6);
 * r == t ? cout << "Bingo!" << endl : cout << "Not the same Rectangle" << endl;
 * //overloading <<
 * cout << r;
 * return 0;
 */

class Rectangle {
public:

    Rectangle(int x, int y, int h, int w);

    int GetWidth();

    int GetHeight();

    bool operator==(const Rectangle &);

    friend ostream &operator<<(ostream &, Rectangle &);

private:
    int xLow, yLow, height, width;
};

int Rectangle::GetHeight() {
    return height;
}

int Rectangle::GetWidth() {
    return width;
}

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0) : xLow(x), yLow(y), height(h), width(w) {};

//重載運算子(==比較)
bool Rectangle::operator==(const Rectangle &s) {
    if (this == &s) {
        return true;
    } else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width)) {
        return true;
    } else {
        return false;
    }

}

//重載運算子(cout) 返回ostream
ostream &operator<<(ostream &os, Rectangle &r) {
    os << "Postion is: " << "[" << r.xLow;
    os << "," << r.yLow << "]" << endl;
    os << "Height is: " << r.height << endl;
    os << "Width is: " << r.width << endl;

    return os;
}