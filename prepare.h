#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>
using namespace std;
struct Word {
	char word_name[20];
	int group_id[10];
	char meaning[30];
	char example_sentence[60];
};
class WordBook {
private:
public:
	Word word_data;//��¼������Ϣ
	void Search(char name[20]);//��ѯ����
	void Add_Group(char reason[30]);//�������������ӷ���
	void Add_Word(int id, char name[20]);//��ӵ��ʽ������
	void Meaning_Add(char name[20], char meaning[30]);//�������
	void Sentence_Add(char name[20], char sentence[60]);//�������
	void SaveWord(Word* control);//�洢���ʵ��ļ�
	void FileRead(Word* control);//���ļ���д��
	void Interface();//���н���
	void Function();//����ѡ��
};