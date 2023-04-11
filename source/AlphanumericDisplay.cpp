#include "AlphanumericDisplay.h"

AlphanumericDisplay::AlphanumericDisplay(uint8_t rows, uint8_t columns, QObject *parent)
    : QObject{parent}
{
    _rows = rows;
    _columns = columns;

    _scene.setBackgroundBrush(QBrush(Qt::darkBlue));

    for(auto i = 0; i<_rows; i++)
    {
        for(auto y = 0; y<_columns; y++)
        {
            AlphanumericCharacter* item = new AlphanumericCharacter((i*_columns)+y,_pixelSize);

            connect(item, &AlphanumericCharacter::hoverEnter, this, &AlphanumericDisplay::on_hoverEnterEvent);
            connect(item, &AlphanumericCharacter::hoverLeave, this, &AlphanumericDisplay::on_hoverLeaveEvent);

            item->setCharacter(' ');

            _scene.addItem(item);
            item->setPos(_pixelSize*6*y , i*_pixelSize*9);

            _items.append(item);
        }
    }
}

void AlphanumericDisplay::write(QString text)
{
    _text = text.toLocal8Bit();
    _update();
}

void AlphanumericDisplay::writeHover(QString text)
{
    _hoverText = text.toLocal8Bit();
}

QGraphicsScene *AlphanumericDisplay::scene()
{
    return &_scene;
}

void AlphanumericDisplay::on_hoverEnterEvent(uint8_t index)
{
    for(auto i = 0; i<80; i++)
    {
        if(i<index)
        {
            _items.at(i)->setCharacter(' ');
        }
        else if(i>=index && i < index+_hoverText.size())
        {
            _items.at(i)->setCharacter(_hoverText.at(i-index));
        }
        else
        {
            _items.at(i)->setCharacter(' ');
        }
    }
}

void AlphanumericDisplay::on_hoverLeaveEvent(uint8_t index)
{
    _update();
}

void AlphanumericDisplay::_update()
{
    for(auto i = 0; i<_rows*_columns ; i++)
    {
        if(i >= _text.size()) _items.at(i)->setCharacter(' ');
        else _items.at(i)->setCharacter(_text.at(i));
    }
}
