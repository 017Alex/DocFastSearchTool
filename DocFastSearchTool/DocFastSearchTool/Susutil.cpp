#include"Sysutil.h"

void DirectionList(const string& path, vector<string>& subfile, vector<string>& subdir)
{
	string _path = path;
	_path += "\\*.*";

	_finddata_t file;
	long handle = _findfirst(_path.c_str(), &file);//搜索path路径下第一个文件
	if (-1 == handle)
	{
		perror("_findfirst");//日志系统
		return;
	}

	do
	{
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
			continue;

		if (file.attrib & _A_SUBDIR)
			subdir.push_back(file.name);

		else
			subfile.push_back(file.name);
	} while (0 == _findnext(handle, &file));

	_findclose(handle);
}