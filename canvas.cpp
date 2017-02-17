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
	m_color(),
	m_tool_size(5, 5)
{
}


void Canvas::setPaintColor(QColor color) {
	m_color = color;
}

void Canvas::setTool(AdaptinkTool tool) {
	m_tool = tool;
}

void Canvas::setToolSize(int size) {
	m_tool_size.setHeight(size);
	m_tool_size.setWidth(size);
}

void Canvas::setPixmap(QPixmap pixmap) {
	m_pixmap = pixmap;
}

QPixmap Canvas::getPixmap() {
	return m_pixmap;
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
		QPoint brush_size(m_tool_size.width(), m_tool_size.height());

		painter.setPen(Qt::NoPen);
		painter.setBrush(Qt::NoBrush);

		switch (m_tool) {
		case Pencil:
			painter.setBrush(m_color);
			painter.drawEllipse(m_mousePos - brush_size / 4, brush_size.x(), brush_size.y());
			painter.setPen(QPen(m_color, brush_size.x() * 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
			painter.drawLine(m_oldMousePos - brush_size / 4, m_mousePos - brush_size / 4);
			break;
		case Paintbrush:
			painter.setBrush(m_color);
			painter.drawEllipse(m_mousePos - brush_size / 4, brush_size.x(), brush_size.y());
			painter.setPen(QPen(m_color, brush_size.x() * 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
			painter.drawLine(m_oldMousePos - brush_size / 4, m_mousePos - brush_size / 4);
			break;
		case Label:
			painter.setPen(m_color);
			painter.setFont(QFont("Arial", m_tool_size.height()));
			painter.drawText(QRect(m_mousePos.x(), m_mousePos.y(), width(), height()), Qt::AlignmentFlag::AlignLeft, "WOW");
			break;
		case Rubber:
			painter.setBrush(Qt::GlobalColor::transparent);
			painter.setCompositionMode(QPainter::CompositionMode_Clear);
			painter.drawRect(QRect(m_mousePos - brush_size / 2, m_mousePos + brush_size / 2));
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

