#pragma once

#include <QGraphicsScene>
#include <randomPoints/randomPoints.h>
#include <constants.h>

class myGraphicsScene : public QGraphicsScene {
  Q_OBJECT
public:
  explicit myGraphicsScene(QObject *parent = nullptr);
  void setActiveItem(Items item);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

  QGraphicsItem *m_activeItem;

private:
  Items currentItem;
  int TcurrentItem;
};
