#include "list.hpp"



int main()
{
	List<char> l1;
	l1.addToEnd('f');
	l1.addToEnd('a');
	l1.addToEnd('k');
	l1.addToEnd('m');
	l1.addToEnd('n');
	l1.addToEnd('q');
	cout << "List: --> ";
	l1.print();

	size_t index = l1.getIndex('a');
	cout << "Index 'a' -> "<< index << endl;
	l1.sort();
	cout << "Sorted list:  ";
	l1.print();
	for (int i = 0; i < 6; ++i) {
		l1.delElementPos(0);
	}



	return 0;
}