#pragma once

#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include "Unit.h"

class UnitGraphicItem: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    UnitGraphicItem(const QPixmap& pixmap, Orientation orientation = Orientation::SOUTH, QObject* parent = 0);
    ~UnitGraphicItem();
 
    // Animate position of this class
    void animatePosition(const QPointF& start, const QPointF& end);
 
public slots:
    void animationFinished();
    void changeFrame(QVariant data);
private:
    Orientation m_Orientation;
    unsigned int m_Frame;
};

