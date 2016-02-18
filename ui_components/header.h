#ifndef HEADER1_H
#define HEADER1_H

#include <QObject>
#include <QLabel>
#include <QPaintEvent>

class Header1 : public QLabel
{
    Q_OBJECT

public:
    explicit Header1(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};

class Header2 : public QLabel
{
    Q_OBJECT

public:
    explicit Header2(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};

class Header3 : public QLabel
{
    Q_OBJECT

public:
    explicit Header3(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};

class Header4 : public QLabel
{
    Q_OBJECT

public:
    explicit Header4(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};

class Header5 : public QLabel
{
    Q_OBJECT

public:
    explicit Header5(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};

class Header6 : public QLabel
{
    Q_OBJECT

public:
    explicit Header6(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent*) override;
};


#endif // HEADER1_H
