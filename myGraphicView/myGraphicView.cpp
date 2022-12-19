#include "myGraphicView.h"
#include "myGraphicScene/myGraphicScene.h"

MyGraphicView::MyGraphicView(QWidget *parent) : QGraphicsView(parent) {

  /* Немного поднастроим отображение виджета и его содержимого */
  this->setHorizontalScrollBarPolicy(
      Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
  this->setVerticalScrollBarPolicy(
      Qt::ScrollBarAlwaysOff); // Отключим скроллбар по вертикали
  this->setAlignment(Qt::AlignCenter); // Делаем привязку содержимого к центру
  this->setSizePolicy(
      QSizePolicy::Expanding,
      QSizePolicy::Expanding); // Растягиваем содержимое по виджету

  /* Также зададим минимальные размеры виджета
   * */
  this->setMinimumHeight(100);
  this->setMinimumWidth(100);

  scene = new myGraphicsScene(); // Инициализируем сцену для отрисовки
  this->setScene(scene); // Устанавливаем сцену в виджет

  group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
  group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов

  scene->addItem(group_1); // Добавляем первую группу в сцену
  scene->addItem(group_2); // Добавляем вторую группу в сцену

  timer = new QTimer(); // Инициализируем Таймер
  timer->setSingleShot(true);
  // Подключаем СЛОТ для отрисовки к таймеру
  connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
  timer->start(50); // Стартуем таймер на 50 миллисекунд
}

MyGraphicView::~MyGraphicView() {}

void MyGraphicView::slotAlarmTimer() {
  /* Удаляем все элементы со сцены,
   * если они есть перед новой отрисовкой
   * */
  this->deleteItemsFromGroup(group_1);
  this->deleteItemsFromGroup(group_2);

  int width = this->width(); // определяем ширину нашего виджета
  int height = this->height(); // определяем высоту нашего виджета

  /* Устанавливаем размер сцены по размеру виджета
   * Первая координата - это левый верхний угол,
   * а Вторая - это правый нижний угол
   * */
  scene->setSceneRect(0, 0, width, height);

  QPen penRed(Qt::red);     // Задаём красную кисть

  group_1->addToGroup(scene->addLine(20, 20, width - 20, 20, penRed));
  group_1->addToGroup(
      scene->addLine(width - 20, 20, width - 20, height - 20, penRed));
  group_1->addToGroup(
      scene->addLine(width - 20, height - 20, 20, height - 20, penRed));
  group_1->addToGroup(scene->addLine(20, height - 20, 20, 20, penRed));
}

/* Этим методом перехватываем событие изменения размера виджет
 * */
void MyGraphicView::resizeEvent(QResizeEvent *event) {
  timer->start(50); // Как только событие произошло стартуем таймер для отрисовки
  QGraphicsView::resizeEvent(event); // Запускаем событие родителького класса
}

/* Метод для удаления всех элементов из группы
 * */
void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group) {
  /* Перебираем все элементы сцены, и если они принадлежат группе,
   * переданной в метод, то удаляем их
   * */
  foreach (QGraphicsItem *item, scene->items(group->boundingRect())) {
    if (item->group() == group) {
      delete item;
    }
  }
}

void MyGraphicView::setActiveItem(constants::Items item){
  scene->setActiveItem(item);
}
