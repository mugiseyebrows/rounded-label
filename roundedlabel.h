#ifndef ROUNDEDLABEL_H
#define ROUNDEDLABEL_H

#include <QWidget>

class RoundedLabel : public QWidget
{
    Q_OBJECT
public:
    explicit RoundedLabel(QWidget *parent = nullptr);
    void setPixmap(const QPixmap& pixmap);
    void setBorderRadius(int value);
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);
    int mBorderRadius;
    QPixmap mPixmap;
};

#endif // ROUNDEDLABEL_H
