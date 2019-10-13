#include"Examinee.h"
using namespace std;
void main() {
	vector<Examinee> l;
	l= ReadExamineeList("data.txt");
	WriteSumOfScore(l, "sum.txt");
}