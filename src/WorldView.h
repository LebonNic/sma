#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QWheelEvent>
#include <QTimeLine>
#include "World.h"

class WorldView
    : public QGraphicsView
{
    Q_OBJECT
public:
    explicit WorldView(World *world, QWidget *parent = NULL);
	void update(void);
signals:

public slots:
    void scalingTime(qreal);
    void animFinished();
private:
    World *m_World;
    QGraphicsScene *m_WorldScene;
    int m_iScheduledScalings;
    double m_dScale;
    std::vector<QPixmap> m_GrassImage;
    std::vector<QPixmap> m_TreeImage;
    std::vector<QPixmap> m_GoldImage;
    std::vector<QPixmap> m_FoodImage;

    QPixmap WorldView::randomTexture(std::vector<QPixmap> textures);
protected:
    virtual void wheelEvent(QWheelEvent* event);
};

#endif // WORLDVIEW_H
