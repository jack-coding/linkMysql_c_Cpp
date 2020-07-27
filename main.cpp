#include<stdio.h>
#include<mysql.h>

int main(int argv,char * args[]) {
	MYSQL mysql;   //数据库句柄
	MYSQL_RES* res;//查询结果集
	MYSQL_ROW row; //记录结构体

	//初始化数据库
	mysql_init(&mysql);

	//设置字符编码
	mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"gbk");

	//连接数据库
	if (mysql_real_connect(&mysql,"127.0.0.1","root","654783","PaySystem",3306,NULL,0)==NULL) {
		printf("错误原因: %s\n",mysql_error(&mysql));
		printf("连接失败!");
		system("pause");
		exit(-1);
	}

	//查询数据
	int ret = mysql_query(&mysql,"select * from user");
	printf("ret: %d\n",ret);

	//获取结果集
	res = mysql_store_result(&mysql);

	//给ROW赋值,判断row是否为空,不为空就打印数据
	while (row=mysql_fetch_row(res)) {
		printf("%s\t",row[0]);
		printf("%s\t", row[1]);
		printf("%s\t", row[2]);
		printf("%s\t", row[3]);
		printf("%s\n", row[4]);
	}

	//释放结果集
	mysql_free_result(res);

	//关闭数据库
	mysql_close(&mysql);

	system("pause");
	return EXIT_SUCCESS;
}

