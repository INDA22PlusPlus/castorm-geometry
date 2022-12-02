#include <iostream>
#include <math.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    double res = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << a << ", " << b << ", " << c << endl;

        double A = acos((b * b + c * c - a * a)/(2 * b * c));
        double B = acos((a * a + c * c - b * b)/(2 * a * c));

        double diff = abs(A - B) / 2.0;

        cout << A << ", " << B << " = " << diff << " : " << c * cos(diff) << endl;
        res += c * cos(diff);
    }

    cout << res << endl;

    return 0;
}