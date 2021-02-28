#pragma once
struct Word {
	char word_name[20] = {'\0'};
	int group_id[10] = { 0 };
	char meaning[30] = { '\0' };
	char example_sentence[60] = { '\0' };
	Word* next;
};
struct Group {
	int id;
	Word word;
	char reason[30];
	Group* next;
};
class WordBook {
private:
public:
	Word word_data;//��¼������Ϣ
	void Search(char name[20]);//��ѯ����
	void Add_Group(char reason[30]);//�������������ӷ���
	void Add_Word(int id, char name[20]);//��ӵ��ʽ������
	void All_Group();//�鿴���з���
	void Meaning_Add(char name[20], char meaning[30]);//�������
	void Sentence_Add(char name[20], char sentence[60]);//�������
	void SaveWord(Group* head);//�洢���ʵ��ļ�
	Group* FileRead(Group* head);//���ļ���д��
	void Interface();//���н���
}A;