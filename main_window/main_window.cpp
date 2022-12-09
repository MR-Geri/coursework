#include "main_window.h"
#include "constants.h"
#include "ui_main_window.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(this, SIGNAL(changeItem(constants::Items)), ui->graphicsView, SLOT(setActiveItem(constants::Items)));

  connect(ui->buttonRhomb, SIGNAL(clicked()), this, SLOT(clickedRhomb()));
  connect(ui->buttonRectangle, SIGNAL(clicked()), this, SLOT(clickedRectangle()));
  connect(ui->buttonRectangleOval, SIGNAL(clicked()), this, SLOT(clickedRectangleOval()));
  connect(ui->buttonParallelepiped, SIGNAL(clicked()), this, SLOT(clickedParallelepiped()));
  connect(ui->buttonHexagon, SIGNAL(clicked()), this, SLOT(clickedHexagon()));
  connect(ui->buttonLine, SIGNAL(clicked()), this, SLOT(clickedLine()));
  connect(ui->buttonArrow, SIGNAL(clicked()), this, SLOT(clickedArrow()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::clickedRhomb(){ emit changeItem(constants::Rhomb); }

void MainWindow::clickedRectangle(){ emit changeItem(constants::Rectangle); }

void MainWindow::clickedRectangleOval(){ emit changeItem(constants::RectangleOval); }

void MainWindow::clickedParallelepiped(){ emit changeItem(constants::Parallelepiped); }

void MainWindow::clickedHexagon(){ emit changeItem(constants::Hexagon); }

void MainWindow::clickedLine(){ emit changeItem(constants::Line); }

void MainWindow::clickedArrow(){ emit changeItem(constants::Arrow); }

