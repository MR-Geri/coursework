#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <iostream>

#include <myGraphicScene/myGraphicScene.h>
#include "figures/rhomb/rhomb.h"

myGraphicsScene::myGraphicsScene(QObject *parent)
    : QGraphicsScene(parent), m_activeItem(nullptr) {
  currentItem = constants::Items::Hexagon;
}

void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mousePressEvent(event);

  int type = getBetween(1, 3);
  int indent = getBetween(10, 50);
  QPointF pos = event->scenePos();

  QColor color(getBetween(0, 255), getBetween(0, 255), getBetween(0, 255));

  m_activeItem = nullptr;

  switch (currentItem) {
  case constants::Rhomb:
    // m_activeItem = new QGraphicsEllipseItem(-indent, -indent, indent * 2, indent * 2);
    // static_cast<QGraphicsEllipseItem *>(m_activeItem)->setBrush(color);
    m_activeItem = new Rhomb(event->scenePos());
    m_activeItem->setPos(event->pos());
    break;
  case constants::Rectangle:
    // m_activeItem = new Rectangle(-indent, -indent, indent * 2, indent * 2);
    // static_cast<QGraphicsEllipseItem *>(m_activeItem)->setBrush(color);
    break;
  case constants::RectangleOval:
    break;
  case constants::Parallelepiped:
    break;
  case constants::Hexagon:
    break;
  case constants::Line:
    break;
  case constants::Arrow:
    break;
  }

  if (nullptr == m_activeItem) return;

  addItem(m_activeItem);
  // m_activeItem->setPos(pos);
}

void myGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mouseMoveEvent(event);

}

void myGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mouseReleaseEvent(event);

}

void myGraphicsScene::keyPressEvent(QKeyEvent *event) {
  QGraphicsScene::keyPressEvent(event);

  if (nullptr == m_activeItem)
    return;

  switch (event->key()) {
  case Qt::Key::Key_A:
    m_activeItem->moveBy(-5, 0);
    break;
  case Qt::Key::Key_S:
    m_activeItem->moveBy(0, 5);
    break;
  case Qt::Key::Key_D:
    m_activeItem->moveBy(5, 0);
    break;
  case Qt::Key::Key_W:
    m_activeItem->moveBy(0, -5);
    break;
  }
}

void myGraphicsScene::setActiveItem(constants::Items item) {
  currentItem = item;
}
