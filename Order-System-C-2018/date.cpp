#include"date.h"
string Cdate::getcurrent(){
	stringstream on;
	string date;
	SYSTEMTIME sys;   
	GetLocalTime( &sys );   
	on<<sys.wYear<<"��"<<sys.wMonth<<"��"<<sys.wDay<<"��";  
	on>>date;
	return date; 
}