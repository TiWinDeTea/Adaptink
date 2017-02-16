#include <QApplication>
#include <QtGlobal> // qInstallMessageHandler

#include <adaptink.hpp>
#include <messagehandler.hpp>

int main(int argc, char **argv)
{
	qInstallMessageHandler(q_message_handler);

	QApplication app (argc, argv);
	Adaptink adapatink;
	adapatink.show();

	return app.exec();
}
