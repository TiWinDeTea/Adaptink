#include <QPainter>

#include "canvas.hpp"

Canvas::Canvas(QWidget *parent) : QWidget(parent), m_mouseX(), m_mouseY() {

}

void Canvas::mousePressEvent(QMouseEvent* event) {
	m_mouseX = event->x();
	m_mouseY = event->y();
	repaint(); // ou 'update()' ?
}

void Canvas::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setPen(Qt::red);
	painter.setFont(QFont("Arial", 30));
	painter.drawText(QRect(m_mouseX, m_mouseY, width(), height()), Qt::AlignmentFlag::AlignLeft, "WOW");
	// TODO: add more interesting tools.
}

