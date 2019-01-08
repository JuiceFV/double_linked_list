#include"LinkedList.hpp"
#include <iostream>
using namespace std;
int main()
{
	double_linked_list<int> list;
	list.init(5);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(3);
	list.push_back(0);
	list.print_list(cout);
	cout << endl << list.size()<<endl;

	system("pause");
	return 0;
}