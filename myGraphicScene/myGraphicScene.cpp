#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <iostream>

#include <myGraphicScene/myGraphicScene.h>

myGraphicsScene::myGraphicsScene(QObject *parent)
    : QGraphicsScene(parent), m_activeItem(nullptr) {
  currentItem = Items::Hexagon;
}

void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mousePressEvent(event);

  int type = getBetween(1, 3);
  int radius = getBetween(10, 50);
  QPointF pos = event->scenePos();

  QColor color(getBetween(0, 255), getBetween(0, 255), getBetween(0, 255));

  m_activeItem = nullptr;
  std::cout << currentItem << "\n";


  // switch (currentItem) {
  // case Rhomb:
  //   // m_activeItem = new QGraphicsEllipseItem(-radius, -radius, radius * 2, radius * 2);
  //   // static_cast<QGraphicsEllipseItem *>(m_activeItem)->setBrush(color);
  //   std::cout << "Rhomb\n";
  //   break;
  // case Rectangle:
  //   // m_activeItem = new QGraphicsRectItem(-radius, -radius, radius * 2, radius * 2);
  //   // static_cast<QGraphicsEllipseItem *>(m_activeItem)->setBrush(color);
  //   break;
  // case RectangleOval:
  //   break;
  // case Parallelepiped:
  //   break;
  // case Hexagon:
  //   break;
  // case Line:
  //   break;
  // case Arrow:
  //   break;
  // }

  if (nullptr == m_activeItem) return;

  addItem(m_activeItem);
  m_activeItem->setPos(pos);
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

void myGraphicsScene::setActiveItem(Items item) {
  currentItem = item;
  std::cout << "!" << item << "\n";
}
