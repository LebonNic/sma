#include "UnitGraphicItem.h"

UnitGraphicItem::UnitGraphicItem(const QPixmap& pixmap, Orientation orientation, QObject* parent) :
    QObject(parent), QGraphicsPixmapItem(pixmap)
{
    this->m_Orientation = orientation;
    this->m_Frame = 0;
    setCacheMode(DeviceCoordinateCache);
}
 
UnitGraphicItem::~UnitGraphicItem()
{
}
 
void UnitGraphicItem::animatePosition(const QPointF& start, const QPointF& end)
{
    // Start animate this class
    QPropertyAnimation* anim = new QPropertyAnimation(this, "pos");
 
    // 250 msecond duration animation
    anim->setDuration(250);
    // position to start animation
    anim->setStartValue(start);
    // end position of animation
    anim->setEndValue(end);
    // easing curve
    anim->setEasingCurve(QEasingCurve::Linear);
 
    // Listen animation finished signal
    QObject::connect(anim, SIGNAL(finished()), this, SLOT(animationFinished()));
    // Listen frame change
    QObject::connect(anim, SIGNAL(valueChanged(QVariant)), this, SLOT(changeFrame(QVariant)));
 
    // Start animation and delete QPropertyAnimation class on the end
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}
 
void UnitGraphicItem::animationFinished()
{
    // This slot is called when animation ends
}

void UnitGraphicItem::changeFrame(QVariant data)
{
    unsigned int index = 0;
    (this->m_Frame)++;
    switch(this->m_Orientation)
    {
        case Orientation::NORTH:
            index = 9;
            break;
        case Orientation::SOUTH:
            index = 0;
            break;
        case Orientation::EAST:
            index = 6;
            break;
        case Orientation::WEST:
            index = 3;
            break;
    }

    // Optimize by using worldview textures ?
    this->setPixmap(QPixmap("../texture/unit" + QString::number(index + (m_Frame%3)) + ".png"));
}

