#include "MyWidget.h"

#include <QList>
#include <QRect>
#include <QColor>
#include <iostream>

MyWidget::MyWidget(Percolation *percolation, QWidget *parent) : QWidget(parent)
{
    // Initialize the widget here
    //MyWidget(Percolation *percolation, QWidget *parent = nullptr);
    this->percolation = percolation;
    this->setStyleSheet("background-color: #8181b1;");
}

MyWidget::~MyWidget()
{
    // Clean up any resources here
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    this->setStyleSheet("background-color: #8181b1;");
    QPainter painter(this);
    painter.setPen(QPen(Qt::white, 1));
    
    QList<QRect> rects;
    int w=20;
    for (int r=0;r < this->percolation->gridSize(); r++) {
        for (int c=0; c < this->percolation->gridSize(); c++) {
            QRect rect(1+(c*w),1+(r*w),w,w);
            rects.append(rect);
            if (this->percolation->isOpen(r,c)) {
                painter.fillRect(1+(c*w),1+(r*w),w,w, QColor(0, 255, 0, 127));
            }
        }
    }
    
    painter.drawRects(rects);
    
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        
        int x=1+event->x();
        int y=1+event->y();
        int r=y/20;
        int c=x/20;
        if (r>=this->percolation->gridSize()) return;
        if (c>=this->percolation->gridSize()) return;
        if (!this->percolation->isOpen(r,c)) {
             this->percolation->open(r,c);
        }
        
        std::cout << "open ("<<r<< ","<<c<<")"<< this->percolation->isOpen(r,c) << std::endl;
        std::cout << "isFull ("<<r<< ","<<c<<")"<< this->percolation->isFull(r,c) << std::endl;
        std::cout << "percolate " << this->percolation->percolates()<< std::endl;
        std::cout << "----- " << std::endl;
        this->update();
    }
}

