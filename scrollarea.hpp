#ifndef SCROLLAREA_HPP
#define SCROLLAREA_HPP

#include <QScrollArea>

class QWidget;


class ScrollArea : public QScrollArea
{

public:
	ScrollArea(QWidget* parent = nullptr);
};

#endif // SCROLLAREA_HPP
