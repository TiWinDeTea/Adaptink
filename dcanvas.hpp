#ifndef DCANVAS_HPP
#define DCANVAS_HPP

#include <QMouseEvent>
#include <QWidget>
#include <canvas.hpp>

class DCanvas: public QWidget
{
public:
	DCanvas(QWidget* parent = nullptr);
	~DCanvas();
	DCanvas(const DCanvas&) = delete;
	DCanvas& operator=(const DCanvas&) = delete;

	void request_resize(const QSize& size);

	Canvas* front;
	QWidget* background;


protected:

	void mouseDoubleClickEvent(QMouseEvent* e) {
		front->mouseDoubleClickEvent(e);
	}

	void mouseMoveEvent(QMouseEvent* e) {
		front->mouseMoveEvent(e);
	}

	void mousePressEvent(QMouseEvent* e) {
		front->mousePressEvent(e);
	}

	void mouseReleaseEvent(QMouseEvent* e) {
		front->mouseReleaseEvent(e);
	}
};

#endif // DCANVAS_HPP
