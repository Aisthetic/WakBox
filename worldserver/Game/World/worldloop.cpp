#include "WorldLoop.h"

void WorldLoop::run()
{
    quint64 currentTime, previousSleepTime = 0;
    quint64 previousTime = QDateTime::currentMSecsSinceEpoch();

    forever
    {
        if(m_stop) break;

        currentTime = QDateTime::currentMSecsSinceEpoch();
        quint64 diff = currentTime - previousTime;

        World::Instance()->Update(diff);
        previousTime = currentTime;

        if (diff <= 1 + previousSleepTime)
        {
            previousSleepTime = 1 + previousSleepTime - diff;
            this->thread()->msleep(previousSleepTime);
        }
        else
            previousSleepTime = 0;
    }

    Log::Write(LOG_TYPE_DEBUG, "WorldLoop stopped");
    emit finished();
}
