#pragma once

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>
#include <qgraphicsitem.h>

#include "text/text.h"

class Figure : public QObject, public QGraphicsItem {
  Q_OBJECT
  // Свойство стартовой точки, относительно которой отрисовываем фигуру
  Q_PROPERTY(QPointF startPoint READ startPoint WRITE setStartPoint NOTIFY pointChanged)
  // Свойство конечно точки, до куда отрисовываем фигуру
  Q_PROPERTY(QPointF endPoint READ endPoint WRITE setEndPoint NOTIFY pointChanged)

public:
  TextItem *text;

  explicit Figure(QPointF point, QObject *parent = 0);
  ~Figure();

  QPointF startPoint() const; // Стартовая точка
  QPointF endPoint() const;   // Конечная точка

  void setStartPoint(const QPointF point); // Установка стартовой точки
  void setEndPoint(const QPointF point); // Установка конечной точки

  virtual Figure* clone() = 0;

  // void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  // void mousePressEvent(QGraphicsSceneMouseEvent *event);
  // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
  void pointChanged(); // Сигнал об изменении точки

private:
  QPointF m_startPoint; // Стартовая точка
  QPointF m_endPoint;   // Конечная точка

  QRectF boundingRect() const; // Область, в которой содержится фигура

public slots:
  void updateRomb(); // Слот обновления области, в которой содержится фигура
};
