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
	m_oldMousePos = event->pos();
	m_mousePos = event->pos();
	draw();
}

void Canvas::mouseMoveEvent(QMouseEvent* event) {
	m_oldMousePos = m_mousePos;
	m_mousePos = event->pos();
	draw();
}

void Canvas::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, m_pixmap);

	if (m_repaintToSave) {
		painter.setPen(Qt::NoPen);
		painter.setBrush(Qt::NoBrush);

		switch (m_tool) {
		case Pencil:
			painter.setPen(QPen(m_color, 5, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin));
			painter.drawLine(m_oldMousePos, m_mousePos);
			break;
		case Paintbrush:
			painter.setBrush(m_color);
			painter.drawEllipse(m_mousePos, 5, 5);
			break;
		case Label:
			painter.setPen(m_color);
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

void Canvas::draw() {
	m_repaintToSave = true;
	m_pixmap = QPixmap(grab());
	m_repaintToSave = false;
	repaint();
}

