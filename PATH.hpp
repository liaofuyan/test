// PATH.hpp: interface for the CPath class.
//
//////////////////////////////////////////////////////////////////////

#ifndef PATH_HPP
#define PATH_HPP
#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif

#include <iostream>
#include <vector>
using namespace std;
class CPath
{
public:
	CPath();
	virtual ~CPath();
	
public:
	bool IsDir(string szPath);
	bool IsFile(string szFileName);
	bool IsExists(string szPath);
	void ScanFiles(string szPath, vector<string> &vFiles, int iDeep = 0, int iCurDeep = 1);
private:
	int Replace(int iPos, string &szSrc, string szSearch, string szReplace);
	int Trim(string &szSrc);

private:
	string m_szPath;
// 	string m_szCurPath;
// 	vector<string> m_vFiles;

};
#endif // !defined(PATH_HPP)
