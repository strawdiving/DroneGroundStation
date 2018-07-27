#include "attitude_indicator.h"
#include <QShowEvent>
#include <QPaintEvent>
#include <QDebug>
#include <cmath>
#include <qmath.h>
#include <limits>

Attitude_Indicator::Attitude_Indicator(QWidget *parent) :
    QWidget(parent),
    defaultColor(70, 200, 70),
    skyColor(65,105,225),
    earthColor(defaultColor),
    vPitchPerDeg(3.0f), ///< 3 mm y translation per degree)
    rollLP(0.0f),
    pitchLP(0.0f),
    scalingFactor(1.0f),
    yaw(0.0f)
{
    //resize(850,690);
    vwidth = this->width() + 15;
    vheight = this->height();
}

void Attitude_Indicator::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    paint();
}

void Attitude_Indicator::paint()
{
    // Sky
    QPainter painter(this);
    painter.setBrush(QBrush(skyColor,Qt::SolidPattern));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,0,vwidth,vheight);

    painter.translate(vwidth/2.0,vheight/2.0);

     // red crossHair,9:1.2, rollDial 9:5, rollPointer 9:4
     float crossWidth = vwidth/3.0f;
     float crossHeight = vheight*2.0f/45.0f;
     float rollDialWidth=  1.2f*vwidth/2.5f;
     float rollDialHeight = rollDialWidth*5.0f/9.0f;
     float rollPointerWidth = crossWidth;
     float rollPointerHeight =rollDialHeight*0.8f;

     //Roll dial
     // Rotate view and draw all roll-dependent indicators, transform between rolld and real degree
     painter.rotate(rollLP*180/M_PI);

     QPen linePen(Qt::SolidLine);
     linePen.setWidth(2.5f);
     linePen.setColor(Qt::white);
     painter.setBrush(Qt::NoBrush);
     painter.setPen(linePen);
     //Pitch
     paintPitchLines(pitchLP*180/M_PI, &painter);

     QPixmap rollDial(":/attitude/attitude/rollDialWhite.svg");
     painter.drawPixmap(-rollDialWidth/2.0f,-rollDialHeight,rollDialWidth,rollDialHeight, rollDial);

      //Fixed indicators
     painter.rotate(-rollLP*180/M_PI);

      //compass at the top of the widget
      const float compassY =  -vheight/2.0f+15.0f;
      painter.drawLine(QPointF(-1.5*vwidth,compassY),QPointF(1.5*vwidth,compassY));
      QPixmap compassPointer(":/attitude/attitude/rollPointerWhite.svg");
      painter.drawPixmap(-rollPointerWidth/2.0f,compassY+8.0f,rollPointerWidth,rollPointerHeight, compassPointer);

      float yawDeg = (yaw / M_PI) * 180.0f;
      painter.translate(-vwidth*yawDeg/120.0f,0);//vwidth*yawDegree/(120 degree)

      for(int i = 0;i<73;i++)
      {
          QPointF p1 =QPointF(-1.5*vwidth+i*(vwidth/24.0f),compassY);
          QPointF p2 =QPointF(-1.5*vwidth+i*(vwidth/24.0f),compassY-8.0f);

          if(i%3!=0)
          drawLine(p1.x(),p1.y(),p2.x(),p2.y(),1.5f,Qt::white,&painter);
          else
          {
              drawLine(p1.x(),p1.y(),p2.x(),p2.y()-2.0f,3.0f,Qt::white,&painter);
              QString text;

              switch(i)
              {
              case 0: //-180
              case 72: text = QString::fromLocal8Bit("南"); break;//+180
              case 9: text = QString::fromLocal8Bit("西南"); break;//-135 "SW"
              case 18: text = QString::fromLocal8Bit("西"); break;//-90
              case 27: text = QString::fromLocal8Bit("西北"); break;//-45
              case 36: text = QString::fromLocal8Bit("北") ; break;//0 "N"
              case 45: text = QString::fromLocal8Bit("东北"); break;//45
              case 54: text = QString::fromLocal8Bit("东"); break;//90
              case 63: text = QString::fromLocal8Bit("东南"); break; //135
              default: text = QString::number((-36+i)*5);
              }
              paintText(text, Qt::white, 14.0f, (p1.x()-8.0f),(p1.y()+6.0f), &painter);
          }
      }
      painter.translate(vwidth*yawDeg/120.0f,0);

      // Roll pointe
      QPixmap rollPointer(":/attitude/attitude/rollPointerWhite.svg");
      painter.drawPixmap(-rollPointerWidth/2.0f,-rollPointerHeight,rollPointerWidth,rollPointerHeight, rollPointer);

      // Red crossHair
      QPixmap cross(":/attitude/attitude/crossHair.svg");
      painter.drawPixmap(-crossWidth/2.0f,-crossHeight/2.0f,crossWidth,crossHeight,cross);


      update();
}

    // Draw pitch lines (pitch angle in degrees (-180 to 180))
    void Attitude_Indicator::paintPitchLines(float pitch, QPainter* painter)
    {
        QString label;

        const float yDeg = vPitchPerDeg;//3
        const float lineDistance = 5.0f; ///< One pitch line every 10 degrees
        const float posIncrement = yDeg * lineDistance;//15
        float posY = posIncrement;

        const float offsetAbs = pitch * yDeg;//pitch*3

        // EARTH
        const float diagonal = sqrt(pow(vwidth, 2.0f) + pow(vheight, 2.0f));

        painter->setBrush(QBrush(earthColor,Qt::SolidPattern));
        painter->setPen(Qt::NoPen);
        //painter->drawRect(-diagonal,offsetAbs,2.0f*diagonal,2.0f*diagonal);
        painter->drawRect(-diagonal,offsetAbs,2.0f*diagonal,2.0f*diagonal);

        int iPos = (int)(0.5f + lineDistance); ///< The first line,int(5.5)=5
        int iNeg = (int)(-0.5f - lineDistance); ///< The first line,int(-5.5)=-5

        //rollDialHeight*2/5
        const float posLimit = vwidth/6.0f;
        //const float posLimit = vwidth/11.25f;
        posY = -offsetAbs + posIncrement; //-3*pitch+30

        while (abs(posY) < posLimit) {
            if(iPos%2==0)
                 paintPitchLinePos(80.0f, label.sprintf("%3d", iPos), 0.0f, -posY, painter);
            else
                 paintPitchLinePos(60.0f, label.sprintf(" "), 0.0f, -posY, painter);
            posY += posIncrement;
            iPos += (int)lineDistance;
        }

        posY = offsetAbs  + posIncrement;

        while (abs(posY) < posLimit) {
            if(iNeg%2==0)
            paintPitchLinePos(100.0f, label.sprintf("%3d", iNeg), 0.0f, posY, painter);
            else
            paintPitchLinePos(80.0f, label.sprintf(" "), 0.0f, posY, painter);

            posY += posIncrement;
            iNeg -= (int)lineDistance;
        }
    }

    void Attitude_Indicator::paintPitchLinePos(const float pitchWidth, QString text, float refPosX, float refPosY, QPainter* painter)
    {
        const float pitchHeight = 10.0f;
        const float textSize = pitchHeight * 1.6f;//4
        const float lineWidth = 3.5f;
        // 10_______ 10
        drawLine(refPosX-pitchWidth/2.0f, refPosY, refPosX+pitchWidth/2.0f, refPosY, lineWidth, Qt::white, painter);

        paintText(text, Qt::white, textSize, refPosX-pitchWidth/2.0 - 50.0f, refPosY - pitchHeight, painter);
        paintText(text, Qt::white, textSize, refPosX+pitchWidth/2.0 + 20.0f, refPosY - pitchHeight, painter);
    }

Attitude_Indicator::~Attitude_Indicator()
{

}

/**
 * Paint text on top of the image
 * @param fontSize text size in mm
 * @param refX position in reference units (mm of the real instrument).
 * @param refY position in reference units (mm of the real instrument).
 */
void Attitude_Indicator::paintText(QString text, QColor color, float fontSize, float refX, float refY, QPainter* painter)
{
    QPen prevPen = painter->pen();
    float pPositionX = (refX) - (fontSize*0.072f);
    float pPositionY = refY - (fontSize*0.212f);

    //QFont font("Bitstream Vera Sans");
    QFont font("Times");
    // Enforce minimum font size of 5 pixels
    int fSize = qMax(5, (int)(fontSize*1.26f));
    font.setPixelSize(fSize);

    QFontMetrics metrics = QFontMetrics(font);
    int border = qMax(4, metrics.leading());
    QRect rect = metrics.boundingRect(0, 0, width() - 2*border, int(height()*0.125),
                                      Qt::AlignLeft | Qt::TextWordWrap, text);
    painter->setPen(color);
    painter->setFont(font);
    painter->setRenderHint(QPainter::TextAntialiasing);//消锯齿，平滑化
    painter->drawText(pPositionX, pPositionY,
                      rect.width(), rect.height(),
                      Qt::AlignCenter | Qt::TextWordWrap, text);
    painter->setPen(prevPen);
}

void Attitude_Indicator::drawLine(float refX1, float refY1, float refX2, float refY2, float width, const QColor& color, QPainter* painter)
{
    QPen pen(Qt::SolidLine);
    pen.setWidth(width);
    pen.setColor(color);
    painter->setPen(pen);
    painter->drawLine(QPoint(refX1, refY1), QPoint(refX2, refY2));
}
