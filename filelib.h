#include <iterator>
#include <iostream>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <map>
using namespace std;
class filelib
{
	public:
	struct stat buff;
	map<long,string> mapname;
	list<struct stat> filelist;					   //Linked list containing all files
	string name;
	list<struct stat>::iterator it;

	void insert(string path);						//For insertion to linked list
	void print();									//Printing of linked list
	void bysize();									//Sorting By Size
	void byname();									//Sorting By Name
	void byaccessdate();							//Sorting By Access Date
	void print_all_attributes(struct stat buffme);	//Printing All Attributes of a File
};
