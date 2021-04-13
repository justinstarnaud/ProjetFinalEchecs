#pragma once
#include <QApplication>
#include <QPainter>
#include <qwidget.h>
#include <QPaintEvent>
#include <QMainWindow>
#include "classes_projet.hpp"


class VueEchiquier : public QWidget {
	Q_OBJECT
protected:
	void paintEvent(QPaintEvent* e);

signals:

public slots:
};
