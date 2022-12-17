#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Parallelepiped : public Figure {
  Q_OBJECT

public:
  explicit Parallelepiped(QPointF point, QObject *parent = 0);
  ~Parallelepiped();

private:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};
