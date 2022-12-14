#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Rectangle : public Figure {
  Q_OBJECT

public:
  explicit Rectangle(QPointF point, QObject *parent = 0);
  ~Rectangle();

  Rectangle* clone();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
