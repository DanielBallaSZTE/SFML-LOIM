#ifndef _QUESTIONMANAGER
#define _QUESTIONMANAGER

#include "linkedList.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

typedef struct Question{
	std::string	question;

	// Answers
	std::string	a1;
	std::string	a2;
	std::string	a3;
	std::string	a4;

	int		correct;
	int		difficulty;
} Question; /* Question */

class QManager {
private:
	linkedList	*questionList;
	void		scanQuestion(Question *q, std::ifstream &fp);

public:
	QManager();
	~QManager();
	void	listQuestions();
	void	readQuestions(char *filename);
	void	freeQuestions();
	template <typename T>
	T		StringToNumber(const std::string &Text);
}; /* Qmanager */

#endif