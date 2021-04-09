#include "classes_projet.hpp"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(TestRoi, TestInitilisation) {
	Roi roi = Roi(blanc);
	EXPECT_EQ(blanc, roi.getCouleur());
	EXPECT_EQ(0, roi.getPosition().first);
	EXPECT_EQ(4, roi.getPosition().second);

	Roi roiN = Roi(noir);
	EXPECT_EQ(noir, roiN.getCouleur());
	EXPECT_EQ(7, roiN.getPosition().first);
	EXPECT_EQ(4, roiN.getPosition().second);
}

TEST(TestRoi, TestMouvement) {
	Roi roi = Roi(blanc);
	//tests avec des mouvements valides
	EXPECT_TRUE(roi.setPosition(0, 5));
	EXPECT_TRUE(roi.setPosition(1, 5));
	EXPECT_TRUE(roi.setPosition(1, 6));

	//tests avec des mouvements invalides
	EXPECT_FALSE(roi.setPosition(1, 6));
	EXPECT_FALSE(roi.setPosition(12, 5));
	EXPECT_FALSE(roi.setPosition(3, 6));
	EXPECT_FALSE(roi.setPosition(1, 8));
}

TEST(TestCavalier, TestInitilisation) {
	Cavalier cav = Cavalier(blanc, gauche);
	EXPECT_EQ(blanc, cav.getCouleur());
	EXPECT_EQ(0, cav.getPosition().first);
	EXPECT_EQ(1, cav.getPosition().second);

	Cavalier cavN = Cavalier(noir, droite);
	EXPECT_EQ(noir, cavN.getCouleur());
	EXPECT_EQ(7, cavN.getPosition().first);
	EXPECT_EQ(6, cavN.getPosition().second);
}

TEST(TestCavalier, TestMouvement) {
	Cavalier cav = Cavalier(blanc, gauche);
	//tests avec des mouvements valides
	EXPECT_TRUE(cav.setPosition(2, 2));
	EXPECT_TRUE(cav.setPosition(1, 4));
	EXPECT_TRUE(cav.setPosition(3, 3));

	//tests avec des mouvements invalides
	EXPECT_FALSE(cav.setPosition(3, 3));
	EXPECT_FALSE(cav.setPosition(-1, 5));
	EXPECT_FALSE(cav.setPosition(3, 6));
	EXPECT_FALSE(cav.setPosition(5, 5));
}

TEST(TestTour, TestInitilisation) {
	Tour tour = Tour(blanc, gauche);
	EXPECT_EQ(blanc, tour.getCouleur());
	EXPECT_EQ(0, tour.getPosition().first);
	EXPECT_EQ(0, tour.getPosition().second);

	Tour tourN = Tour(noir, droite);
	EXPECT_EQ(noir, tourN.getCouleur());
	EXPECT_EQ(7, tourN.getPosition().first);
	EXPECT_EQ(7, tourN.getPosition().second);
}

TEST(TestTour, TestMouvement) {
	Tour tour = Tour(blanc, gauche);
	//tests avec des mouvements valides
	EXPECT_TRUE(tour.setPosition(0, 2));
	EXPECT_TRUE(tour.setPosition(0, 7));
	EXPECT_TRUE(tour.setPosition(7, 7));

	//tests avec des mouvements invalides
	EXPECT_FALSE(tour.setPosition(7, 7));
	EXPECT_FALSE(tour.setPosition(8, 7));
	EXPECT_FALSE(tour.setPosition(6, 6));
	EXPECT_FALSE(tour.setPosition(5, 4));
}

TEST(TestEchiquier, TestMouvementValide) {
	Echiquier echiquier = Echiquier();
	EXPECT_TRUE(echiquier.effectuerMouvement(0, 0, 5, 0));
	EXPECT_TRUE(echiquier.effectuerMouvement(7, 1, 5, 2));
	EXPECT_TRUE(echiquier.effectuerMouvement(0, 4, 1, 5));
}

TEST(TestEchiquier, TestPieceEnChemin) {
	Echiquier echiquier = Echiquier();
	echiquier.effectuerMouvement(7, 0, 4, 0);
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 0, 7, 0));
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 0, 0, 3));
	echiquier.effectuerMouvement(0, 6, 2, 7);
	EXPECT_FALSE(echiquier.effectuerMouvement(7, 7, 1, 7));

}

TEST(TestEchiquier, TestManger) {
	Echiquier echiquier = Echiquier();
	Tour tourNoire = Tour(noir, gauche);
	Tour tourBlanche = Tour(blanc, gauche);
	tourBlanche.setPosition(7, 0);

	//On test qu'il y a une tour blanche a la position 7,0 de l'echiquier
	EXPECT_EQ(tourNoire.getCouleur() , echiquier.getPiece(7, 0)->getCouleur());
	EXPECT_EQ(tourNoire.getPosition().first, echiquier.getPiece(7, 0)->getPosition().first);
	EXPECT_EQ(tourNoire.getPosition().second, echiquier.getPiece(7, 0)->getPosition().second);

	//On test que le mouvement de la tour blanche mangeant la tour noire est faisable
	EXPECT_TRUE(echiquier.effectuerMouvement(0, 0, 7, 0));

	//On test qu'il y a maintenant une tour blanche a la position 7,0 de l'echiquier
	EXPECT_EQ(tourBlanche.getCouleur(), echiquier.getPiece(7, 0)->getCouleur());
	EXPECT_EQ(tourBlanche.getPosition().first, echiquier.getPiece(7, 0)->getPosition().first);
	EXPECT_EQ(tourBlanche.getPosition().second, echiquier.getPiece(7, 0)->getPosition().second);


}

//TEST(TestEchiquier, TestPieceEnChemin) {
//	Echiquier echiquier = Echiquier();
//
//}

#endif