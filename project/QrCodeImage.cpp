#include "QrCodeImage.h"
#include <QPainter>
#include <QrCode.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

namespace qrcodegen {
QrCodeImage::QrCodeImage(QQuickItem *parent)
    : QQuickPaintedItem(parent) {
    mImage = generateImage();
}

void QrCodeImage::paint(QPainter *painter) {
    auto image = mImage.scaled(boundingRect().size().toSize(),
                               Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    auto topLeftPoint = boundingRect().topLeft();
    if(boundingRect().size().toSize() != image.size()) {
        topLeftPoint.setX(topLeftPoint.x() + (boundingRect().size().width() - image.size().width())/2);
        topLeftPoint.setY(topLeftPoint.y() + (boundingRect().size().height() - image.size().height())/2);
    }
    painter->fillRect(boundingRect(),Qt::white);
    painter->drawImage(topLeftPoint, image);
}

QImage QrCodeImage::generateImage() const {
    QString jsonData;
    auto rect = boundingRect();
    if(rect.isEmpty()) {
        rect.setSize(QSizeF(420,420));
    }
    QrCode qrcode = QrCode::encodeText(text(), QrCode::Ecc::LOW);
    const int baseSize = qrcode.getSize()>0 ? qrcode.getSize() : 1;
    const double width = rect.width();
    const double height = rect.height();
    const double aspect = width/height;
    const double size = ((aspect > 1.0) ? height : width);
    const double scale = size/(baseSize+2);
    QImage result(rect.width(), rect.height(),
                  QImage::Format_ARGB32_Premultiplied);
    result.fill(Qt::white);
    QPainter painter(&result);
    painter.setPen(Qt::SolidLine);
    painter.setBrush(QColor(Qt::black));
    for(int y=0; y<baseSize; y++) {
        for(int x=0; x<baseSize; x++) {
            auto color = qrcode.getModule(x, y);
            if(0!=color) {
                QRectF r((x+1)*scale, (y+1)*scale,
                         scale, scale);
                painter.drawRects(&r,1);
            }
        }
    }
    return result;
}

QString QrCodeImage::text() const {
    return mText;
}

void QrCodeImage::setText(const QString &text) {
    if(mText == text) {
        return;
    }
    mText = text;
    emit textChanged();
    generateImage();
    update();
}
} //namespace qrcodegen
