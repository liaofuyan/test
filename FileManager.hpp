// FileManager.hpp: interface for the CFileManager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <string>
#include <fstream>
#include <vector>
#include "File.hpp"
using namespace std;

class CFileManager  
{
public:
	int GetLine(string & szLine);
	void Init(string szPath);
	CFileManager();
	virtual ~CFileManager();


private:
	vector<string> m_vsFiles;
	vector<CFile *> m_vfFiles;
};

#endif // !defined(FILEMANAGER_HPP)
