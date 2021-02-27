#include<iostream>
#include<Windows.h>
#include<conio.h>
#include "prepare.h"
using namespace std;
//运行界面
void WordBook::Interface() {
	l0:system("cls");
	cout << "\t\t\t\t\t\t\t\t|~~~~~~~~~~~~~" << endl
		<< "\t\t\t\t\t\t\t\t|Welcome!|" << endl
		<< "\t\t\t\t\t\t\t\t|请选择功能:     \t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|1.添加单词       \t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|2.查询单词       \t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|3.添加分组       \t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|4.查询所有分组\t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|5.添加释义       \t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|6.添加例句       \t\t|" << endl
		<< "\t\t\t\t\t\t\t\t|7.退出              \t\t|" << endl;
	int key = _getch();
	switch (key) {
	case 49: {
		int id = 0;
		char str[20];
		WordBook::Add_Word(id, str);
	}break;
	case 50: {
		char str[20];
		WordBook::Search(str);
	}break;
	case 51: {
		char reason[30];
		WordBook::Add_Group(reason);
	}
	case 52: WordBook::All_Group(); break;
	case 53: {
		char str[20], meaning[30];
		WordBook::Meaning_Add(str, meaning);
	}break;
	case 54: {
		char str[20], sentence[60];
		WordBook::Sentence_Add(str, sentence);
	}break;
	case 55: return; break;
	default: {
		cout << "无效的按键!按任意键返回" << endl;
		_getch();
		goto l0;
	}
	}
}
void WordBook::Add_Word(int id, char name[20]) {

}
void WordBook::Search(char name[20]) {

}
void WordBook::Add_Group(char reason[30]) {

}
void WordBook::All_Group() {

}
void WordBook::Meaning_Add(char name[20], char meaning[30]) {

}
void WordBook::Sentence_Add(char name[20], char sentence[60]) {

}