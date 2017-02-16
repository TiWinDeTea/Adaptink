#include <QPainter>

#include "canvas.hpp"

Canvas::Canvas(QWidget *parent) :
	QWidget(parent),
	m_repaintToSave(false),
	m_mousePos(),
	m_pixmap(),
	m_color()
{
}


void Canvas::setPenColor(QColor color) {
	m_color = color;
}

// === protected ===

void Canvas::mousePressEvent(QMouseEvent* event) {
	m_mousePos = event->pos();
	draw();
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
	m_mousePos = event->pos();
	draw();
}

void Canvas::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_pixmap);

	if (m_repaintToSave) {
		// general
		painter.setPen(m_color);
		painter.setBrush(m_color);

		painter.drawEllipse(m_mousePos, 5, 5);
		//painter.setFont(QFont("Arial", 30));
		//painter.drawText(QRect(m_mousePos.x(), m_mousePos.y(), width(), height()), Qt::AlignmentFlag::AlignLeft, "WOW");
	}
}

// === private ===

void Canvas::draw() {
	m_repaintToSave = true;
	m_pixmap = QPixmap(grab());
	m_repaintToSave = false;
	repaint();
}

