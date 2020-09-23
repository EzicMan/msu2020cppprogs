#include "CVector.hpp"
#include "AutoTest.hpp"
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "AutoTest not complete!";
		return 0;
	}
	cout << "AutoTest complete!";
	return 0;
}