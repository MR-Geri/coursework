#include "parallelepiped.h"

Parallelepiped::Parallelepiped(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Parallelepiped::~Parallelepiped() {}

// Реализуем метод отрисовки
void Parallelepiped::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));

  QPolygonF polygon;
  QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));

  QPointF leftUp(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) + (size / 2).y(),
      startPoint().y() < endPoint().y() ? startPoint().y() : endPoint().y()
  );
  QPointF rightUp(
      endPoint().x() > startPoint().x() ? endPoint().x() : startPoint().x(),
      startPoint().y() < endPoint().y() ? startPoint().y() : endPoint().y()
  );
  QPointF leftDown(
      endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
      startPoint().y() > endPoint().y() ? startPoint().y() : endPoint().y()
  );
  QPointF rightDown(
      (endPoint().x() > startPoint().x() ? endPoint().x() : startPoint().x()) - (size / 2).y(),
      startPoint().y() > endPoint().y() ? startPoint().y() : endPoint().y()
  );

  polygon << leftUp << rightUp << rightDown << leftDown;
  painter->drawPolygon(polygon);

  QPointF pos = startPoint() + size / 2;
  text->setPos(QPointF(
     pos.x() - text->boundingRect().width() / 2,
     pos.y() - text->boundingRect().height() / 2
  ));

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

Parallelepiped* Parallelepiped::clone(){
  Parallelepiped *out = new Parallelepiped(startPoint());
  out->setEndPoint(endPoint());
  out->text = new TextItem();
  out->text->setPlainText(this->text->toPlainText());
  return out;
}
