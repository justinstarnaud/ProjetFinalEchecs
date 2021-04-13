#include "Vue.h"
#include <QApplication>
#include <qwidget.h>
#include <QPainter>
#include <QPaintEvent>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLabel>

void VueEchiquier::paintEvent(QPaintEvent* event) {
	/*int x = 0, y = 0;
	int couleur = 0;
	QPainter painter(this);
	QVector<QRectF> rectangles;
	for (int ligne = 0; ligne < nLignes; ligne++) {
		for (int colonne = 0; colonne < nColonnes; colonne++) {

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
			rectangles.push_back(rectangle);

			x += 100;
		}
		y += 100;
		x = 0;
		couleur == 0 ? couleur = 1 : couleur = 0;
	}*/
	QVector<QRectF> rectangles;
	QPainter painter(this);


	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			QRectF rectangle(80 * i, 80 * j, 80.0, 80.0);
			if ((i % 2) == (j % 2))
			{
				const QColor myColor(255, 255, 255);
				painter.fillRect(rectangle, myColor);
			}
			else {
				const QColor myColor1(0, 0, 0);
				painter.fillRect(rectangle, myColor1);
			}
			rectangles.push_back(rectangle);
		}

	painter.drawRects(rectangles);

}