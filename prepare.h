#pragma once
struct Word {
	char word_name[20];
	int group_id[10];
	char meaning[30];
	char example_sentence[60];
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
	Word word_data;//记录单词信息
	void Search(char name[20]);//查询单词
	void Add_Group(char reason[30]);//输入分组依据添加分组
	void Add_Word(int id, char name[20]);//添加单词进入分组
	void All_Group();//查看所有分组
	void Meaning_Add(char name[20], char meaning[30]);//添加释义
	void Sentence_Add(char name[20], char sentence[60]);//添加例句
	void SaveWord(Word* control);//存储单词到文件
	Group* FileRead(Group* head);//从文件中写入
	void Interface();//运行界面
};