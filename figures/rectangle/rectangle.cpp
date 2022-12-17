#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Rectangle::~Rectangle() {}

// Реализуем метод отрисовки
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));
  QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));

  QRectF rect(
    endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
    endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
    qAbs(endPoint().x() - startPoint().x()),
    qAbs(endPoint().y() - startPoint().y())
  );
  painter->drawRect(rect);

  QPointF pos = startPoint() + size / 2;
  text->setPos(QPointF(
     pos.x() - text->boundingRect().width() / 2,
     pos.y() - text->boundingRect().height() / 2
  ));


  Q_UNUSED(option)
  Q_UNUSED(widget)
}
