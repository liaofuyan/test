// FileManager.cpp: implementation of the CFileManager class.
//
//////////////////////////////////////////////////////////////////////

#include "FileManager.hpp"
#include "PATH.hpp"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileManager::CFileManager()
{

}

CFileManager::~CFileManager()
{
	vector<CFile * >::iterator fiter;
	for(fiter = m_vfFiles.begin(); fiter != m_vfFiles.end(); fiter ++)
	{
		delete (CFile *)(* fiter);
	}
}

void CFileManager::Init(string szPath)
{	
	
	CPath cPath;
	cPath.ScanFiles(szPath, m_vsFiles, 1);

	vector<string>::iterator iter;
	for(iter = m_vsFiles.begin(); iter != m_vsFiles.end(); iter ++)
	{
		//cout << * iter<< endl;
		CFile * ptF = new CFile(*iter);	
		m_vfFiles.push_back(ptF);
	}
	
	
// 	vector<CFile * >::iterator fiter;
// 	for(fiter = m_vfFiles.begin(); fiter != m_vfFiles.end(); fiter ++)
// 	{
// 		cout <<"OUTER->"<<( (CFile *)(* fiter))->m_name<< endl;
// 	}
}

int CFileManager::GetLine(string &szLine)
{
	return 0;
}
