#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QMouseEvent>

class Canvas : public QWidget
{
	Q_OBJECT
public:
	explicit Canvas(QWidget *parent = nullptr);

signals:

public slots:

protected:
	void mousePressEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);

private:
	int m_mouseX;
	int m_mouseY;

};

#endif // CANVAS_HPP
