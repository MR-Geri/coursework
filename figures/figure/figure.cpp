#include "figure.h"
#include <iostream>

Figure::Figure(QPointF point, QObject *parent)
    : QObject(parent), QGraphicsItem() {
  this->setStartPoint(mapFromScene(point));
  this->setEndPoint(mapFromScene(point));

  connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
}

Figure::~Figure() {}

QRectF Figure::boundingRect() const {
  return QRectF(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) -
          5,
      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) -
          5,
      qAbs(endPoint().x() - startPoint().x()) + 10,
      qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb() {
  this->update(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) -
          5,
      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) -
          5,
      qAbs(endPoint().x() - startPoint().x()) + 10,
      qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point) {
  m_startPoint = mapFromScene(point);
  emit pointChanged();
}

void Figure::setEndPoint(const QPointF point) {
  m_endPoint = mapFromScene(point);
  emit pointChanged();
}

QPointF Figure::startPoint() const { return m_startPoint; }

QPointF Figure::endPoint() const { return m_endPoint; }

// void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//   QGraphicsItem::mouseMoveEvent(event);
//   std::cout << "Move";
//   this->setPos(mapToScene(event->pos()));
// }
//
// void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//   QGraphicsItem::mousePressEvent(event);
//   std::cout << "Press\n";
//   if (event->button() != Qt::LeftButton) return;
//   /* При нажатии мышью на графический элемент
//    * заменяем курсор на руку, которая держит этот элемента
//    * */
//   this->setCursor(QCursor(Qt::ClosedHandCursor));
//   // Q_UNUSED(event);
// }
//
// void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
//   QGraphicsItem::mouseReleaseEvent(event);
//   std::cout << "Release\n";
//   if (event->button() != Qt::LeftButton) return;
//   /* При отпускании мышью элемента
//    * заменяем на обычный курсор стрелку
//    * */
//   this->setCursor(QCursor(Qt::ArrowCursor));
//   // Q_UNUSED(event);
// }
