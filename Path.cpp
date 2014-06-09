// PATH.cpp: implementation of the CPath class.
//
//////////////////////////////////////////////////////////////////////

#include "Path.hpp"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include <sys/stat.h>
#include <io.h>
#include <iostream>
#include <string>
using namespace std;

CPath::CPath()
{

}

CPath::~CPath()
{
	
}
bool CPath::IsDir(string szPath)
{
	Trim(szPath);
	struct stat buf;
	int cc;
    cc=stat(szPath.c_str(),&buf);
    if(!cc && (buf.st_mode & S_IFDIR)) 
		return true;
    return false;
}

bool CPath::IsFile(string szFileName)
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


bool CPath::IsExists(string szPath)
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

int CPath::Replace(int iPos, string &szSrc, string szSearch, string szReplace)
{	
    string::size_type pos = iPos;
    while((pos = szSrc.find(szSearch, pos)) != string::npos) 
	{
        szSrc.replace(pos, szSearch.size(), szReplace);
        pos++;
    }
    return 0;
}

int CPath::Trim(string &szSrc)
{
	Replace(0, szSrc, "\\\\", "\\");
	int iLen = szSrc.length();
	if(iLen > 1)
	{
		Replace(iLen -1, szSrc, "\\", "");
	}
	
	return 0;
}

void CPath::ScanFiles(string szPath, vector<string> &vFiles, int iDeep, int iCurDeep)
{
	Trim(szPath);
    _finddata_t FileInfo;
    string strfind = szPath + "\\*";
    long Handle = _findfirst(strfind.c_str(), &FileInfo);
    
    if (Handle == -1L)
    {
        return;
    }
    do{
        //判断是否有子目录
        if (FileInfo.attrib & _A_SUBDIR)    
        {
			if(0 == iDeep || iCurDeep < iDeep)
			{
				//去除当前文件和上一级文件
				if( (strcmp(FileInfo.name,".") != 0 ) &&(strcmp(FileInfo.name,"..") != 0))   
				{
					string newPath = szPath + "\\" + FileInfo.name;
					ScanFiles(newPath, vFiles, iDeep, iCurDeep + 1);
				}
			}
        }
        else  
        {

			vFiles.push_back( szPath + "\\" + FileInfo.name);
        }
    }while (_findnext(Handle, &FileInfo) == 0);
	
    _findclose(Handle);
	return;
}