#include "myGraphicsScene/myGraphicsScene.h"

myGraphicsScene::myGraphicsScene(QObject *parent)
    : QGraphicsScene(parent), m_activeItem(nullptr) {
  currentItem = constants::Items::Hexagon;
}

void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mousePressEvent(event);

  int mouse_x = event->pos().x(), mouse_y = event->pos().y();
  flag_move = false;

  QList<QGraphicsItem *> all = items();
  for (int i = 0; i < all.size(); i++) {
    QGraphicsItem *gi = all[i];
    if (dynamic_cast<Figure *>(gi) != nullptr) {
      Figure *fig = dynamic_cast<Figure *>(gi);
      int start_x = std::min(fig->startPoint().x(), fig->endPoint().x());
      int start_y = std::min(fig->startPoint().y(), fig->endPoint().y());

      int end_x = std::max(fig->startPoint().x(), fig->endPoint().x());
      int end_y = std::max(fig->startPoint().y(), fig->endPoint().y());

      if (end_x >= mouse_x - 5 && mouse_x >= start_x - 5 && end_y >= mouse_y - 5 &&
          mouse_y >= start_y - 5) {
        flag_move = true;
        offset = event->scenePos();
        m_activeItem = fig;
        break;
      }
    }
  }

  if (flag_move) {
    if (event->button() == Qt::RightButton) {
      delete m_activeItem->text;
      delete m_activeItem;
      this->update(QRectF(0, 0, this->width(), this->height()));
      return;
    }
    if (flag_ctrl && copy_active_item == nullptr && flag_move) {
      copy_active_item = m_activeItem->clone();
      copy_active_item->setStartPoint(copy_active_item->startPoint() + QPointF(10, 10));
      copy_active_item->setEndPoint(copy_active_item->endPoint() + QPointF(10, 10));
      addItem(copy_active_item);
      if (copy_active_item->text != nullptr)
        addItem(copy_active_item->text);
      m_activeItem = copy_active_item;
    }
  } else {
    switch (currentItem) {
    case constants::Rhomb:
      m_activeItem = new Rhomb(event->scenePos());
      addItem(m_activeItem);
      currentItem = constants::None;
      m_activeItem->text = new TextItem();
      addItem(m_activeItem->text);
      break;
    case constants::Rectangle:
      m_activeItem = new Rectangle(event->scenePos());
      addItem(m_activeItem);
      currentItem = constants::None;
      m_activeItem->text = new TextItem();
      addItem(m_activeItem->text);
      break;
    case constants::RectangleOval:
      m_activeItem = new RectangleOval(event->scenePos());
      addItem(m_activeItem);
      currentItem = constants::None;
      m_activeItem->text = new TextItem();
      addItem(m_activeItem->text);
      break;
    case constants::Parallelepiped:
      m_activeItem = new Parallelepiped(event->scenePos());
      addItem(m_activeItem);
      currentItem = constants::None;
      m_activeItem->text = new TextItem();
      addItem(m_activeItem->text);
      break;
    case constants::Hexagon:
      m_activeItem = new Hexagon(event->scenePos());
      addItem(m_activeItem);
      currentItem = constants::None;
      m_activeItem->text = new TextItem();
      addItem(m_activeItem->text);
      break;
    case constants::Line:
      m_activeItem = new Line(event->scenePos());
      m_activeItem->text = nullptr;
      addItem(m_activeItem);
      currentItem = constants::None;
      break;
    case constants::Arrow:
      m_activeItem = new Arrow(event->scenePos());
      m_activeItem->text = nullptr;
      addItem(m_activeItem);
      currentItem = constants::None;
      break;
    case constants::None:
      m_activeItem = nullptr;
      break;
    }
  }
}

void myGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mouseMoveEvent(event);

  if (m_activeItem != nullptr) {
    if (flag_move) {
      QPointF start = m_activeItem->startPoint(),
              end = m_activeItem->endPoint();
      QPointF cursor = event->scenePos();
      m_activeItem->setStartPoint(cursor - (end - start) / 2);
      m_activeItem->setEndPoint(cursor + (end - start) / 2);
    } else {
      m_activeItem->setEndPoint(event->scenePos());
    }
    if (m_activeItem->text != nullptr)
      m_activeItem->text->setTextInteractionFlags(Qt::NoTextInteraction);
  }
  this->update(QRectF(0, 0, this->width(), this->height()));
}

void myGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mouseReleaseEvent(event);
  m_activeItem = nullptr;
  copy_active_item = nullptr;
}

void myGraphicsScene::keyPressEvent(QKeyEvent *event) {
  QGraphicsScene::keyPressEvent(event);
  if (event->key() == Qt::Key_Control) {
    flag_ctrl = true;
  }
}

void myGraphicsScene::keyReleaseEvent(QKeyEvent *event) {
  QGraphicsScene::keyPressEvent(event);
  if (event->key() == Qt::Key_Control) {
    flag_ctrl = false;
  }
}

void myGraphicsScene::setActiveItem(constants::Items item) {
  currentItem = item;
}
