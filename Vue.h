#pragma once
#include <QApplication>
#include <QPainter>
#include <qwidget.h>
#include <QPaintEvent>
#include <QMainWindow>
#include "classes_projet.hpp"


class VueEchiquier : public QWidget {
	Q_OBJECT
public:
	VueEchiquier(Echiquier& echiquier) : echiquier_(echiquier) {}
	void paintEvent(QPaintEvent* e);

signals:

public slots:

private:
	Echiquier& echiquier_;
};
