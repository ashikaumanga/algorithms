#include <QWidget>
#include <QPainter>
#include "Percolation.h"
#include <QMouseEvent>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(Percolation *percolation, QWidget *parent = nullptr);
    virtual ~MyWidget();
private:
    Percolation *percolation; 
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

};