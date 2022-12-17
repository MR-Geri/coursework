#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Hexagon : public Figure {
  Q_OBJECT

public:
  explicit Hexagon(QPointF point, QObject *parent = 0);
  ~Hexagon();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
