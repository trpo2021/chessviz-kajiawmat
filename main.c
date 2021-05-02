#include<stdlib.h>
#include<stdio.h>
const char Type_figure[6]={'P','R','N','B','Q','K'};
char C[9][9];

int ver_begin=0, gor_begin=0, ver_end=0, gor_end=0, move=1;
char letter_fig=0, typ_move=0, transform=0, last_cut=0;
int typ_roki=0, move_rook[4]={1,1,1,1};

void Move_Write()
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
	if(letter_fig!='P')
	{
		printf("%c",letter_fig);
	}
	printf("%c%c%c%c%c",gor_begin+96, ver_begin+48, typ_move, gor_end+96, ver_end+48);
	if((typ_move==':') || (typ_move=='x'))
	{
		printf("\nВзята фигура %c на поле %c%c",C[ver_end][gor_end],gor_end+96, ver_end+48);
	}
	else
	{
		printf("\n");
	}
	if(transform)
	{
		printf("\nПешка %c%c попала на поле %c%c и стала ",gor_begin+96, ver_begin+48,gor_end+96, ver_end+48,transform);
	}
	else
	{
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void Roki_Write()
{
	int i=0;
	printf("\nХод №%i за ",move/2+move % 2);
	if(move % 2)
	{
		printf("белых: ");
	}
	else
	{
		printf("чёрных: ");
	}
	printf("O");
	while(i<typ_roki)
	{
		printf("-O");
		i++;
	}
	printf("\n\n\n\n");
}

void Error_Move()
{
	printf("\nСейчас ход №%i за ",move/2+move % 2);
	if(move % 2)
	{
		printf("белых, ");
	}
	else
	{
		printf("чёрных, ");
	}
}

void Error_Text(int i)
{
	printf("%i\n",i);
	switch(i)
	{
		case 1:
			printf("К сожалению, открыть введённый вами файл, не предоставляется возможным.");
			break;
			
		case 2:
			printf("Номер хода указан не верно");
			Error_Move();
			break;
			
		case 3:
			Error_Move();
			printf("\nОшибка ввода данных хода.");
			break;
			
		case 4:
			Move_Write();
			printf("\nФигура не может походить на своё же поле.");
			break;
			
		case 5:
			Move_Write();
			printf("\nНевозможно взять фигуру с того поля, где она не указана.");
			break;
			
		case 6:
			Move_Write();
			printf("На поле %c%c фигура %c не стоит.",gor_begin+96,ver_begin+48,letter_fig+32*((move+1)%2));
			break;

		case 7:
			Error_Move();
			printf("Неправильна записана рокировка: многовато или маловато повторений символов \'-O\'.");
			break;
			
		case 8:
			Move_Write();
			printf("\nФигура не может встать на занятое фигурой %c поле %c%c.",C[ver_end][gor_end],gor_end+96,ver_end+48);
			break;
			
		case 9:
			Move_Write();
			printf("\nФигура не может срубить фигуру %c на поле %c%c, так как они одного цвета.",C[ver_end][gor_end],gor_end+96,ver_end+48);
			break;
			
		case 10:
			Move_Write();
			printf("\nФигура не может срубить фигуру на поле %c%c, так как на этом поле нет фигуры.",gor_end+96,ver_end+48);
			break;
			
		case 11:
			Move_Write();
			printf("Пешка на поле %c%c может идти только на 1 клетку вперёд, или на 2 клетки вперёд, если идёт с первоначальной позиции",gor_begin+96,ver_begin+48);
			break;
			
		case 12:
			Move_Write();
			printf("Пешка на поле %c%c может ходить только вдоль своей вертикали",gor_begin+96,ver_begin+48);
			break;
			
		case 13:
			Move_Write();
			printf("Пешка на поле %c%c может рубить только вдоль диагонали на одну клетку перед собой",gor_begin+96,ver_begin+48);
			break;
			
		case 14:
			Move_Write();
			printf("Пешка на поле %c%c может рубить фигуры только на соседних вертикалях",gor_begin+96,ver_begin+48);
			break;
			
		case 15:
			Move_Write();
			printf("Фигура %c не может перешагивать через фигуру", letter_fig);
			break;
			
		case 16:
			Move_Write();
			printf("Фигура %c с поля %c%c не может пойти на поле %c%c.",letter_fig,gor_begin+96,ver_begin+48,gor_end+96,ver_end+48);
			break;
			
		case 17:
			Roki_Write();
			printf("\nКороль или рокирующаяся ладья уже ходили в этой партии.");
			break;
			
		case 18:
			Roki_Write();
			printf("\nРокирующаяся ладья уже ходила в этой партии.");
			break;
			
		case 19:
			Move_Write();
			printf("Новый массив символов фигур точно был изменён.");
			break;
			
		default:
			printf("Я не знаю данной ошибки");
	}
	printf("\nИсправьте ошибку и попробуйте снова!");
	exit(1);
}
int Module(int x)
{
	if(x<0)
	{
		x=-x;
	}
	return x;
}

int Check_Getc(char ch)
{
	if(ch!=' ' && ch!='.' && ch!='X' && ch!='#' && ch!='+' && ch!='!' && ch!='?' && ch!='\n' && ch!='\t') return 1;
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
	for(i=0;i<6;i++)
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
		printf("\n%i",move_input);
		Error_Text(2);
	}
}


void Move_Read(FILE *f1, char ch)
{
	transform=0;
	last_cut=0;
	if(Check_Gor(ch))
	{
		letter_fig=Type_figure[0];
	}
	else
	{
		if(Check_Massive(ch))
		{
			letter_fig=ch;
			ch=getc(f1);
		}
		else
		{
			Error_Text(3);
		}
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Gor(ch))
	{
		gor_begin=ch-96;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Ver(ch))
	{
		ver_begin=ch-48;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(ch=='-' || ch=='x' || ch==':')
	{
		typ_move=ch;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Gor(ch))
	{
		gor_end=ch-96;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Ver(ch))
	{
		ver_end=ch-48;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	//Проверка на логическую корректность ходов
	if((gor_begin==gor_end)&&(ver_begin==ver_end))
	{
		Error_Text(4);
	}
	
	if(((move % 2 == 1)+(C[ver_begin][gor_begin]<=96))==1)
	{
		Error_Text(5);
	}
	
	if(C[ver_begin][gor_begin]!=letter_fig+32*((move+1)%2))
	{
		Error_Text(6);
	}
	
	//Заготовка для превлащения
	if(letter_fig=='P' && (ver_end==1 || ver_end==8))
	{
		ch=Search_Read(f1,ch);
		if(Check_Massive(ch) && ch!='P')
		{
			transform=ch;
		}
	}
}

void Roki_Read(FILE *f1, char ch)
{
	ch=getc(f1);
	ch=Search_Read(f1,ch);
	while(ch=='-')
	{
		ch=getc(f1);
		ch=Search_Read(f1,ch);
		if(ch=='O')
		{
			typ_roki++;
			ch=getc(f1);
		}
		else
		{
			Error_Text(3);
		}
	}
	if(typ_roki==0 || typ_roki>2)
	{
		Error_Text(7);
	}
}






void Board_Init()
{
	int i,j;
	C[0][0]=' ';
	for(i=1;i<=8;i++)
	{
		C[i][0]=i+48;
		C[0][i]=i+96;
		C[2][i]=Type_figure[0];
		C[7][i]=Type_figure[0]+32;
		for(j=3;j<=6;j++)
		{
			C[j][i]=' ';
		}
	}
	for(j=1;j<=5;j++)
	{
		C[1][j]=Type_figure[j];
		C[8][j]=Type_figure[j]+32;
	}
	for(j=6;j<=8;j++)
	{
		C[1][j]=Type_figure[9-j];
		C[8][j]=Type_figure[9-j]+32;
	}
	
}

void Board()
{
	int i,j;
	for(i=8;i>=1;i--)
	{
		printf("\n%c  ",C[i][0]);
		for(j=1;j<=8;j++)
		{
			printf("%2c",C[i][j]);
		}
	}
	printf("\n");
	printf("\n%c  ",C[0][0]);
	for(j=1;j<=8;j++)
	{
		printf("%2c",C[0][j]);
	}
	printf("\n");
}

int Attack_or_Not()
{
	if(typ_move=='-')
	{
		if(C[ver_end][gor_end]==' ')
		{
			return 1;
		}
		else
		{
			Error_Text(8);
		}
	}
	if((typ_move==':') || (typ_move=='x'))
	{
		if(C[ver_end][gor_end]!=' ')
		{
			if(((move % 2 == 1)+(C[ver_end][gor_end]<=96))==1) 
			//Первое выражение возвращает 1 если белых ход, второе -- 1 если белая фигура (принцип исключающего ИЛИ (XOR))
			{
				last_cut=C[ver_end][gor_end];
				return 1;
			}
			else
			{
				Error_Text(9);
			}
		}
		else
		{
			Error_Text(10);
		}
	}
}
void Moving()
{
	if(Attack_or_Not())
	{
		C[ver_end][gor_end]=letter_fig+32*((move+1)%2);
		C[ver_begin][gor_begin]=' ';
	}
}

int Check_Pown() //К удивлению самая сложная проверка
{
	int distance=-1+2*(move%2);
	int dif_ver=ver_end-ver_begin;
	if(typ_move=='-')
	{
		if(gor_begin==gor_end)
		{
			if(ver_begin==2 || ver_begin==7)
			{
				distance*=2;
			}
			if((dif_ver==distance) || (dif_ver==distance/2))
			{
				return 1;
			}
			else
			{
				Error_Text(11);
			}
		}
		else
		{
			Error_Text(12);
		}
	}
	if(((typ_move==':') || (typ_move=='x')) && (Module(gor_begin-gor_end)==1))
	{
		if(dif_ver==distance)
		{
			return 1;
		}
		else
		{
			Error_Text(13);
		}
	}
	else
	{
		Error_Text(14);
	}
}

int Check_Rook()
{
	if((gor_begin==gor_end) || (ver_begin==ver_end))
	{
		return 1;
	}
	return 0;
}

int Check_Knight()
{
	if(( Module(ver_end-ver_begin)+ Module(gor_end-gor_begin) == 3) && (ver_end!=ver_begin) && (gor_end!=gor_begin))
	{
		return 1;
	}
	return 0;
}

int Check_Bishop()
{
	if( Module(ver_end-ver_begin) == Module(gor_end-gor_begin))
	{
		return 1;
	}
	return 0;
}

int Check_King()
{
	if(( Module(ver_end-ver_begin) <= 1) && ( Module(gor_end-gor_begin) <= 1))
	{
		return 1;
	}
	return 0;
}

void Check_BNQ()
{
	int i,j, dif_i=0,dif_j=0;
	i=ver_begin;
	j=gor_begin;
	if(ver_end-i)
	{
		dif_i=(ver_end-i)/Module(ver_end-i);
	}
	if(gor_end-j)
	{
		dif_j=(gor_end-j)/Module(gor_end-j);
	}
	i+=dif_i;
	j+=dif_j;
	while((i!=ver_end)||(j!=gor_end))
	{
		if(C[i][j]!=' ')
		{
			Error_Text(15);
		}
		i+=dif_i;
		j+=dif_j;
	}
}

void Move_Pawn()
{
	if(Check_Pown())
	{
		if(ver_end==8 || ver_end==1)
		{
			letter_fig=transform;
		}
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 


void Move_Rook()
{
	if(Check_Rook())
	{
		Check_BNQ();
		Moving();
		if(ver_begin==8-7*(move%2))
		{
			if(gor_begin==1)
			{
				move_rook[3-2*(move%2)]=0;
			}
			else
			{
				if(gor_begin==8)
				{
					move_rook[4-2*(move%2)]=0;
				}
			}
		}
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Knight()
{
	if(Check_Knight())
	//Если расстояние от коня три клетки и начало и конец не находятся на одной линии
	{
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Bishop()
{
	if(Check_Bishop())
	{
		Check_BNQ();
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Queen()
{
	if(Check_Rook() || Check_Bishop()) //Проверка на ход как ладья
	{
		Check_BNQ();
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_King()
{
	if(Check_King())
	{
		Moving();
		if(ver_begin==8-7*(move%2))
		{
			move_rook[3-2*(move%2)]=0;
			move_rook[4-2*(move%2)]=0;
		}
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Figure()
{
	switch(letter_fig)
	{
		case 'P':
			Move_Pawn();
			break;
		case 'R':
			Move_Rook();
			break;
		case 'N':
			Move_Knight();
			break;
		case 'B':
			Move_Bishop();
			break;
		case 'Q':
			Move_Queen();
			break;
		case 'K':
			Move_King();
			break;
		default:
			Error_Text(19);
	}
}

void Rokirovka() //Ошибся, рокировка, даже БЕЗ шаха, требуют много сравнений
{
	int left=(move%2); 
	char temp;
	ver_begin=8-7*left;
	gor_begin=5;
	ver_end=ver_begin;
	int border=3-2*left;
	letter_fig='K';
	typ_move='-';
	
	if(move_rook[border]) //Если король не двигался, то для левой или правой пары массива move_rook
	{
		gor_end=1+7*(typ_roki%2);
		Check_BNQ();
		if(move_rook[border+(typ_roki%2)])
		{
			temp=gor_end;
			gor_end=gor_begin-(2-4*(typ_roki%2));
			Moving();
			gor_begin=temp;
			gor_end-=(gor_end-5)/2;
			letter_fig='R';
			Moving();
		}
		else
		{
			Error_Text(18);
		}
	}
	else
	{
		Error_Text(17);
	}
}

int main()
{
	FILE *f1;
	system("chcp 1251>nul");
	char ch;
	f1=fopen("res//Chess_Game.txt","r");
	if(f1== NULL)
	{
		Error_Text(1);
	}
	printf("\nДа ладно сработало");
	system("CLS");
	Board_Init();
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
			Move_Write();
			Move_Figure();
			Board();
			system("Pause");
			move++;
		}
		
		if(ch=='O')
		{
			typ_roki=0;
			Roki_Read(f1,ch);
			system("CLS");
			Roki_Write();
			Rokirovka();
			Board();
			system("Pause");
			move++;
		}
	}
	fclose(f1);	
	return 0;
}
