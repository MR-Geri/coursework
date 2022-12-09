#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Rhomb : public Figure {
  Q_OBJECT

public:
  explicit Rhomb(QPointF point, QObject *parent = 0);
  ~Rhomb();

private:
  // Для Ромба реализуем только саму отрисовку
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
