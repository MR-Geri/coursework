#include "main_window.h"
#include "constants.h"
#include "ui_main_window.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <iostream>
#include <qlist.h>


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
  connect(ui->buttonExport, SIGNAL(clicked()), this, SLOT(clickedExport()));
  connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(clickedSave()));
  connect(ui->buttonLoad, SIGNAL(clicked()), this, SLOT(clickedLoad()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::clickedRhomb(){ emit changeItem(constants::Rhomb); }

void MainWindow::clickedRectangle(){ emit changeItem(constants::Rectangle); }

void MainWindow::clickedRectangleOval(){ emit changeItem(constants::RectangleOval); }

void MainWindow::clickedParallelepiped(){ emit changeItem(constants::Parallelepiped); }

void MainWindow::clickedHexagon(){ emit changeItem(constants::Hexagon); }

void MainWindow::clickedLine(){ emit changeItem(constants::Line); }

void MainWindow::clickedArrow(){ emit changeItem(constants::Arrow); }

void MainWindow::clickedExport() {
  QString fileName = QFileDialog::getSaveFileName(
      this, "Save image", QCoreApplication::applicationDirPath(),
      "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)");
  if (!fileName.isNull()) {
    QPixmap pixMap = this->ui->graphicsView->grab();
    pixMap.save(fileName);
  }
}

void MainWindow::clickedSave(){
  std::cout << "SAVE\n";
  QJsonArray figures;
  QList<QGraphicsItem *> all = this->ui->graphicsView->scene->items();
  for (int i = 0; i < all.size(); i++) {
    QGraphicsItem *obj = all[i];
    if (dynamic_cast<Figure *>(obj) != nullptr) {
      Figure *fig = dynamic_cast<Figure *>(obj);
      QJsonObject jsonFigure;
      if (dynamic_cast<Arrow *>(obj) != nullptr) {
        jsonFigure["type"] = 0;
      } else if (dynamic_cast<Hexagon *>(obj) != nullptr) {
        jsonFigure["type"] = 1;
      } else if (dynamic_cast<Line *>(obj) != nullptr) {
        jsonFigure["type"] = 2;
      } else if (dynamic_cast<Parallelepiped *>(obj) != nullptr) {
        jsonFigure["type"] = 3;
      } else if (dynamic_cast<Rectangle *>(obj) != nullptr) {
        jsonFigure["type"] = 4;
      } else if (dynamic_cast<RectangleOval *>(obj) != nullptr) {
        jsonFigure["type"] = 5;
      } else if (dynamic_cast<Rhomb *>(obj) != nullptr) {
        jsonFigure["type"] = 6;
      }
      jsonFigure["start_x"] = fig->startPoint().x();
      jsonFigure["start_y"] = fig->startPoint().y();
      jsonFigure["end_x"] = fig->endPoint().x();
      jsonFigure["end_y"] = fig->endPoint().y();
      jsonFigure["text"] = (fig->text != nullptr) ? fig->text->toPlainText() : "";
      figures.append(jsonFigure);
    }
  }
  QJsonDocument document(figures);
  QByteArray bytes = document.toJson(QJsonDocument::Indented);

  QString fileName = QFileDialog::getSaveFileName(
      this, "Save base", QCoreApplication::applicationDirPath(),
      "") + ".json";
  if (!fileName.isNull()) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
      QTextStream iStream(&file);
      iStream.setCodec("utf-8");
      iStream << bytes;
      file.close();
    } else {
      std::cout << "file open failed" << std::endl;
    }
  }

}

void MainWindow::clickedLoad() {
  std::cout << "LOAD\n";
  QString fileName = QFileDialog::getOpenFileName(
      this, "Load base", QCoreApplication::applicationDirPath(),
      "");
  if (!fileName.isNull()) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
      QByteArray bytes = file.readAll();
      file.close();

      QJsonParseError jsonError;
      QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
      if (jsonError.error != QJsonParseError::NoError) {
        std::cout << "fromJson failed: " << jsonError.errorString().toStdString() << std::endl;
        return;
      }
      if (document.isArray()) {
        QJsonArray jsonArr = document.array();
        this->ui->graphicsView->scene->clear();
        for (int i = 0; i < jsonArr.count(); ++i) {
          QJsonObject jsonObj = jsonArr.at(i).toObject();
          int type = jsonObj.take("type").toInt();
          int start_x = jsonObj.take("start_x").toInt();
          int start_y = jsonObj.take("start_y").toInt();
          int end_x = jsonObj.take("end_x").toInt();
          int end_y = jsonObj.take("end_y").toInt();
          QString text = jsonObj.take("text").toString();
          std::cout << text.toStdString() << "\n";
          Figure* figure;

          switch (type){
            case 0:
              figure = new Arrow(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              this->ui->graphicsView->scene->addItem(figure);
              break;
            case 1:
              figure = new Hexagon(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              figure->text = new TextItem();
              figure->text->setPlainText(text);
              this->ui->graphicsView->scene->addItem(figure);
              this->ui->graphicsView->scene->addItem(figure->text);
              break;
            case 2:
              figure = new Line(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              this->ui->graphicsView->scene->addItem(figure);
              break;
            case 3:
              figure = new Parallelepiped(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              figure->text = new TextItem();
              figure->text->setPlainText(text);
              this->ui->graphicsView->scene->addItem(figure);
              this->ui->graphicsView->scene->addItem(figure->text);
              break;
            case 4:
              figure = new Rectangle(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              figure->text = new TextItem();
              figure->text->setPlainText(text);
              this->ui->graphicsView->scene->addItem(figure);
              this->ui->graphicsView->scene->addItem(figure->text);
              break;
            case 5:
              figure = new RectangleOval(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              figure->text = new TextItem();
              figure->text->setPlainText(text);
              this->ui->graphicsView->scene->addItem(figure);
              this->ui->graphicsView->scene->addItem(figure->text);
              break;
            case 6:
              figure = new Rhomb(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              figure->text = new TextItem();
              figure->text->setPlainText(text);
              this->ui->graphicsView->scene->addItem(figure);
              this->ui->graphicsView->scene->addItem(figure->text);
              break;
          }
        }
      }
    }
  }
}
