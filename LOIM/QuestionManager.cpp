#include "QuestionManager.h"
#include <string>
#include <direct.h>
#include <sstream>
#define GetCurrentDir _getcwd

QManager::QManager()
{
	questionList = new linkedList();
}

void QManager::scanQuestion(Question *q, std::ifstream &fp)
{
	std::getline(fp, q->question, ';');
	
	std::getline(fp, q->a1, ';');
	std::getline(fp, q->a2, ';');
	std::getline(fp, q->a3, ';');
	std::getline(fp, q->a4, ';');

	std::string temp_correct;
	std::string temp_difficulty;

	std::string throwaway;

	std::getline(fp, temp_correct, ';');
	std::getline(fp, temp_difficulty, ';');
	std::getline(fp, throwaway, '\n');
	
	int result1;
	int result2;

	std::stringstream res1(temp_correct);
	res1 >> result1;
	std::stringstream res2(temp_difficulty);
	res2 >> result2;

	q->correct = result1;
	q->difficulty = result2;
}

void QManager::readQuestions(char *filename)
{
	std::ifstream fp;
	fp.open(filename);
	Question *q = new Question;
	scanQuestion(q, fp);
	questionList->createNode(q);
	int qLoaded = 1;

	if (!fp.is_open())
	{
		std::cout << "ERR: FILE NOT FOUND " << filename;
		return;
	}

	while (!fp.eof()) 
	{
		Question *_q = new Question;
		scanQuestion(_q, fp);
		questionList->insert_start(_q);
		qLoaded++;
	}


	std::cout << "\nQuestionManager::Successfuly loaded " << qLoaded << " questions.";
	fp.close();
}

void QManager::listQuestions()
{
	questionList->display();
}

void QManager::freeQuestions()
{
	questionList->freeNodes();
}

template <typename T>

T QManager::StringToNumber(const std::string &Text)
{
	std::stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}