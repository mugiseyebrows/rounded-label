#include "roundedlabel.h"

#include <QPainter>
#include <QPainterPath>

RoundedLabel::RoundedLabel(QWidget *parent) : QWidget(parent), mBorderRadius(0)
{

}

void RoundedLabel::setPixmap(const QPixmap &pixmap)
{
    mPixmap = pixmap;
    updateGeometry();
    update();
}

void RoundedLabel::setBorderRadius(int value)
{
    mBorderRadius = value;
    update();
}

void RoundedLabel::paintEvent(QPaintEvent *event)
{
    if (mPixmap.isNull()) {
        return;
    }
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QRect r = this->rect();
    int radius = mBorderRadius;
    QPainterPath clipPath;
    clipPath.moveTo(radius, 0);
    clipPath.arcTo(r.right() - radius, 0, radius, radius, 90, -90);
    clipPath.arcTo(r.right() - radius, r.bottom() - radius, radius, radius, 0, -90);
    clipPath.arcTo(r.left(), r.bottom() - radius, radius, radius, 270, -90);
    clipPath.arcTo(r.left(), r.top(), radius, radius, 180, -90);
    clipPath.closeSubpath();
    painter.setClipPath(clipPath);
    painter.drawPixmap(QPoint(0,0),mPixmap);
}

QSize RoundedLabel::sizeHint() const
{
    return mPixmap.isNull() ? QSize(40,40) : mPixmap.size();
}
