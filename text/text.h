#pragma once

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>

class TextItem : public QGraphicsTextItem {
public:
  TextItem();
  ~TextItem();
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget = NULL);

protected:
  void focusOutEvent(QFocusEvent *event);

  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};
