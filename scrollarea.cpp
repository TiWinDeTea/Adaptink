#include <QMouseEvent>
#include <QGridLayout>

#include <canvas.hpp>
#include <scrollarea.hpp>

ScrollArea::ScrollArea(QWidget* parent) : QScrollArea(parent) {
}

#include <QDebug>
void QWidget::mouseMoveEvent(QMouseEvent* event) {
	QWidget* w = QObject::findChild<QWidget*>("canvas");
	w->resize(QSize(event->pos().x(), event->pos().y()));
	/*w->setVisible(true);
	w->show();
	w->repaint();
	w->update();*/
}
