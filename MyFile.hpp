// MyFile.hpp: interface for the CMyFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MYFILE_HPP
#define MYFILE_HPP

#include <iostream>
using namespace std;
class CMyFile  
{
public:
	CMyFile();
	virtual ~CMyFile();
	
public:
	bool IsDir(string szPath);
	bool IsFile(string szFileName);
	bool IsExists(string szPath);

private:
	int Replace(int iPos, string &szSrc, string szSearch, string szReplace);
	int Trim(string &szSrc);
};

#endif // !defined(MYFILE_HPP)
