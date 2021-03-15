#include"date.h"
string Cdate::getcurrent(){
	stringstream on;
	string date;
	SYSTEMTIME sys;   
	GetLocalTime( &sys );   
	on<<sys.wYear<<"Äê"<<sys.wMonth<<"ÔÂ"<<sys.wDay<<"ÈÕ";  
	on>>date;
	return date; 
}