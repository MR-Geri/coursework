#pragma once

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include <QVector>
#include <constants.h>
#include <QFileDialog>

#include <myGraphicsView/myGraphicsView.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  // MyGraphicView graphView;

private slots:
  void clickedRhomb();
  void clickedRectangle();
  void clickedRectangleOval();
  void clickedParallelepiped();
  void clickedHexagon();
  void clickedLine();
  void clickedArrow();
  void clickedExport();
  void clickedSave();
  void clickedLoad();

signals:
  void changeItem(constants::Items item);
};
