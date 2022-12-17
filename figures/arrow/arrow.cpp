#include "arrow.h"

Arrow::Arrow(QPointF point, QObject *parent) : Figure(point, parent) {
  Q_UNUSED(point)
}

Arrow::~Arrow() {}

// Реализуем метод отрисовки
void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));

  float x, y;
  float x1 = startPoint().x(), y1 = startPoint().y();
  float x2 = endPoint().x(), y2 = endPoint().y();
  float f1x2 , f1y2;
  float lons, ugol;
  const float ostr = 0.5;        // острота стрелки

  painter->drawLine(x1, y1, x2, y2);

  x = x2 - x1;
  y = y2 - y1;

  // lons = sqrt(x*x + y*y) / 7;     // длина лепестков % от длины стрелки
  lons = 20;     // длина лепестков % от длины стрелки
  ugol = atan2(y, x);             // угол наклона линии

  //lons = 12;

  f1x2 = x2 - lons * cos(ugol - ostr);
  f1y2 = y2 - lons * sin(ugol - ostr);

  painter->drawLine(x2, y2, f1x2, f1y2);

  f1x2 = x2 - lons * cos(ugol + ostr);
  f1y2 = y2 - lons * sin(ugol + ostr);

  painter->drawLine(x2, y2, f1x2, f1y2);

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
