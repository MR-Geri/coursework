#pragma once

#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>

#include <myGraphicsScene/myGraphicsScene.h>
#include <qgraphicsitem.h>
#include <constants.h>

// Расширяем класс QGraphicsView
class myGraphicsView : public QGraphicsView {
  Q_OBJECT public : explicit myGraphicsView(QWidget *parent = 0);
  ~myGraphicsView();
signals:
private slots:
  void slotAlarmTimer(); /* слот для обработчика переполнения
                          * таймера в нём будет производиться
                          * перерисовка виджета
                          * */
public:
  myGraphicsScene *scene; // Объявляем сцену для отрисовки

private:
  QGraphicsItemGroup *group_1; // Объявляем первую группу элементов
  QGraphicsItemGroup *group_2; // Объявляем вторую группу элементов

  /* Таймер для задержки отрисовки.
   * Дело в том, что при создании окна и виджета
   * необходимо некоторое время, чтобы родительский слой
   * развернулся, чтобы принимать от него адекватные параметры
   * ширины и высоты
   * */
  QTimer *timer;

private:
  /* Перегружаем событие изменения размера окна,
   * чтобы перехватывать его
   * */
  void resizeEvent(QResizeEvent *event);
  /* Метод для удаления всех элементов
   * из группы элементов
   * */
  void deleteItemsFromGroup(QGraphicsItemGroup *group_1);

public slots:
  void setActiveItem(constants::Items item);
};
