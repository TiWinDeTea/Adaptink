#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QWidget>
#include <QMouseEvent>

class Canvas : public QWidget
{
	Q_OBJECT
public:
	explicit Canvas(QWidget *parent = nullptr);
	virtual ~Canvas();

signals:

public slots:

protected:
	void mousePressEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);

private:
	void drawAndSavePixmap();

	bool m_repaintToSave;

	QPoint m_mousePos;

	QPixmap m_pixmap;
};

#endif // CANVAS_HPP
