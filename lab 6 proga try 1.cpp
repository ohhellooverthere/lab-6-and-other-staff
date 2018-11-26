/* Вилучити з тексту всі слова, які містять у собі паліндроми довжиною не менші
за n. Записати результуючий текст у інший файл.*/

#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

bool is_palindrome(char**matrix,int row,int col) {
	int n = strlen(matrix[row]);
	for (int i = 0; i < n / 2; i++)
		if (matrix[i] != matrix[n - 1 - i])
			return false;
	return true;
}
void deleting(char);
void perenos(char*s,char**str)// из s в str
{
		

}
int main()
{
	int n;
	cout << "n= ";
	cin >> n;
	fstream fs;
	string path = "text_for_lab_6.txt";
	fs.open(path, fstream::app|fstream::out| fstream::in);
	char s[300];// сюда считываем весь текст
	int words = 0;
	for (int i = 0; i < sizeof(s); i++)
	{
		if ((s[i] != ' ') || (s[i] != '\0'))
		{
			words++;
		}
	}
	int size = 200;
	char **str = new char*[size];
	for (int i = 0; i < words; i++)
	{
		str[i] = new char[size];// массив куда ложим все изначальные слова из текста
	}
	if (!fs.is_open())
	{
		cout << "error, file wasn't open correctly" << endl;
	}
	else
	{
		cout << "file was opened correctly" << endl;
		fs.getline(s, sizeof(s));// пока не достигнут конец файла класть очередную строку в переменную(s)
		perenos(s, str);

	}
	fs.close();
	
	cout<<is_palindrome(str, 0, size);
}
