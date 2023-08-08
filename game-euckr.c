#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>

int TRUTH_TABLE[3][3] = {
	{0,1,-1},
	{-1,0,1},
	{1,-1,0}
}; // ��쿡 ���� �ºθ� ��Ÿ�� ����ǥ (��ǻ���� ���ÿ� ���� �÷��̾��� ������ ���)
/*
	�÷��̾� ��: 1
	���º�: 0
	�÷��̾� ��: -1
*/

char *SELECT[3] = {"����", "����", "��"};

int isExit(char *choice);
int convert(char *choice);
void makeResult(int p_n);

int main(void) {
	
	char p[15]; // �÷��̾��� ����
	int p_n; // �÷��̾��� ������ ������
	
	while(1) {
		printf("----------------\n");
		printf("����, ����, ��!\n");
		printf("����� ����: ");
		scanf("%s", p); // �Է�
		
		if(isExit(p)) // '������' �Է½� ���α׷� ����
			break;
		
		p_n = convert(p); // �Է��� ������ ��ȯ
		
		if(p_n == 3) { // ����ó��
			printf("��Ģ��...\n");
			continue;
		}
			
		makeResult(p_n); // ��� ���� �� ���
	}
	
	return 0;
}

int isExit(char *choice) {
	return (strcmp(choice, "������")==0) ? 1 : 0; // �Է����� �����Ⱑ ������ 1�� ����
}

// ���ڿ��� ������ ��ȯ
int convert(char *choice) {
	int i;
	
	for(i=0; i<3; i++) {
		if(strcmp(choice, SELECT[i])==0) {
			break;
		}
	}
	
	return i;
}

// ��� ���� �� ���
void makeResult(int p_n) {
	int c_n; // ��ǻ���� ����
	srand(time(NULL));
	
	c_n = rand()%3;
	
	printf("��ǻ���� ����: %s\n", SELECT[c_n]); // ��ǻ���� ���� ���
	switch(TRUTH_TABLE[c_n][p_n]) {
		case -1:
			printf("����� �й�...\n");
			break;
		case 0:
			printf("���º�\n");
			break;
		case 1:
			printf("����� �¸�!!!\n");
			break;
		default:
			printf("����ġ ���� ������ �߻��߽��ϴ�.\n");
			break;
	}
}