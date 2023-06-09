#include "colleague.hpp"
#include "list.hpp"
#include <algorithm>
#include <vector>
using std::sort;
using std::vector;

int main()
{
	vector<Programmer> pr1;
	pr1.push_back(Programmer("rex", 12.4f, senior));
	pr1.push_back(Programmer("next", 3.5f, middle));
	pr1.push_back(Programmer("fool", 6.4f, junior));

	vector<Programmer> pr2;
	pr2.push_back(Programmer("rex", 7.5f, middle));
	pr2.push_back(Programmer("next", 9.5f, junior));
	pr2.push_back(Programmer("fool", -6.4f, middle));

	vector<Programmer> pr = merge(pr1, pr2);
	vector<Programmer> find_programmer = findProgrammerInCompany_WithMiddleLev_and_WorkExperMoreThenOneYear(pr);
	cout << "Find programmer in collection : " << endl;
	for (size_t i = 0; i < find_programmer.size(); i++) {
		find_programmer[i].printMe();
	}
	cout << "Not sorted collection : " << endl;
	for (size_t i = 0; i < pr.size(); i++) {
		pr[i].printMe();
	}
	sortProgrammer("work_experience", pr);
	cout << "After sort" << endl;
	for (size_t i = 0; i < pr.size(); i++) {
		pr[i].printMe();
	}

	return 0;
}