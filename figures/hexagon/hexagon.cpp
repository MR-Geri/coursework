#include "hexagon.h"

Hexagon::Hexagon(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Hexagon::~Hexagon() {}

// Реализуем метод отрисовки
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));

  QPolygonF polygon;
  QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));

  if (size.x() < size.y()) {
    setEndPoint(QPointF(endPoint().x() + (size.y() - size.x()) * (endPoint().x() > startPoint().x() ? + 1 : - 1), endPoint().y()));
    QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));
  }

  QPointF leftUp(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) + (size / 2).y(),
      startPoint().y() < endPoint().y() ? startPoint().y() : endPoint().y()
    );
  QPointF rightUp(
      (endPoint().x() > startPoint().x() ? endPoint().x() : startPoint().x())- (size / 2).y(),
      startPoint().y() < endPoint().y() ? startPoint().y() : endPoint().y()
    );
  QPointF leftDown(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) + (size / 2).y(),
      startPoint().y() > endPoint().y() ? startPoint().y() : endPoint().y()
    );
  QPointF rightDown(
      (endPoint().x() > startPoint().x() ? endPoint().x() : startPoint().x()) - (size / 2).y(),
      startPoint().y() > endPoint().y() ? startPoint().y() : endPoint().y()
    );

  QPointF left(
      endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
      ( startPoint().y() > endPoint().y() ? startPoint().y() : endPoint().y() ) - (size / 2).y()
    );
  QPointF right(
      endPoint().x() > startPoint().x() ? endPoint().x() : startPoint().x(),
      ( startPoint().y() > endPoint().y() ? startPoint().y() : endPoint().y() ) - (size / 2).y()
    );


  polygon << leftUp << rightUp << right << rightDown << leftDown << left;
  painter->drawPolygon(polygon);

  QPointF pos = startPoint() + size / 2;
  text->setPos(QPointF(
     pos.x() - text->boundingRect().width() / 2,
     pos.y() - text->boundingRect().height() / 2
  ));

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

Hexagon* Hexagon::clone(){
  Hexagon *out = new Hexagon(startPoint());
  out->setEndPoint(endPoint());
  out->text = new TextItem();
  out->text->setPlainText(this->text->toPlainText());
  return out;
}
