//#include <iostream>
//
//using namespace std;
//
//class Progression {
//public:
//	Progression(long f = 0) : first(f), cur(f) {}
//	virtual ~Progression() {};
//	void printProgression(int n);
//protected:
//	virtual long firstValue();
//	virtual long nextValue();
//	long first;
//	long cur;
//};
//
//
//void Progression::printProgression(int n) {
//	cout << firstValue();
//	for (int i = 2; i <= n; i++) {
//		cout << ' ' << nextValue();
//	}
//	cout << endl;
//}
//
//long Progression::firstValue() {
//	cur = first;
//	return cur;
//}
//
//long Progression::nextValue() {
//	return ++cur;
//}
//
//class ArithProgression : public Progression {
//public:
//	ArithProgression(long i = 1);
//protected:
//	virtual long nextValue();
//protected:
//	long inc;
//};
//
//ArithProgression::ArithProgression(long i) : Progression(), inc(i) {}
//long ArithProgression::nextValue() {
//	cur += inc;
//	return cur;
//}
//
//int main() {
//
//
//
//}