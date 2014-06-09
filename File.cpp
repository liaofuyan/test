// File.cpp: implementation of the CFile class.
//
//////////////////////////////////////////////////////////////////////

#include "File.hpp"
#include "Path.hpp"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFile::CFile()
{
	
}

CFile::CFile(string szFileName)
{
	CPath cPath;
	if(cPath.IsFile(szFileName))
	{
		m_file.open(szFileName.c_str());

	}
	m_name = szFileName;
}
CFile::CFile(const CFile & copy)
{
// 	m_name = copy.m_name;
// 	CPath cPath;
// 	if(cPath.IsFile(m_name))
// 	{
// 		m_file.open(m_name.c_str());	
// 	}
// 	
}
CFile::~CFile()
{
	if (m_file.is_open())
	{
		m_file.close();
	}
}
