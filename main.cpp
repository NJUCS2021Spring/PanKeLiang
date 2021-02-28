#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include "prepare.h"
using namespace std;
//运行界面
int main() {
	A.Interface();
	return 0;
}
void WordBook::Interface() {
	l0:system("cls");
	cout << "\t\t\t\t\t-------------------------" << endl
		<< "\t\t\t\t\t|Welcome!        \t|" << endl
		<< "\t\t\t\t\t|请选择功能:     \t|" << endl
		<< "\t\t\t\t\t|1.添加单词       \t|" << endl
		<< "\t\t\t\t\t|2.查询单词       \t|" << endl
		<< "\t\t\t\t\t|3.添加分组       \t|" << endl
		<< "\t\t\t\t\t|4.查询所有分组  \t|" << endl
		<< "\t\t\t\t\t|5.添加释义       \t|" << endl
		<< "\t\t\t\t\t|6.添加例句       \t|" << endl
		<< "\t\t\t\t\t|7.退出              \t|" << endl
		<< "\t\t\t\t\t-------------------------";
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
		cout << "\nadd group: 输入分组依据\n";
		char reason[30];
		cin >> reason;
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
	Group* head = NULL;
	head = A.FileRead(head);
	int tid = 1;
	if (head == NULL) {
		head = new Group;
		head->id = 1;
		
		strcpy(head->reason, reason);
		head->next = NULL;
	}
	else {
		Group* p = head;
		while (p->next != NULL) {
			p = p->next;
			tid += 1;
		}
		Group* tp = new Group;
		tp = p->next;
		tp->id = tid;
		strcpy(tp->reason, reason);
		tp->next = NULL;
		delete tp;
		delete p;
	}
	cout << "Add successfully!";
	A.SaveWord(head);
}
void WordBook::All_Group() {

}
void WordBook::Meaning_Add(char name[20], char meaning[30]) {

}
void WordBook::Sentence_Add(char name[20], char sentence[60]) {

}
Group* WordBook::FileRead(Group* head) {
	FILE* pfile = fopen("D:\\MyCode\\Word.txt", "r");
	if (pfile == NULL)
		cout << "Error!";
	else {
		Group* p = new Group;
		while (fscanf(pfile, "%d %s\n", &p->id, p->reason) != EOF) {
			Word* t = new Word;
			while (fscanf(pfile, "%s %s %s\n", t->word_name, t->meaning,
				t->example_sentence) != EOF) {
				*(t->next) = p->word;
				p->word = *t;
			}
			p->next = head;
			head = p;
		}
	}
	return head;
}
void WordBook::SaveWord(Group* head) {
	FILE* pfile = fopen("D:\\MyCode\\Word.txt", "w");
	if (pfile == NULL)
		cout << "Error!";
	else {
		Group* p = head;
		while (p) {
			fprintf(pfile, "Group id：%d     分组依据：%s\n", p->id, p->reason);
			Word* t = &head->word;
			while (t ->word_name[0] != '\0') {
				fprintf(pfile, "%s %s %s\n", t->word_name, t->meaning,
					t->example_sentence);
				t = t->next;
			}
			p = p->next;
			fprintf(pfile, "\n");
		}
	}
}