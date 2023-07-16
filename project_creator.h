#ifndef PROJECT_CREATOR_H
#define PROJECT_CREATOR_H

// Qt includes
#include <QString>

// This should initialize a project with a main file, main function, and CMakeLists.txt file at the very least.
class ProjectCreator
{
public:
	ProjectCreator(QString projectName);
	bool CreateDefaults();

private:
	QString projectName;
};

#endif // PROJECT_CREATOR_H