#include "rectangle.h"

Rectangle::Rectangle(QObject *parent) : QObject(parent), QGraphicsItem() {}

Rectangle::~Rectangle() {}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  this->setPos(mapToScene(event->pos()));
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  // this->setCursor(QCursor(Qt::ClosedHandCursor));
  // Q_UNUSED(event);
}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  // this->setCursor(QCursor(Qt::ArrowCursor));
  // Q_UNUSED(event);
}
