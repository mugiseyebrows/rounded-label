#include <QApplication>
#include <QVBoxLayout>
#include "roundedlabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString image_path = ":/images/photo.png";

    RoundedLabel* label = new RoundedLabel();
    label->setPixmap(QPixmap(image_path).scaled(40,40));
    label->setBorderRadius(5);

    QWidget widget;
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label, 0, Qt::AlignCenter);
    widget.setLayout(layout);
    widget.setStyleSheet("background : rgb(42,45,49); border-radius : 2px; border : 2px; border-color : (90,92,95);");
    widget.show();
    widget.setGeometry(QRect(widget.pos(), QSize(200,100)));

    return a.exec();
}
