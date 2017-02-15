#ifndef ADAPTINK_HPP
#define ADAPTINK_HPP

#include <QMainWindow>

namespace Ui {
class Adaptink;
}

class Adaptink : public QMainWindow {
	Q_OBJECT

public:
	explicit Adaptink(QWidget *parent = 0);
	~Adaptink();

private:
	Ui::Adaptink *ui;
};

#endif // ADAPTINK_HPP
