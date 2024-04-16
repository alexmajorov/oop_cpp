#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define EPS 1e-9
#define TRIANGLE_ERROR 1

struct Point {
    double x, y;
    Point() {}
    Point(double x_, double y_) : x(x_), y(y_) {}
};

class Triangle {
public:
    Point A, B, C;
    Triangle() {}
    Triangle(Point A_, Point B_, Point C_) { A = A_; B = B_; C = C_; } 
};

class Vector {
public:
    double x, y;
    Vector() {}
    Vector(double x_, double y_) : x(x_), y(y_) {}
    double operator*(const Vector& v) const 
    {
        return x * v.x + y * v.y;
    }
    double length() const 
    {
        return sqrt(x * x + y * y);
    }
};

double angle(const Triangle& t) 
{
    Vector BM = Vector((t.A.x + t.C.x) / 2 - t.B.x, (t.A.y + t.C.y) / 2 - t.B.y);
    Vector CD;
    if (fabs(t.A.y - t.B.y) > EPS)
        CD = Vector(1, (t.B.x - t.A.x) / (t.A.y - t.B.y));
    else
        CD = Vector(0, 1);
    double cos_angle = (BM * CD) / (BM.length() * CD.length());
    if (isnan(cos_angle))
    {
        string error_message = "Error"; 
        throw error_message;
    }
    return acos(fabs(cos_angle));
}

int main() 
{
    int rc = 0;
    double xa, ya;
    double xb, yb;
    double xc, yc;
    cout << "Insert xa: "; cin >> xa;
    cout << "Insert ya: "; cin >> ya;
    cout << "Insert xb: "; cin >> xb;
    cout << "Insert yb: "; cin >> yb;
    cout << "Insert xc: "; cin >> xc;
    cout << "Insert yc: "; cin >> yc;
    Point A(xa, ya);
    Point B(xb, yb);
    Point C(xc, yc);

    try
    {
        double a = sqrt((B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y));
        double b = sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
        double c = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
        if (!((a + b > c) && (c + b > a) && (a + c > b)))
        {
            string error_message = "Triangle does not exist.";
            throw error_message;
        }
    }
    catch(string error_message)
    {
        cout << error_message << "\n";
        rc = TRIANGLE_ERROR;
    }
    catch(...)
    {
        cout << "Unknown error" << "\n";
        rc = TRIANGLE_ERROR;
    }
    
    if (!rc)
    {
        Triangle t(A, B, C);
        try
        {
            double a = angle(t);
            cout << "Angle: " << setprecision(6) << fixed << a << "\n";  
        }
        catch(string error_message)
        {
            cout << error_message << "\n";
            rc = TRIANGLE_ERROR;
        }
        catch(...)
        {
            cout << "Unknown error" << "\n";
            rc = TRIANGLE_ERROR;
        }
    }

    return rc;
}