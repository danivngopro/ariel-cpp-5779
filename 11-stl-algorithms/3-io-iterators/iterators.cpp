/**
 * Demonstrates IO iterators with STL containers.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

template<typename T> ostream& operator<<(ostream& out, const set<T>& container) {
	copy(container.begin(), container.end(), 
		ostream_iterator<T>(out,"; "));
	return out;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& container) {
	copy(container.begin(), container.end(), 
		ostream_iterator<T>(out,"; "));
	return out;
}

int main() {
	// example of ostream_iterator:
	ostream_iterator<double> o(cout,"---");
	for (double i=0; i<10; ++i)
		(*o) = i;
	cout << endl;

	// example of istream_iterator:
    istringstream str("0.12 0.2 0.3 0.4");
	istream_iterator<float> ibegin(str);
	istream_iterator<float> iend;
	cout << "istream_iterator: ";
	for (; ibegin!=iend; ++ibegin)
		cout << (*ibegin) << "  ";
	cout << endl;

	// example of copy:
	vector<int> v1 {1,7,3,5,1,3};
	set<int> v1s;
	copy(v1.begin(), v1.end(), v1s.begin());  // get rid of duplicates, and sort by value

	// example of copy + ostream_iterator
	set<int> s1 = {1,7,3,5};
	copy(s1.begin(), s1.end(), ostream_iterator<int>(cout,"; "));
	cout << endl;
	cout << "s1: " << s1 << endl;

	vector<int> v11(4);
	cout << "v11: " << v11 << endl;

	auto it_v11 = v11.begin() + 1;
	it_v11+=1;
	copy(s1.begin(), s1.end(), it_v11);
	cout << "v11: " << v11 << endl;

	auto it_s1 = s1.begin();
	++++it_s1;
	copy(it_s1, s1.end(), v11.begin());
	cout << "v11: " << v11 << endl;

	auto it=s1.begin();

	//copy(s1.begin(), ++++++it, v1.begin());

	// vector<int> v1(4);
	// copy(istream_iterator<int>(cin), istream_iterator<int>{} , v1.begin());

	// copy(v1.begin(), v1.end(), ostream_iterator<int>(cout,","));
	// cout << endl;

	// int a[4] = {1,2,3,4};
	// int b[4];
	// copy(begin(a), end(a), v11.begin());
	// cout << "v11: " << v11 << endl;
    //partial_sum(a, a+4,  ostream_iterator<int>(cout, ","));
	// for (int i: b) 
	// 	cout << i << endl;

    //partial_sum(istream_iterator<double>(cin),
    //       	istream_iterator<double>(),
    //            ostream_iterator<double>(cout, " "));
}


/*
template<typename Iterator> Iterator& operator+=(Iterator& it, int howmuch) {
	for (int i=0; i<howmuch; ++i)
		++it;
	return it;
}
*/
