#include "BorderAnimation.h"

#include "Global.h"

BorderAnimation::BorderAnimation(QWidget* target, QObject* parent)
    : QObject(parent),
    value(255), target(target), animation(NULL)
{    
    this->animation = new QPropertyAnimation(this, "alpha");
    this->animation->setDuration(1000);
    this->animation->setKeyValueAt(0, 255);
    this->animation->setKeyValueAt(0.5, 64);
    this->animation->setKeyValueAt(1, 255);
}

void BorderAnimation::start(int loopCount)
{
    this->animation->setLoopCount(loopCount);
    this->animation->start();
}

void BorderAnimation::pause()
{
    this->animation->pause();
}

void BorderAnimation::stop()
{
    this->animation->stop();
    this->target->setStyleSheet(QString("#%1 { border-color: rgba(%2); }").arg(this->target->objectName()).arg(Stylesheet::DEFAULT_BORDER_COLOR));
}

int BorderAnimation::alpha() const
{
    return this->value;
}

void BorderAnimation::setAlpha(const int value)
{
    this->value = value;

    this->target->setStyleSheet(QString("#%1 { border-color: rgba(255, 0, 0, %2); }").arg(this->target->objectName()).arg(this->value));
}