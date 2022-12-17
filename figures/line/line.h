#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Line : public Figure {
  Q_OBJECT

public:
  explicit Line(QPointF point, QObject *parent = 0);
  ~Line();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
