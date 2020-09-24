#include "CVector.hpp"
#include "AutoTest.hpp"
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	CVector b = { 1.1,2.2,3.3 };
	cout << b[0] << " " << b[1] << " " << b[2] << endl;
	double a1[3] = {1,2,3};
	CVector a(3, a1);
	cout << a.getSize() << ":" << a[0] << " " << a[1] << " " << a[2] << endl;
	a[0] = 10;
	cout << a.getSize() << ":" << a[0] << " " << a[1] << " " << a[2] << endl;
	a[5] = 100;
	cout << a.getSize() << ":" <<  a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << endl;
	return 0;
}