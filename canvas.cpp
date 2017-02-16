#include <QDebug>
#include <QPainter>

#include <canvas.hpp>

Canvas::Canvas(QWidget *parent) :
	QWidget(parent),
	m_repaintToSave(false),
	m_tool(Pencil),
	m_oldMousePos(),
	m_mousePos(),
	m_pixmap(),
	m_color()
{
}


void Canvas::setPaintColor(QColor color) {
	m_color = color;
}

void Canvas::setTool(AdaptinkTool tool) {
	m_tool = tool;
}

// === protected ===

void Canvas::mousePressEvent(QMouseEvent* event) {
	updateMousePos(event);
	m_oldMousePos = m_mousePos;
	draw();
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
	updateMousePos(event);
	draw();
}

void Canvas::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_pixmap);

	if (m_repaintToSave) {
		// general
		painter.setPen(m_color);
		painter.setBrush(m_color);

		switch (m_tool) {
		case Pencil:
			painter.drawLine(m_oldMousePos, m_mousePos);
			break;
		case Paintbrush:
			painter.drawEllipse(m_mousePos, 5, 5);
			break;
		case Label:
			painter.setFont(QFont("Arial", 30));
			painter.drawText(QRect(m_mousePos.x(), m_mousePos.y(), width(), height()), Qt::AlignmentFlag::AlignLeft, "WOW");
			break;
		default:
			qDebug() << "Unexpected default case reached.";
			break;
		}
	}
}

// === private ===

void Canvas::updateMousePos(QMouseEvent* event) {
	m_oldMousePos = m_mousePos;
	m_mousePos = event->pos();
}

void Canvas::draw() {
	m_repaintToSave = true;
	m_pixmap = QPixmap(grab());
	m_repaintToSave = false;
	repaint();
}

