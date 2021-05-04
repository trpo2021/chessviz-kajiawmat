#include<stdlib.h>
#include<stdio.h>
#include "IO.h"
#include "Board.h"
extern int move, gor_begin, ver_begin, gor_end, ver_end;
extern char letter_fig, C[][9];
extern const int Players, Ver_min, Gor_min, Reg;


void Error_Move()
{
	printf("\nСейчас ход №%i за ",move/Players + move%Players);
	if(move % Players)
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
	system("CLS");
	printf("Ошибка №%i\n",i);
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
			printf("\nСейчас ход другого цвета, так что походите фигурой другого цвета.");
			break;
			
			
		case 6:
			Move_Write();
			printf("На поле %c%c фигура %c не стоит.",gor_begin+Gor_min,ver_begin+Ver_min,letter_fig+Reg*((move+1)%Players));
			break;

		case 7:
			Error_Move();
			printf("Неправильна записана рокировка: многовато или маловато повторений символов \'-O\'.");
			break;
			
		case 8:
			Move_Write();
			printf("\nФигура не может встать на занятое фигурой %c поле %c%c.",C[ver_end][gor_end],gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 9:
			Move_Write();
			printf("\nФигура не может срубить фигуру %c на поле %c%c, так как они одного цвета.",C[ver_end][gor_end],gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 10:
			Move_Write();
			printf("\nФигура не может срубить фигуру на поле %c%c, так как на этом поле нет фигуры.",gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 11:
			Move_Write();
			printf("Пешка на поле %c%c может идти только на 1 клетку вперёд, или на 2 клетки вперёд, если идёт с первоначальной позиции",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 12:
			Move_Write();
			printf("Пешка на поле %c%c может ходить только вдоль своей вертикали",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 13:
			Move_Write();
			printf("Пешка на поле %c%c может рубить только вдоль диагонали на одну клетку перед собой",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 14:
			Move_Write();
			printf("Пешка на поле %c%c может рубить фигуры только на соседних вертикалях",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 15:
			Move_Write();
			printf("Фигура %c не может перешагивать через фигуру", letter_fig);
			break;
			
		case 16:
			Move_Write();
			printf("Фигура %c с поля %c%c не может пойти на поле %c%c.",letter_fig,gor_begin+Gor_min,ver_begin+Ver_min,gor_end+Gor_min,ver_end+Ver_min);
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
			
		case 20:
			Move_Write();
			printf("Нормально не указано в какую фигуру превращается пешка, когда встаёт на поле %c%c.",gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		default:
			printf("Я не знаю данной ошибки");
	}
	printf("\nИсправьте ошибку и попробуйте снова!\n");
	if(i!=1)
	{
		Board();
	}
	system("pause>nul");
	exit(1);
}
