#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>
#include <algorithm>
#include <iterator>

class RectangleOval : public Figure {
  Q_OBJECT

public:
  explicit RectangleOval(QPointF point, QObject *parent = 0);
  ~RectangleOval();

  RectangleOval* clone();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
