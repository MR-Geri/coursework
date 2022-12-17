#pragma once

#include "figures/figure/figure.h"
#include <QGraphicsScene>
#include <randomPoints/randomPoints.h>
#include <constants.h>

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
