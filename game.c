#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>

int TRUTH_TABLE[3][3] = {
	{0,1,-1},
	{-1,0,1},
	{1,-1,0}
}; // 경우에 따른 승부를 나타낸 진리표 (컴퓨터의 선택에 대한 플래이어의 선택의 결과)
/*
	플래이어 승: 1
	무승부: 0
	플래이어 패: -1
*/

char *SELECT[3] = {"가위", "바위", "보"};

int isExit(char *choice);
int convert(char *choice);
void makeResult(int p_n);

int main(void) {
	
	char p[15]; // 플래이어의 선택
	int p_n; // 플래이어의 선택의 정수꼴
	
	while(1) {
		printf("----------------\n");
		printf("가위, 바위, 보!\n");
		printf("당신의 선택: ");
		scanf("%s", p); // 입력
		
		if(isExit(p)) // '나가기' 입력시 프로그램 종료
			break;
		
		p_n = convert(p); // 입력을 정수로 변환
		
		if(p_n == 3) { // 예외처리
			printf("반칙패...\n");
			continue;
		}
			
		makeResult(p_n); // 결과 생성 및 출력
	}
	
	return 0;
}

int isExit(char *choice) {
	return (strcmp(choice, "나가기")==0) ? 1 : 0; // 입력으로 나가기가 들어오면 1을 리턴
}

// 문자열을 정수로 변환
int convert(char *choice) {
	int i;
	
	for(i=0; i<3; i++) {
		if(strcmp(choice, SELECT[i])==0) {
			break;
		}
	}
	
	return i;
}

// 결과 생성 및 출력
void makeResult(int p_n) {
	int c_n; // 컴퓨터의 선택
	srand(time(NULL));
	
	c_n = rand()%3;
	
	printf("컴퓨터의 선택: %s\n", SELECT[c_n]); // 컴퓨터의 선택 출력
	switch(TRUTH_TABLE[c_n][p_n]) {
		case -1:
			printf("당신의 패배...\n");
			break;
		case 0:
			printf("무승부\n");
			break;
		case 1:
			printf("당신의 승리!!!\n");
			break;
		default:
			printf("예상치 못한 오류가 발생했습니다.\n");
			break;
	}
}