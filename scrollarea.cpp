#include <QMouseEvent>
#include <QGridLayout>

#include <dcanvas.hpp>
#include <scrollarea.hpp>

ScrollArea::ScrollArea(QWidget* parent) : QScrollArea(parent) {
}

#include <QDebug>
void QWidget::mouseMoveEvent(QMouseEvent* event) {
	QObject::findChild<DCanvas*>("dcanvas")
				 ->request_resize(QSize(event->pos().x(), event->pos().y()));
	/*w->setVisible(true);
	w->show();
	w->repaint();
	w->update();*/
}
