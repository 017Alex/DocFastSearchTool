#include"common.h"
#include"Sysutil.h"
#include"./sqlite/sqlite3.h"

//���뾲̬��
#pragma comment(lib, "./sqlite/sqlite3.lib")

void Test_DirecttinList()
{
	const string& path = "F:\\����\\Study";
	vector<string> subfile, subdir;
	DirectionList(path, subfile, subdir);
	for (const auto& e : subfile)
		cout << e << endl;
	for (const auto& e : subdir)
		cout << e << endl;
}

int main(int argc, char *argv[])
{
	Test_DirecttinList();
	return 0;
}
