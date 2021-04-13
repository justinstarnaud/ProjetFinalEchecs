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
	void afficherEchiquier(QPaintEvent* e) {
		int x = 0, y = 0;
		int couleur = 0;
		for (int ligne = 0; ligne < nLignes; ligne++) {
			for (int colonne = 0; colonne < nColonnes; colonne++) {

				QPainter painter(this);

				if (couleur == 0) {
					painter.setBrush(Qt::white);
					couleur++;
				}
				else
				{
					painter.setBrush(Qt::black);
					couleur--;
				}
				QRectF rectangle(x, y, 80.0, 80.0);
				painter.drawRect(rectangle);

				x += 100;
			}
			y += 100;
			x = 0;
			couleur == 0 ? couleur = 1 : couleur = 0;
		}
	}
};
