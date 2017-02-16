#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

enum QtMsgType;
class QMessageLogContext;
class QString;

void q_message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // MESSAGEHANDLER_HPP
