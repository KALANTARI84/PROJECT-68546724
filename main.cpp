#include <iostream>
#include <cmath>
using namespace std;

// کلاس پایه
class Shape {
protected:
    string color;
    string pattern;
public:
    Shape(string c, string p) : color(c), pattern(p) {}

    virtual void Display() {
        cout << "Shape - Color: " << color << ", Pattern: " << pattern << endl;
    }

    virtual float Area() {
        return 0;
    }

    virtual float Perimeter() {
        return 0;
    }
};

// دایره
class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r, string c, string p) : Shape(c, p), radius(r) {}

    void Display() override {
        cout << "Circle - Radius: " << radius << ", Color: " << color << ", Pattern: " << pattern << endl;
    }

    float Area() override {
        return 3.14 * radius * radius;
    }

    float Perimeter() override {
        return 2 * 3.14 * radius;
    }
};

// مستطیل
class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w, string c, string p) : Shape(c, p), length(l), width(w) {}

    void Display() override {
        cout << "Rectangle - Length: " << length << ", Width: " << width
             << ", Color: " << color << ", Pattern: " << pattern << endl;
    }

    float Area() override {
        return length * width;
    }

    float Perimeter() override {
        return 2 * (length + width);
    }
};

// مثلث
class Triangle : public Shape {
private:
    float a, b, c;
public:
    Triangle(float side1, float side2, float side3, string col, string pat)
        : Shape(col, pat), a(side1), b(side2), c(side3) {}

    void Display() override {
        cout << "Triangle - Sides: " << a << ", " << b << ", " << c
             << ", Color: " << color << ", Pattern: " << pattern << endl;
    }

    float Area() override {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c)); // فرمول هرون
    }

    float Perimeter() override {
        return a + b + c;
    }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(2.5, "Red", "Dots");
    shapes[1] = new Rectangle(4.0, 6.0, "Green", "Stripes");
    shapes[2] = new Triangle(3.0, 4.0, 5.0, "Blue", "Solid");

    for (int i = 0; i < 3; i++) {
        shapes[i]->Display();
        cout << "Area: " << shapes[i]->Area() << ", Perimeter: " << shapes[i]->Perimeter() << endl << endl;
    }

    // آزادسازی حافظه
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
