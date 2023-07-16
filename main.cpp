#include <QCoreApplication>

// Project includes
#include "project_creator.h"

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	// Check if we're creating a new project.
	if (app.arguments().contains("new"))
	{
		int projectNameIdx = app.arguments().indexOf("new") + 1;
		if (app.arguments().size() <= projectNameIdx)
		{
			qDebug().noquote() << "A project name must be specified.";
			return -1;
		}

		ProjectCreator pc(app.arguments()[projectNameIdx]);
		if (!pc.CreateDefaults())
		{
			qDebug().noquote() << "Unable to create project.";
		}
	}

	return 0;
}