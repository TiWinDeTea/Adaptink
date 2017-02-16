// Copyright 2017 Lucas Lazare
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <QString> // QString
#include <string> // std::string
#include <iostream> // std::cerr
#include <exception> // std::terminate


#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(WIN64)) && !defined(__CYGWIN__)
#define MSGH_OS_WINDOWS
#endif


#ifndef MSGH_OS_WINDOWS
#include <climits>
#include <cstdlib> // realpath & associated free
#endif

#include <messagehandler.hpp>

static const std::string MESSAGE_HANDLER_TEXT[] = { "[Debug]: ",
													"[Warning]: ",
													"[Critical]: ",
													"[Fatal Error]: ",
													"[Info]: " };

struct MessageLogContext {
	const char* file;
	int line;
	const char* function;
	const char* category;
};

void q_message_info(const std::string& header, const MessageLogContext& context, const QString& msg);
void q_message_debug(const std::string& header, const MessageLogContext& context, const QString& msg);
void q_message_warning(const std::string& header, const MessageLogContext& context, const QString& msg);
void q_message_critical(const std::string& header, const MessageLogContext& context, const QString& msg);
void q_message_fatal(const std::string& header, const MessageLogContext& context, const QString& msg);
void console_set_color(const std::string& color);
void console_reset_color();
std::string realPath(const char* file);

void q_message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {

	MessageLogContext local_context;
	if (context.function == nullptr) {
		local_context = { context.file, context.line, "Unknown method", context.category };
	} else {
		local_context = { context.file, context.line, context.function, context.category };
	}

	switch (type) {
	case QtDebugMsg:
		q_message_debug(MESSAGE_HANDLER_TEXT[type], local_context, msg);
		break;
	case QtWarningMsg:
		q_message_warning(MESSAGE_HANDLER_TEXT[type], local_context, msg);
		break;
	case QtCriticalMsg:
		q_message_critical(MESSAGE_HANDLER_TEXT[type], local_context, msg);
		break;
	case QtFatalMsg:
		q_message_fatal(MESSAGE_HANDLER_TEXT[type], local_context, msg);
		break;
	case QtInfoMsg:
		q_message_info(MESSAGE_HANDLER_TEXT[type], local_context, msg);
		break;
	default:
		break;
	}
}

inline void q_message_info(const std::string& header, const MessageLogContext& context, const QString& msg) {
	console_set_color("blue");
	std::cout << header;
	console_reset_color();
	std::cout << msg.toStdString() << "\n";
	std::cout << "at: " << realPath(context.file) << ":" << context.line << "  -  " << context.function;
	std::cout << "\n" << std::endl;
}

inline void q_message_debug(const std::string& header, const MessageLogContext& context, const QString& msg) {
	console_set_color("yellow");
	std::cout << header;
	console_reset_color();
	std::cout << msg.toStdString() << "\n";
	std::cout << "at: " << realPath(context.file) << ":" << context.line << "  -  " << context.function;
	std::cout << "\n" << std::endl;
}

inline void q_message_warning(const std::string& header, const MessageLogContext& context, const QString& msg) {
	console_set_color("yellow");
	std::cout << header << "\n    ";
	console_reset_color();
	std::cout << msg.toStdString() << "\n";
	std::cout << "at: " << realPath(context.file) << "\n    " << context.function << "\n    line: " << context.line;
	std::cout << "\n" << std::endl;
}

inline void q_message_critical(const std::string& header, const MessageLogContext& context, const QString& msg) {
	console_set_color("red");
	std::cout << header << "\n    " << std::flush;
	console_reset_color();
	std::cout << msg.toStdString() << "\n\n";

	console_set_color("red");
	std::cout << "File:\n    ";
	console_reset_color();
	std::cout << realPath(context.file) << ':';
	std::cout << context.line << std::endl;

	console_set_color("red");
	std::cout << "Method:\n    ";
	console_reset_color();
	std::cout << context.function << "\n\n" << std::endl;
}

inline void q_message_fatal(const std::string& header, const MessageLogContext& context, const QString& msg) {
	q_message_critical(header, context, msg);
	std::terminate();
}


inline void console_set_color(const std::string& color) {
#ifdef MSGH_OS_WINDOWS
	/*
	if (color == "blue") {
		system("Color 09");
	} else if (color == "red") {
		system("Color 0C");
	} else if (color == "yellow") {
		system("Color 0E");
	}
	*/
#else
	if (color == "blue") {
		std::cout << "\033[34m";
	} else if (color == "red") {
		std::cout << "\033[31m";
	} else if (color == "yellow") {
		std::cout << "\033[33m";
	}
#endif
}

inline void console_reset_color() {
#ifdef MSGH_OS_WINDOWS
	//system("Color 07");
#else
	std::cout << "\033[0m";
#endif
}

inline std::string realPath(const char* file) {
	if (file == nullptr) {
		return "Unknow file";
	}
	char* path;
#ifdef MSGH_OS_WINDOWS
	path = static_cast<char*>(malloc(512 * sizeof(char)));
	strcpy(path, file);
#else
	path = realpath(file, nullptr);
	if (path == nullptr) {
		return std::string(file);
	}
#endif
	std::string real_path(path);
	free(path);
	return real_path;
}

#ifdef MSGH_OS_WINDOWS
#undef MSGH_OS_WINDOWS
#endif
