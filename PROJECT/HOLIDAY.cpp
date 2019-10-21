#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include<conio.h>
#define TOTAL_HOLIDAYS 33

typedef struct Holiday{
	unsigned short int month;
	unsigned short int day;
	char detail[100];
}Holiday;

int main(){
clrscr();
	FILE *holiday_file;
	holiday_file = fopen("HOLIDAYS.DAT", "wb");
	Holiday holiday;
	for(int i=0; i < TOTAL_HOLIDAYS; i++){
		printf("Enter month: ");
		scanf("%d", &holiday.month);
		printf("Enter day: ");
		scanf("%d", &holiday.day);
		printf("Enter Detail: ");
		fflush(stdin);
		gets(holiday.detail);
		fwrite(&holiday, sizeof(Holiday), 1, holiday_file);
	}
	fclose(holiday_file);
	return 0;
	getch();
}