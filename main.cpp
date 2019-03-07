#include "filelib.h"

int main()
{
	filelib testobj;
	int rec;
	string path;
	while(1)
	{
		cout<<"Press 1 to Insert"<<endl;
		cout<<"Press 2 to Sort By Size"<<endl;
		cout<<"Press 3 to Sort By Name"<<endl;	
		cout<<"Press 4 to Sort By Access Date"<<endl;
		cout<<"Press 5 to Display File and Its Attributes"<<endl;
		cout<<"Press 6 to Exit"<<endl;
		cin>>rec;
		switch(rec)
		{
			case 1 : cout<<"Enter Path"<<endl;
				 cin>>path;
				 testobj.insert(path);
				 break;
			case 2 : testobj.bysize();
				 break;
			case 3 : testobj.byname();
				 break;
			case 4 : testobj.byaccessdate();
				 break;
			case 5 : testobj.print();
				 break;
			case 6 : cout<<"Exiting"<<endl;
				 exit(0);
		       default : cout<<"Invalid Option"<<endl;
		}
	}
	return 0;
}
