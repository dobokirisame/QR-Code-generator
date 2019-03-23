#ifndef QRCODEIMAGE_H
#define QRCODEIMAGE_H

#include <QQuickPaintedItem>
#include <QImage>

namespace qrcodegen {
class QrCodeImage : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    explicit QrCodeImage(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    QString text() const;
    void setText(const QString &text);
signals:
    void textChanged();
private:
    QImage generateImage() const;
private:
    QImage mImage;
    QString mText;
};
} // namespace qrcodegen
#endif // QRCODEIMAGE_H
