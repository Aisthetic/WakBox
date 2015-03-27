#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtCore>
#include <QObject>

template <typename T> class Singleton : public QObject
{
public:
    static T* Instance()
    {
        static QMutex mutex;
        if(m_instance == 0)
        {
            mutex.lock();

            if(!m_instance) //double check
                m_instance = new T;

            mutex.unlock();
        }

        return (static_cast<T*>(m_instance));
    }

    static void Delete()
    {
        static QMutex mutex;
        mutex.lock();
        delete m_instance;
        m_instance = 0; //good pratice to set invalid pointer = 0
        mutex.unlock();
    }

protected:
    Singleton() {}
    virtual ~Singleton() {}

private:
    static T* m_instance;
};

#endif
