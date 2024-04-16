#include <iostream>
#include <cmath>

using namespace std;

class func
{
private:
    int a, b, h;
public:
    int prime_factors(int);
    void tabulate(void);
    func(int = 1, int = 10, int = 1);
};

func::func(int a_, int b_, int h_)
{
    a = a_;
    b = b_;
    h = h_;
}

int func::prime_factors(int number)
{
    int ans = 0;
    int border = (int)sqrt(number) + 1;
    for (int i = 2; i <= border; ++i)
    {
        if (number % i == 0) ans++;
        while (number % i == 0) number /= i;
    }
    if (number != 1) ans++;
    return ans;
}

void func::tabulate(void)
{
    for (int i = a; i <= b; i += h)
        cout << "f(" << i << ")" << " = " << prime_factors(i) << "\n";
    return;
}

int main()
{
    int a, b, h;
    cout << "Insert a: "; cin >> a;
    cout << "Insert b: "; cin >> b;
    cout << "Insert h: "; cin >> h;
    func f(a, b, h);
    f.tabulate();
    return 0;
}