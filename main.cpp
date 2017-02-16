#include <QApplication>
#include <QtGlobal> // qInstallMessageHandler

#include <adaptink.hpp>
#include <messagehandler.hpp>

int main(int argc, char **argv)
{
	qInstallMessageHandler(q_message_handler);

	int retval;
	do {
		QApplication app (argc, argv);
		Adaptink adapatink;
		adapatink.show();
		retval = app.exec();
	} while (retval == RESTART_EXIT_STATUS);

	return retval;
}
