#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QMouseEvent>

class Canvas final : public QWidget
{
	Q_OBJECT
public:
	explicit Canvas(QWidget *parent = nullptr);
	~Canvas();

	void setPenColor(QColor color);

signals:

public slots:

protected:
	void mousePressEvent(QMouseEvent* event);

	void mouseMoveEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);

private:
	void draw();

	bool m_repaintToSave;

	QPoint m_mousePos;

	QPixmap m_pixmap;

	QColor m_color;
};

#endif // CANVAS_HPP
