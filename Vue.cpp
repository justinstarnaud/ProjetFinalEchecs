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

	QVector<QRectF> rectangles;
	QPainter painter(this);
	QFont font = painter.font();
	font.setPointSize(40);
	painter.setFont(font);

	for (int ligne = 0; ligne < nLignes; ligne++)
		for (int colonne = 0; colonne < nColonnes; colonne++)
		{
			QRectF rectangle(80 * ligne, 80 * colonne, 80.0, 80.0);
			if ((ligne % 2) == (colonne % 2))
			{
				const QColor myColor(174, 173, 172);
				painter.fillRect(rectangle, myColor);
			}
			else {
				const QColor myColor1(0, 99, 37);
				painter.fillRect(rectangle, myColor1);
			}
			rectangles.push_back(rectangle);

			if (echiquier_.getPiece(colonne, ligne) != nullptr) 
			{
				Piece* piece = echiquier_.getPiece(colonne, ligne);
				bool couleur = piece->getCouleur();
				QString pieceVue;
				if (dynamic_cast<Roi*>(piece)) couleur ? pieceVue = QChar(0x2654) : pieceVue = QChar(0x265A);
				else if (dynamic_cast<Tour*>(piece)) couleur ? pieceVue = QChar(0x2656): pieceVue = QChar(0x265C);
				else if (dynamic_cast<Cavalier*>(piece)) couleur ? pieceVue = QChar(0x2658): pieceVue = QChar(0x265E);

				painter.drawText(rectangle, Qt::AlignCenter, pieceVue);
			}
		}

	painter.drawRects(rectangles);

}