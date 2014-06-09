// MyFile.cpp: implementation of the CMyFile class.
//
//////////////////////////////////////////////////////////////////////

#include "MyFile.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include <sys/stat.h>

#include <iostream>
using namespace std;

CMyFile::CMyFile()
{

}

CMyFile::~CMyFile()
{

}
bool CMyFile::IsDir(string szPath)
{
	Trim(szPath);
	struct stat buf;
	int cc;
    cc=stat(szPath.c_str(),&buf);
    if(!cc && (buf.st_mode & S_IFDIR)) 
		return true;
    return false;
}

bool CMyFile::IsFile(string szFileName)
{
	Trim(szFileName);
	struct stat buf;
	int cc;
    cc=stat(szFileName.c_str(),&buf);
	if(!cc && (buf.st_mode & S_IFDIR)) 
		return false;
	if(cc == 0)
	{
		return true;
	}
    return false;
}


bool CMyFile::IsExists(string szPath)
{
	Trim(szPath);
	struct stat buf;
	int cc;
    cc=stat(szPath.c_str(),&buf);

	if(cc == 0)
	{
		return true;
	}
    return false;
}

int CMyFile::Replace(int iPos, string &szSrc, string szSearch, string szReplace)
{	
    string::size_type pos = iPos;
    while((pos = szSrc.find(szSearch, pos)) != string::npos) {
        szSrc.replace(pos, szSearch.size(), szReplace);
        pos++;
    }
    return 0;
}

int CMyFile::Trim(string &szSrc)
{
	Replace(0, szSrc, "\\\\", "\\");
	int iLen = szSrc.length();
	if(iLen > 1)
	{
		Replace(iLen -1, szSrc, "\\", "");
	}

	return 0;
}