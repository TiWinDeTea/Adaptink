#ifndef ADAPTINK_HPP
#define ADAPTINK_HPP

#include <QMainWindow>

#include <canvas.hpp>

namespace Ui {
class Adaptink;
}

class Adaptink : public QMainWindow {
	Q_OBJECT

public:
	explicit Adaptink(QWidget *parent = nullptr);
	Adaptink(const Adaptink&) = delete;
	Adaptink(Adaptink&&) = delete;
	Adaptink& operator=(const Adaptink&) = delete;

	~Adaptink();

private slots:
	void on_actionChangePen_triggered();

	void on_actionQuit_triggered();

	void on_actionChangeColor_triggered();

private:
	Ui::Adaptink* m_ui;
};

#endif // ADAPTINK_HPP
