#include"common.h"
#include"Sysutil.h"
#include"./sqlite/sqlite3.h"

//引入静态库
#pragma comment(lib, "./sqlite/sqlite3.lib")

void Test_DirecttinList()
{
	const string& path = "F:\\常用\\Study";
	vector<string> subfile, subdir;
	DirectionList(path, subfile, subdir);
	for (const auto& e : subfile)
		cout << e << endl;
	for (const auto& e : subdir)
		cout << e << endl;
}

void Test_Sqlite()
{
	//数据库打开
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
		printf("Open database failed.\n");
	else
		printf("Open database successed.\n");

	//操作数据库
	string sql = "select * from my_tb";
	char** result;
	int row;
	int col;
	char* zErrMsg = 0;

	sqlite3_get_table(db, sql.c_str(), &result, &row, &col, &zErrMsg);

	for (int i = 0; i <= row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("-5%s", *(result + (i * col) + j));
		}
		cout << endl;
	}

	sqlite3_free_table(result);
	//关闭数据库
	sqlite3_close(db);
}

int main(int argc, char *argv[])
{
	//Test_DirecttinList();
	Test_Sqlite();
	return 0;
}
