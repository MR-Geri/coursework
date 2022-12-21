#include "line.h"

Line::Line(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Line::~Line() {}

// Реализуем метод отрисовки
void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));

  painter->drawLine(startPoint(), endPoint());

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

Line* Line::clone(){
  Line *out = new Line(startPoint());
  out->setEndPoint(endPoint());
  out->text = nullptr;
  return out;
}
