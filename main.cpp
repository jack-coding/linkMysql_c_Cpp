#include<stdio.h>
#include<mysql.h>

int main(int argv,char * args[]) {
	MYSQL mysql;   //���ݿ���
	MYSQL_RES* res;//��ѯ�����
	MYSQL_ROW row; //��¼�ṹ��

	//��ʼ�����ݿ�
	mysql_init(&mysql);

	//�����ַ�����
	mysql_options(&mysql,MYSQL_SET_CHARSET_NAME,"gbk");

	//�������ݿ�
	if (mysql_real_connect(&mysql,"127.0.0.1","root","654783","PaySystem",3306,NULL,0)==NULL) {
		printf("����ԭ��: %s\n",mysql_error(&mysql));
		printf("����ʧ��!");
		system("pause");
		exit(-1);
	}

	//��ѯ����
	int ret = mysql_query(&mysql,"select * from user");
	printf("ret: %d\n",ret);

	//��ȡ�����
	res = mysql_store_result(&mysql);

	//��ROW��ֵ,�ж�row�Ƿ�Ϊ��,��Ϊ�վʹ�ӡ����
	while (row=mysql_fetch_row(res)) {
		printf("%s\t",row[0]);
		printf("%s\t", row[1]);
		printf("%s\t", row[2]);
		printf("%s\t", row[3]);
		printf("%s\n", row[4]);
	}

	//�ͷŽ����
	mysql_free_result(res);

	//�ر����ݿ�
	mysql_close(&mysql);

	system("pause");
	return EXIT_SUCCESS;
}

