#pragma once

#include <QCursor>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

class Rectangle : public QObject, public QGraphicsItem {
  Q_OBJECT
public:
  explicit Rectangle(QObject *parent = 0);
  ~Rectangle();

signals:

private:
  QRectF boundingRect() const;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};
