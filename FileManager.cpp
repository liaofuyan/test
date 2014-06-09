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
	vector<CFile * >::iterator iter;
	for(iter = m_vfFiles.begin(); iter != m_vfFiles.end(); iter ++)
	{
		if((CFile*)(*iter)->m_file.is_open())
		{
		
			char buf[1024];
		//	(CFile*)(*iter)->m_file.getline(buf, sizeof(buf));
// 			int len = ServerData.m_ReadFile.gcount();
// 			int cur = ServerData.m_ReadFile.tellg();
// 			if (cur != -1)
// 			{
// 				ServerData.m_iCurPos = cur;
// 			}
// 			else
// 			{
// 				ServerData.m_ReadFile.clear();
// 			}
// 			ServerData.m_ReadFile.seekg(ServerData.m_iCurPos);
			cout<<buf<<endl;	
		}
	}
	return 0;
}
