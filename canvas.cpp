#include <QPainter>
#include <iostream>

#include "canvas.hpp"

Canvas::Canvas(QWidget *parent) : QWidget(parent),
	m_repaintToSave(false),
	m_mousePos(),
	m_pixmap() {
}

Canvas::~Canvas() {
}

void Canvas::mousePressEvent(QMouseEvent* event) {
	m_mousePos = event->pos();
	drawAndSavePixmap();
	repaint();
}

void Canvas::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_pixmap);

	if (m_repaintToSave) {
		painter.setPen(QColor(255, 0, 0, 50));
		painter.setFont(QFont("Arial", 30));
		painter.drawText(QRect(m_mousePos.x(), m_mousePos.y(), width(), height()), Qt::AlignmentFlag::AlignLeft, "WOW");
		// TODO: add more interesting tools.
	}
}

void Canvas::drawAndSavePixmap() {
	m_repaintToSave = true;
	m_pixmap = QPixmap(grab());
	m_repaintToSave = false;
}
