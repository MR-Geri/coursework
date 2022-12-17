#include "rhomb.h"
#include <QPainter>

Rhomb::Rhomb(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Rhomb::~Rhomb() {}

// Реализуем метод отрисовки
void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setPen(QPen(Qt::white, 2));
  QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));
  QPolygonF polygon;

  polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                         abs((endPoint().x() - startPoint().x())/2), startPoint().y())
              << QPointF(endPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                         abs((endPoint().y() - startPoint().y())/2))
              << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                         abs((endPoint().x() - startPoint().x())/2), endPoint().y())
              << QPointF(startPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                         abs((endPoint().y() - startPoint().y())/2));
  painter->drawPolygon(polygon);

  QPointF pos = startPoint() + size / 2;
  text->setPos(QPointF(
     pos.x() - text->boundingRect().width() / 2,
     pos.y() - text->boundingRect().height() / 2
  ));

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
