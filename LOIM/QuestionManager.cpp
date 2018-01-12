#include "QuestionManager.h"
#include <string>
#include <direct.h>
#include <sstream>
#define GetCurrentDir _getcwd


/**
 * Constructor for QManager.
 * Creates a new linkedList.
 */
QManager::QManager()
{
	questionList = new linkedList();
} /* QManager */


/**
 * Destructor for QManager.
 * Frees the question structures, then frees the linkedList.
 */
QManager::~QManager()
{
	freeQuestions();
	delete questionList;
} /* ~QManager */


/**
 * Reads a single Question structure from the given file.
 * @q Pointer to a Question structure.
 * @fp Reference of the file to read from.
 */
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
} /* scanQuestion */


/**
 * Reads questions from the given file.
 * @filename name of the file to read from.
 */
void QManager::readQuestions(char *filename)
{
	std::ifstream fp;
	fp.open(filename);
	Question *q = new Question;

	if (!fp.is_open())
	{
		std::cout << "ERR: FILE NOT FOUND " << filename;
		return;
	}

	scanQuestion(q, fp);
	questionList->createNode(q);
	int qLoaded = 0;

	while (!fp.eof()) 
	{
		Question *_q = new Question;
		scanQuestion(_q, fp);
		questionList->insert_start(_q);
		qLoaded++;
	}


	std::cout << "\nQuestionManager::Successfuly loaded " << qLoaded << " questions.";
	fp.close();
} /* readQuestions */


/**
* Lists all questions
*/
void QManager::listQuestions()
{
	questionList->display();
} /* listQuestions */


/**
* Frees all Question structures.
*/
void QManager::freeQuestions()
{
	questionList->freeNodes();
} /* freeQuestions */


/**
* Converts a std::string to a number
* @Text Reference of the string to convert.
*/
template <typename T>
T QManager::StringToNumber(const std::string &Text)
{
	std::stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
} /* StringToNumber */