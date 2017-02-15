#include <QApplication>
#include "adaptink.hpp"

int main(int argc, char **argv)
{
	QApplication app (argc, argv);

	Adaptink adapatink;
	adapatink.show();

	return app.exec();
}
