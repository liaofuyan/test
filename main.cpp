#include <sys/stat.h>

#include "Path.hpp"
#include "FileManager.hpp"
#include <iostream>
#include <string>
#include <io.h>
#include <vector>
using namespace std;

int repalce_test(string &szSrc, string szSearch, string szReplace);
void Dir(string folderPath, bool bFileOnly = false);
void test_cpath();
void test_cfilemanager();
int main()
{
	//test_cpath();
	test_cfilemanager();
	return 0;
}

void test_cpath()
{
	// 	cout << isdir("e:\\src\\www\\wx\\")<< endl;
	// 	cout << isdir("e:\\src\\www\\wx")<< endl;
	// 	cout << isdir("e:\\src\\www\\wx\\wx_sample.php")<< endl;
	string szPath = "e:\\src\\www\\wx\\";
	CPath myPath;
	cout << myPath.IsDir("e:\\src\\www\\wx\\")<< endl;
	cout << myPath.IsDir("e:\\src\\www\\wx")<< endl;
	cout << myPath.IsDir("e:\\src\\www\\wx\\wx_sample.php")<< endl;
	
	cout << myPath.IsFile("e:\\src\\www\\wx\\")<< endl;
	cout << myPath.IsFile("e:\\src\\www\\wx")<< endl;
	cout << myPath.IsFile("e:\\src\\www\\wx\\wx_sample.php")<< endl;
	
	cout << myPath.IsExists("e:\\src\\www\\wx\\")<< endl;
	cout << myPath.IsExists("e:\\src\\www\\wx")<< endl;
	cout << myPath.IsExists("e:\\src\\www\\wx\\wx_sample.php")<< endl;
	
	// 	while (1)
	// 	{
	// 		cout<<"输入q退出服务："<<endl;
	// 		string  szPath;
	// 		std::cin >> szPath;	
	// 		cout<< szPath.length()<<endl;
	// 		cout << myFile.IsExists(szPath)<< endl;
	// 	}
	
	
	string szSrc = "e:\\src\\www\\wx\\";
	string searchString("\\");
	string replaceString("");
	cout << szSrc << endl;
	repalce_test(szSrc, searchString, replaceString);
	cout << szSrc << endl;
	
	//	Dir("e:\\src\\znjj\\httpclient", true);
	
	vector<string> vFiles;
	myPath.ScanFiles("e:\\src\\znjj\\httpclient\\", vFiles, 3);
	
	vector<string>::iterator iter;
	for(iter = vFiles.begin(); iter != vFiles.end(); iter ++)
	{
		cout<< "outer------" << *iter << endl;
	}
}
int repalce_test(string &szSrc, string szSearch, string szReplace)
{	
    string::size_type pos = 0;
    while((pos = szSrc.find(szSearch, pos)) != string::npos) {
        szSrc.replace(pos, szSearch.size(), szReplace);
        pos++;
    }
    return 0;
}

void Dir(string szPath, bool bFileOnly)
{
    _finddata_t FileInfo;
    string strfind = szPath + "\\*";
    long Handle = _findfirst(strfind.c_str(), &FileInfo);
    
    if (Handle == -1L)
    {
        cerr << "can not match the folder path" << endl;
        exit(-1);
    }
    do{
        //判断是否有子目录
        if (FileInfo.attrib & _A_SUBDIR)    
        {
			if(!bFileOnly)
			{
				//这个语句很重要
				if( (strcmp(FileInfo.name,".") != 0 ) &&(strcmp(FileInfo.name,"..") != 0))   
				{
					string newPath = szPath + "\\" + FileInfo.name;
					Dir(newPath, bFileOnly);
				}
			}
        }
        else  
        {
            cout << szPath << "\\" << FileInfo.name  << endl;
        }
    }while (_findnext(Handle, &FileInfo) == 0);
	
    _findclose(Handle);
   // fout.close();
}



void test_cfilemanager()
{
	CFileManager cFilemanager;
	string path = "e:\\src\\myapp\\test\\";
	cFilemanager.Init(path);
}