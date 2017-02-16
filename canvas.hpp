#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QMouseEvent>
#include <QApplication>

class ScrollArea;

#include <adaptinktool.hpp>

class Canvas final : public QWidget
{
	Q_OBJECT
public:
	explicit Canvas(QWidget *parent = nullptr);
	~Canvas() = default;

	void setPaintColor(QColor color);

	void setTool(AdaptinkTool tool);

signals:

public slots:

protected:
	void mousePressEvent(QMouseEvent* event);

	void mouseMoveEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);

private:
	void updateMousePos(QMouseEvent* event);

	void draw();

	bool m_repaintToSave;

	AdaptinkTool m_tool;

	QPoint m_oldMousePos;
	QPoint m_mousePos;

	QPixmap m_pixmap;

	QColor m_color;
};

#endif // CANVAS_HPP
