// File.hpp: interface for the CFile class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FILE_HPP
#define FILE_HPP
#include <string>
#include <fstream>
using namespace std;
class CFile  
{
public:
	CFile();
	CFile(string szFineName);
	CFile(const CFile & copy);

	virtual ~CFile();

public:
	fstream m_file;	
	string m_name;
};

#endif // !defined(FILE_HPP)
