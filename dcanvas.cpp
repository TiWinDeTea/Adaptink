#include <QWidget>
#include <canvas.hpp>

#include <dcanvas.hpp>

DCanvas::DCanvas(QWidget* parent): QWidget(parent),
	front(new Canvas(this)),
	background(new QWidget(this))
{
	front->setPalette(QPalette(Qt::GlobalColor::transparent));
	front->raise();
	background->setPalette(QPalette(Qt::GlobalColor::white));
	background->setAutoFillBackground(true);
	background->lower();
}

DCanvas::~DCanvas() {
	delete front;
	delete background;
}

void DCanvas::request_resize(const QSize& size) {
	resize(size);
	front->resize(size);
	background->resize(size);
}
