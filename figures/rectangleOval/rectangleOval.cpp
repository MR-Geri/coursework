#include "rectangleOval.h"

RectangleOval::RectangleOval(QPointF point, QObject *parent)
    : Figure(point, parent) {
  Q_UNUSED(point)
}

RectangleOval::~RectangleOval() {}

// Реализуем метод отрисовки
void RectangleOval::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));

  QPolygonF polygon;
  QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));

  if (size.x() < size.y()) {
    setEndPoint(QPointF(endPoint().x() + (size.y() - size.x()) * (endPoint().x() > startPoint().x() ? + 1 : - 1), endPoint().y()));
    QPointF size(abs(endPoint().x() - startPoint().x()), abs(endPoint().y() - startPoint().y()));
  }

  QPointF leftUp(
    startPoint().x() + (size / 2).y() * (endPoint().x() > startPoint().x() ? + 1 : - 1),
    startPoint().y()
  );
  QPointF rightUp(
    endPoint().x() - (size / 2).y() * (endPoint().x() > startPoint().x() ? + 1 : - 1),
    startPoint().y()
  );
  QPointF leftDown(
    endPoint().x() - (size / 2).y() * (endPoint().x() > startPoint().x() ? + 1 : - 1),
    endPoint().y()
  );
  QPointF rightDown(
    startPoint().x() + (size / 2).y() * (endPoint().x() > startPoint().x() ? + 1 : - 1),
    endPoint().y()
  );

  polygon << leftUp << rightUp;
  painter->drawPolygon(polygon);
  polygon.clear();
  polygon << leftDown << rightDown;
  painter->drawPolygon(polygon);

  QRectF leftEllipse(
    startPoint(),
    QPointF(startPoint().x() + size.y() * (startPoint().x() < endPoint().x() ? 1 : -1), endPoint().y())
  );
  QRectF rightEllipse(
    QPointF(endPoint().x() - size.y() * (startPoint().x() < endPoint().x() ? 1 : -1), startPoint().y()),
    endPoint()
  );
  painter->drawArc(
    rightEllipse,
    (endPoint().x() > startPoint().x() ? 270 * 16 : 90 * 16),
    (endPoint().x() > startPoint().x() ? 180 * 16 : 180 * 16)
  );
  painter->drawArc(
    leftEllipse,
    (endPoint().x() > startPoint().x() ? 90 * 16 : 270 * 16),
    (endPoint().x() > startPoint().x() ? 180 * 16 : 180 * 16)
  );

  QPointF pos = startPoint() + size / 2;
  text->setPos(QPointF(
     pos.x() - text->boundingRect().width() / 2,
     pos.y() - text->boundingRect().height() / 2
  ));

  Q_UNUSED(option)
  Q_UNUSED(widget)
}
