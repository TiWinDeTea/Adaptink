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
	void on_actionQuit_triggered();

	void on_actionChangeColor_triggered();

	void on_actionToolPencil_triggered();

	void on_actionToolBrush_triggered();

	void on_actionToolLabel_triggered();

	void on_actionRubber_triggered();

	void on_actionSet_Background_color_triggered();

private:
	Ui::Adaptink* m_ui;
};

#endif // ADAPTINK_HPP
