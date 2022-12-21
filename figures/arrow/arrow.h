#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <cmath>

class Arrow : public Figure {
  Q_OBJECT

public:
  explicit Arrow(QPointF point, QObject *parent = 0);
  ~Arrow();

  Arrow* clone();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
