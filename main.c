#include<stdlib.h>
#include<stdio.h>
const char Type_figure[5]={'B','N','R','Q','K'};

int ver_begin=0, gor_begin=0, ver_end=0, gor_end=0, move=1;
char letter_fig=0, typ_move=0;

int Check_Getc(char ch)
{
	if(ch!=' ' && ch!='.' && ch!='X' && ch!='+' && ch!='!' && ch!='?' && ch!='\n' && ch!='\t') return 1;
	return 0;
}

char Search_Read(FILE *f1,char ch)
{
	while(Check_Getc(ch)!=1) //Поиск нормального символа
	{
		ch=getc(f1);
	}
	return ch;
}

int Check_Massive(char ch)
{
	int i;
	for(i=0;i<5;i++)
	{
		if(ch==Type_figure[i])
		{
			return 1;
		}
	}
	return 0;
}

int Check_Gor(char ch)
{
	if(ch>=97 && ch<=104) return 1;
	return 0;
}

int Check_Ver(char ch)
{
	if(ch>=49 && ch<=56) return 1;
	return 0;
}

void Error_Message_Move(int move_input)
{
	printf("\nНомер хода указан не верно");
	printf("\nХод №%i за ",move/2+move % 2);
	if(move % 2)
	{
		printf("белых, ");
	}
	else
	{
		printf("чёрных, ");
	}
	printf("а написано, что он №%i",move_input);
	exit(1);
}

void Move_input(FILE *f1,char ch)
{
	int move_input=0;
	while(Check_Getc(ch))
	{
		move_input=move_input*10+ch-48;
		ch=getc(f1);
	}
	if(move_input!=(move / 2)+(move % 2))
	{
		Error_Message_Move(move_input);
	}
}

void Error_Message_Read()
{
	printf("\nХод №%i за ",move/2+move % 2);
	if(move % 2)
	{
		printf("белых: ");
	}
	else
	{
		printf("чёрных: ");
	}
	printf("\nОшибка ввода данных. Исправьте её и попробуйте снова");
	exit(1);
}

void Move_Read(FILE *f1, char ch)
{
	if(Check_Gor(ch))
	{
		letter_fig='P';
	}
	else
	{
		letter_fig=ch;
		ch=getc(f1);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Gor(ch))
	{
		gor_begin=ch-96;
		ch=getc(f1);
	}
	else
	{
		Error_Message_Read();
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Ver(ch))
	{
		ver_begin=ch-48;
		ch=getc(f1);
	}
	else
	{
		Error_Message_Read();
	}
	
	ch=Search_Read(f1,ch);
	if(ch=='-' || ch=='x' || ch==':')
	{
		typ_move=ch;
		ch=getc(f1);
	}
	else
	{
		Error_Message_Read();
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Gor(ch))
	{
		gor_end=ch-96;
		ch=getc(f1);
	}
	else
	{
		Error_Message_Read();
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Ver(ch))
	{
		ver_end=ch-48;
		ch=getc(f1);
	}
	else
	{
		Error_Message_Read();
	}

}

int main()
{
	FILE *f1;
	system("chcp 1251>nul");
	// Место для записи переменных
	
	char ch;
	f1=fopen("res//Chess_Game.txt","r");
	if(f1== NULL)
	{
		printf("\nДумай как нормально открыть файл");
		return 1;
	}
	printf("\nДа ладно сработало");
	system("CLS");
	while((ch=getc(f1))!=EOF)
	{
		ch=Search_Read(f1,ch);	
		
		if(ch>=48 && ch<=57)  //48 и 57 -- символьные коды цифр '0' и '9'
		{
			Move_input(f1,ch);
		}
		
		if(Check_Massive(ch) || Check_Gor(ch))
		{
			Move_Read(f1,ch);
			system("CLS");
			printf("\nХод №%i за ",move/2+move % 2);
			if(move % 2)
			{
				printf("белых: ");
			}
			else
			{
				printf("чёрных: ");
			}
			printf("%c%c%c%c%c%c\n",letter_fig, gor_begin+96, ver_begin+48, typ_move, gor_end+96, ver_end+48);
			system("Pause");
			move++;
		}
	}
	fclose(f1);	
	return 0;
}
