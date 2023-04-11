#include "AlphanumericCharacter.h"

AlphanumericCharacter::AlphanumericCharacter(uint8_t index, uint8_t pixelSize)
{
    setAcceptHoverEvents(true);

    _character = ' ';
    _index = index;
    _pixelSize = pixelSize;
}

void AlphanumericCharacter::setCharacter(char character)
{
    _character = character;
    update();
}

void AlphanumericCharacter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{

     painter->setPen(QPen(Qt::black));

     for (int x=0; x<=_row*_pixelSize; x+=_pixelSize)
     {
         painter->drawLine(x,0,x,_collum*_pixelSize);
     }

     for (int y=0; y<=_collum*_pixelSize; y+=_pixelSize)
     {
         painter->drawLine(0,y,_row*_pixelSize,y);
     }

     for(auto i = 0; i< _row; i++)
     {
         uint8_t line = _font[(uint8_t) _character][i+1];

         for(auto y = 0; y<_collum; y++)
         {
             QBrush br = QBrush(Qt::darkBlue);
             if (line & 0x01) br = QBrush(Qt::white);

             line = line>>1;
             painter->fillRect(i*_pixelSize,y*_pixelSize+1,_pixelSize-1, _pixelSize-1,br);
         }
     }
}


QRectF AlphanumericCharacter::boundingRect() const
{
    return QRectF(0, 0, _row*_pixelSize-1, _collum*_pixelSize-1);
}

void AlphanumericCharacter::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit hoverEnter(_index);
    update();
}

void AlphanumericCharacter::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit hoverLeave(_index);
    update();
}

