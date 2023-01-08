#include <iostream>
#include "include/Percolation.h"
#include "include/QuickUnion.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QWindow>
#include <QBoxLayout>
#include <QPushButton>

#include <QPainter>

#include "MyWidget.h"



int main(int argc, char **argv)
{

 QApplication app (argc, argv);

 Percolation p(8);
 MyWidget *myw = new MyWidget(&p);

  QWidget *window = new QWidget;
  QPushButton *button2 = new QPushButton("Two");
  QPushButton *button3 = new QPushButton("Three");
  QPushButton *button4 = new QPushButton("Four");
  QPushButton *button5 = new QPushButton("Five");

  QVBoxLayout *layout = new QVBoxLayout(window);
  layout->addWidget(myw);
  layout->addWidget(button2);
  layout->addWidget(button3);
  layout->addWidget(button4);
  layout->addWidget(button5);

  window->show();

 //QPushButton button ("Hello world !");
 //button.show();
 return app.exec();
}









  
