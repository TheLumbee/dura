#include "project_creator.h"

// Qt includes
#include <QDebug>
#include <QDir>
#include <QFile>

// Create the project under the specified project name.
// Probably should have some sort of naming convention...
ProjectCreator::ProjectCreator(QString projectName) :
	projectName(projectName) {}

bool ProjectCreator::CreateDefaults()
{
	// Does this directory exist? Better not, or this ain't going to work.
	QDir currentDir(QDir::currentPath());
	if (!currentDir.mkdir(projectName))
	{
		qDebug().noquote() << "Directory with same name as project already exists. Exiting...";
		return false;
	}
	
	currentDir.cd(projectName);

	// Create the main.cpp file with a standard "Hello, world!"
	// If file already exists, notify and stop
	if (QFile::exists(QString("%1/main.cpp").arg(projectName)))
	{
		qDebug().noquote() << "Main file already exists in this directory. Exiting...";
		return false;
	}

	QFile mainFile(QString("%1/main.cpp").arg(projectName));
	mainFile.open(QFile::ReadWrite);

	// Actually create the file and write the intro.
	QString helloWorldText("#include <iostream>\n\nint main()\n{\n\tstd::cout << "
		"\"Hello, world!\" << std::endl;\n\treturn 0;\n}");
	mainFile.write(helloWorldText.toLatin1());
	mainFile.close();

	return true;
}
