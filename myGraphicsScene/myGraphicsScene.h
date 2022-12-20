#pragma once

#include <QGraphicsScene>
#include <randomPoints/randomPoints.h>
#include <constants.h>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <algorithm>
#include <iostream>

#include <qnamespace.h>

#include "figures/figure/figure.h"
#include "figures/arrow/arrow.h"
#include "figures/hexagon/hexagon.h"
#include "figures/line/line.h"
#include "figures/parallelepiped/parallelepiped.h"
#include "figures/rectangle/rectangle.h"
#include "figures/rectangleOval/rectangleOval.h"
#include "figures/rhomb/rhomb.h"
#include "text/text.h"


class myGraphicsScene : public QGraphicsScene {
  Q_OBJECT
public:
  explicit myGraphicsScene(QObject *parent = nullptr);
  void setActiveItem(constants::Items item);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

  Figure *m_activeItem;

private:
  constants::Items currentItem;
  bool flag_move = false;
  QPointF offset;
};
