#include "filelib.h"

map<long,string> mapme;

//To Extract Mime Type of File,Function Defined Later
void getmimetype(mode_t mod);

//Asceding order AccessDate Sorting
bool byaccessdate_asc(struct stat first,struct stat second)
{
	return (first.st_atime < second.st_atime);
}

//Descending Order AccessDate Sorting
bool byaccessdate_dsc(struct stat first,struct stat second)
{
	return (first.st_atime > second.st_atime);
}

//Ascending Order Name Sorting
bool byname_asc(struct stat first,struct stat second)
{
	return (strcmp(mapme[first.st_ino].c_str(),mapme[second.st_ino].c_str())<0);
}

//Descending Order Name Sorting
bool byname_dsc(struct stat first,struct stat second)
{
	return (strcmp(mapme[first.st_ino].c_str(),mapme[second.st_ino].c_str())>=0);
}

//Ascending Order Size Sorting
bool bysize_asc(struct stat first,struct stat second)
{
	return (first.st_size <= second.st_size);
}

//Descending Order Size Sorting
bool bysize_dsc(struct stat first,struct stat second)
{
	return (first.st_size > second.st_size);
}

//Size Sorting
void filelib::bysize()
{
	int rec;
	cout<<"Press 1 for Ascending Sort"<<endl;
	cout<<"Press 2 for Descending Sort"<<endl;
	cin>>rec;
	if(rec==1)
	{
		filelist.sort(bysize_asc);
	}
	else if(rec==2)
	{
		filelist.sort(bysize_dsc);
	}
	else
	{
		cout<<"Invalid Option"<<endl;
	}
	cout<<"Sorting Successful"<<endl;
}

//Name Sorting
void filelib::byname()
{
	int rec;
	mapme = mapname;
	cout<<"Press 1 for Ascending order"<<endl;
	cout<<"Press 2 for Descending order"<<endl;
	cin>>rec;
	if(rec==1)
	{
		filelist.sort(byname_asc);
	}
	else if(rec==2)
	{
		filelist.sort(byname_dsc);
	}
	else
	{
		cout<<"Invalid Option"<<endl;
	}
	cout<<"Sorting Successful"<<endl;
}

//Insertion to linked list
void filelib::insert(string path)
{
	if(stat(path.c_str(),&buff)==0)
	{
		name = path.substr(path.rfind('/')+1,path.length()-1);
		mapname[buff.st_ino] = name;
		filelist.push_back(buff);
		cout<<"Insertion Successful"<<endl;
	}
	else
	{
		cout<<"File Not Present"<<endl;
	}
}

//Printing All Contents of Linked List
void filelib::print()
{
	for(it=filelist.begin();it!=filelist.end();++it)
	{
		cout<<"************************"<<endl;
		print_all_attributes(*it);
		cout<<"************************"<<endl;
	}
}

//Access Date Sorting
void filelib::byaccessdate()
{
	int rec;
	cout<<"Press 1 for ascending order"<<endl;
	cout<<"Press 2 for descending order"<<endl;
	cin>>rec;
	if(rec==1)
	{
		filelist.sort(byaccessdate_asc);
	}
	else if(rec==2)
	{
		filelist.sort(byaccessdate_dsc);
	}
	else
	{
		cout<<"Invalid option"<<endl;
	}
	cout<<"Sorting Successful"<<endl;
}

//Printing All Attributes of a File
void filelib::print_all_attributes(struct stat buffme)
{
	mapme = mapname;
	cout<<"Name of File: "<<mapme[buffme.st_ino]<<endl;
	cout<<"Following Line Describes the File Type : "<<endl;
	getmimetype(buffme.st_mode);
	cout<<"Serial Number of File: "<<buffme.st_ino<<endl;
	cout<<"Size of File: "<<buffme.st_size<<endl;
	cout<<"Mode of File: "<<buffme.st_mode<<endl;
	cout<<"Device Containing the file: "<<buffme.st_dev<<endl;
	cout<<"Last Access Time: "<<buffme.st_atime<<endl;
	cout<<"Last Modification of Contents Time: "<<buffme.st_mtime<<endl;
	cout<<"Last modification to Attributes Time: "<<buffme.st_ctime<<endl;
	cout<<"Number of blocks Consumed: "<<buffme.st_blocks<<endl;
	cout<<"User Id of File's Owner: "<<buffme.st_uid<<endl;
	cout<<"Group id of file: "<<buffme.st_gid<<endl;
}

//To Extract Mime Type of File
void getmimetype(mode_t mod)
{
	if(S_ISDIR(mod)!=0)
	{
		cout<<"This File is a Directory"<<endl;
	}
	if(S_ISCHR(mod)!=0)
	{
		cout<<"This is a Character Special File"<<endl;
	}
	if(S_ISBLK(mod)!=0)
	{
		cout<<"This is a Block Special file"<<endl;
	}
	if(S_ISREG(mod)!=0)
	{
		cout<<"This is a regular file"<<endl;
	}
	if(S_ISFIFO(mod)!=0)
	{
		cout<<"This is a FIFO Special file"<<endl;
	}
	if(S_ISLNK(mod)!=0)
	{
		cout<<"This is a symbolic file"<<endl;
	}
	if(S_ISSOCK(mod)!=0)
	{
		cout<<"This file is a socket"<<endl;
	}
}
