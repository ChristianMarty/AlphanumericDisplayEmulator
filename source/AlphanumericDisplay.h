#ifndef ALPHANUMERICDISPLAY_H
#define ALPHANUMERICDISPLAY_H

#include <QObject>
#include <QGraphicsScene>

#include "AlphanumericCharacter.h"

class AlphanumericDisplay : public QObject
{
    Q_OBJECT
public:
    explicit AlphanumericDisplay( uint8_t rows, uint8_t columns, QObject *parent = nullptr);

    void write(QString text);
    void writeHover(QString text);

    QGraphicsScene *scene(void);

signals:

private slots:
    void on_hoverEnterEvent(uint8_t index);
    void on_hoverLeaveEvent(uint8_t index);

private:
    uint8_t _rows;
    uint8_t _columns;
    uint8_t _pixelSize = 8;

    void _update(void);

    QByteArray _text;
    QByteArray _hoverText;
    QList<AlphanumericCharacter*> _items;
    QGraphicsScene _scene = QGraphicsScene();

};

#endif // ALPHANUMERICDISPLAY_H
