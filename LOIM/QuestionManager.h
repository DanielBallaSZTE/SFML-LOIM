#ifndef _QUESTIONMANAGER
#define _QUESTIONMANAGER

#include "linkedList.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <sstream>
#include "structs.h"

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