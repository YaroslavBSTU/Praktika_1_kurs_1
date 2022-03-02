#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
void arabrim()
{
	int a = 0;
	printf("Введите целое арабское число от 1 до 3999\n");
	if (scanf("%d", &a) == NULL) { printf("Было введено неарабское число, а так как числовой переменной задать\n"); printf("нечисловое значение невозможно, то программа прекратила свою работу.\n"); return; }
	while (a<1 || a>3999)
	{
		printf("Было введено арабское число невходящее в диапазон от 1 до 3999\n");
		printf("Программа умеет переводить арабские числа входящие в диапазон от 1 до 3999\n");
		printf("Введите целое арабское число от 1 до 3999 еще раз\n");
		if (scanf("%d", &a) == NULL) { printf("Было введено неарабское число, а так как числовой переменной задать\n"); printf("нечисловое значение невозможно, то программа прекратила свою работу.\n"); return; };
	}
	printf("Римская запись числа %d\n",a);
	while (a >= 1000) { a -= 1000; printf("M"); }
	while (a >= 900) { a -= 900; printf("CM"); }
	while (a >= 500) { a -= 500; printf("D"); }
	while (a >= 400) { a -= 400; printf("CD"); }
	while (a >= 100) { a -= 100; printf("C"); }
	while (a >= 90) { a -= 90; printf("XC"); }
	while (a >= 50) { a -= 50; printf("L"); }
	while (a >= 40) { a -= 40; printf("XL"); }
	while (a >= 10) { a -= 10; printf("X"); }
	while (a >= 9) { a -= 9; printf("IX"); }
	while (a >= 5) { a -= 5; printf("V"); }
	while (a >= 4) { a -= 4; printf("IV"); }
	while (a >= 1) { a -= 1; printf("I"); }
	printf("\n");
}
int rimarab(char* str,int dlina)
{
	int c = 0, kM = 0, kD = 0, kC = 0, kL = 0, kX = 0, kV = 0, kI = 0, kCM = 0, kCD = 0, kXC = 0, kXL = 0, kIX = 0, kIV = 0; // c-само число
	char razr = ' ';//razr - последний считанный символ
	for (int i = 0; i < dlina; i++)
	{
		if (str[i] == 'C') { kC++; if (razr == 'L' || razr == 'V' || razr == 'I' || kC > 3 || kCM > 0 || kCD > 0 || (kC > 1 && (str[i + 1] == 'M' || str[i + 1] == 'D'))) { c = 4000; return c; } if (str[i + 1] == 'M') { c += 900; kCM++; kC--; i++;  razr = 'M'; continue; }  if (str[i + 1] == 'D') { c += 400; kCD++; i++; kC--; razr = 'D'; continue; } c += 100;  razr = 'C'; continue; }
		if (str[i] == 'X') { kX++; if (razr == 'V' || kX > 3 || kXC > 0 || kXL > 0 || (kX > 1 && (str[i + 1] == 'M' || str[i + 1] == 'D' || str[i + 1] == 'C' || str[i + 1] == 'L'))) { c = 4000; return c; } if (str[i + 1] == 'C') { c += 90; kXC++; kX--; i++;  razr = 'C'; continue; }  if (str[i + 1] == 'L') { c += 40; kXL++; kX--; i++;  razr = 'L'; continue; } c += 10;  razr = 'X'; continue; }
		if (str[i] == 'I') { kI++; if (kI > 3 || kIX > 0 || kIV > 0 || (kI > 1 && (str[i + 1] == 'M' || str[i + 1] == 'D' || str[i + 1] == 'C' || str[i + 1] == 'L' || str[i + 1] == 'X' || str[i + 1] == 'V'))) { c = 4000; return c; } if (str[i + 1] == 'V') { c += 4; kIV++; i++; kI--; razr = 'V'; continue; } if (str[i + 1] == 'X') { c += 9; i++; kIX++; kI--; razr = 'X'; continue; } c += 1; razr = 'I';  continue; }
		if (str[i] == 'M') { kM++; if (razr == 'D' || razr == 'L' || razr == 'X' || razr == 'V' || razr == 'I' || kM > 3 || kCM > 0) { c = 4000; return c; } c += 1000; razr = 'M'; continue; }
		if (str[i] == 'D') { kD++; if (razr == 'L' || razr == 'X' || razr == 'V' || razr == 'I' || kD > 1 || kCD > 0) { c = 4000; return c; }  c += 500; razr = 'D'; continue; }
		if (str[i] == 'L') { kL++; if (razr == 'V' || razr == 'I' || kL > 1 || kXL > 0) { c = 4000; return c; }  c += 50; razr = 'L'; continue; }
		if (str[i] == 'V') { kV++; if (razr == 'V' || kV > 1 || str[i + 1] == 'X' || str[i + 1] == 'V' || str[i + 1] == 'C' || str[i + 1] == 'D' || str[i + 1] == 'L' || str[i + 1] == 'M' || kIV > 0) { c = 4000; return c; }  c += 5; razr = 'L'; continue; }
		{  c = 4000; return c; }
	}
	if (c == 0) c = 4000;
	return c;
}
int calc(void)
{
	char str1[32], str2[16], str3[1], str4[16];
	int rez = 0;
	printf("Условие ввода:\n");
	printf("Вводимая строка должна состоять из 2 римских чисел, между которыми должна стоять математическая операция.\n");
	printf("Калькулятор умеет складывать(+), вычитать(-), умножать(*) и целочисленно делить(/)\n");
	printf("В вводимой строке пробелы не допускаются\n");
	printf("Римские числа должны быть от I(1) до MMMCMXCIX(3999)\n");
	printf("Пример строки:'XXX+V'\n");
	scanf("%s",str1);
	int i1 = 0,i2=0,i3=0;
	for (i1=0; i1 < strlen(str1); i1++)
	{
		if (str1[i1] != '+' && str1[i1] != '-' && str1[i1] != '*' && str1[i1] != '/') str2[i1] = str1[i1]; else { str3[0] = str1[i1]; break; }
	}
	for (i2 = i1+1; i2 < strlen(str1); i2++)
	{
		str4[i3] = str1[i2];
		i3++;
	}
	if (rimarab(str2, i1)==4000||rimarab(str4, i3)==4000) { return 100000;}
	switch (str3[0])
	{
	case '+': {rez = rimarab(str2, i1) + rimarab(str4, i3); } break;
	case '-': {rez= rimarab(str2, i1) - rimarab(str4, i3); } break;
	case '*': {rez= rimarab(str2, i1) * rimarab(str4, i3); } break;
	case '/': {rez= rimarab(str2, i1) / rimarab(str4, i3); } break;
	default: {  return 100000; }
	}
	return rez;
}
int main()
{
	setlocale(LC_ALL,"Russian");
	int r=0;//r-режим работы
	printf("Выберите соответствующий номер режима работы\n");
	printf("1-перевод числа из арабских цифр в римские цифры\n");
	printf("2-перевод числа из римских цифр в арабские цифры\n");
	printf("Программа умеет переводить целые числа из диапазона от 1(I) до 3999(MMMCMXCIX)\n");
	printf("3-калькулятор, работающий в римской системе счисления\n");
	printf("Калькулятор умеет складывать(+), вычитать(-), умножать(*) и целочисленно делить(/)\n");
	printf("римские числа из диапазона от I(1) до MMMCMXCIX(3999)\n");
	printf("Чтобы прекратить работу программы введите 0\n");
	do
	{
		printf("Введите режим работы\n");
		if (scanf("%d", &r) == NULL) { printf("Было введено нечисло. Режим работы вводится в виде числа, а так как числовой переменной задать нечисловое\n"); printf("значение невозможно, то программа прекратила свою работу.\n"); return 101; }
		switch (r)
		{
		case 1:  arabrim();  break;
		case 2:
		{
			printf("Введите римское число\n");
			char str[16];//максимальное длинное римское число содержит 15 знаков MMMDCCCLXXXVIII (это 3888) + нужна ячейка для нуль-символа
			scanf("%s", str);//gets_s отказывается работать в этой программе
			if (rimarab(str, strlen(str)) > 3999 || rimarab(str, strlen(str)) < 1) printf("Некорректное число\n"); else printf("%d\n", rimarab(str, strlen(str)));
		} 
		break;
		case 3:
		{
			int s = calc();
			if ( s!= 100000) printf("Ответ %d\n", s); else printf("Строка не соответствует условию ввода.\n");
		}
		break;
		default: {printf("Было введена несуществующая команда. Попробуйте ввести существующую команду\n"); }
		}
	} while (r != 0);
	printf("Прекращение работы программы\n");
	return 0;
}