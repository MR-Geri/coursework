#include "text.h"

TextItem::TextItem() {
  setPlainText("Текст");
  QFont f;
  f.setPointSize(20);
  f.setBold(true);
  f.setFamily("Helvetica");
  setFont(f);

  setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable |
           QGraphicsItem::ItemIsSelectable);
  setTextInteractionFlags(Qt::NoTextInteraction);
}

TextItem::~TextItem(){}

void TextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
  QGraphicsTextItem::paint(painter, option, widget);
}

void TextItem::focusOutEvent(QFocusEvent *event) {
  setTextInteractionFlags(Qt::NoTextInteraction);
  Q_UNUSED(event);
}

void TextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
  setTextInteractionFlags(Qt::TextEditorInteraction);
  Q_UNUSED(event);
}

void TextItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsTextItem::mouseReleaseEvent(event);
  Q_UNUSED(event);
}
