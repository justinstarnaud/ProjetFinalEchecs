/*
* Fichier contenant les tests sur nos classes du projet final.
* file
* author Benoit - Paraschivoiu et St - Arnaud
* date    8 avril 2021
* Cr�� le 1 avril 2021
*/
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

TEST(TestEchiquier, TestMouvement) {
	Echiquier echiquier = Echiquier();
	// test de mouvement invalide pour une tour...
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 0, 2, 1));
	// ...cavalier
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 1, 5, 1));
	// ...roi
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 4, 2, 5));

	// test de mouvement d'une case sans piece
	EXPECT_FALSE(echiquier.effectuerMouvement(5, 0, 2, 6));
	EXPECT_FALSE(echiquier.effectuerMouvement(2, 1, 2, 6));

	// test mouvement valide
	EXPECT_TRUE(echiquier.effectuerMouvement(0, 0, 5, 0));
	EXPECT_TRUE(echiquier.effectuerMouvement(7, 1, 5, 2));
	EXPECT_TRUE(echiquier.effectuerMouvement(0, 4, 1, 5));

	// test de mouvement vers sa propre case
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 4, 0, 4));
	EXPECT_FALSE(echiquier.effectuerMouvement(7, 7, 7, 7));	
}

TEST(TestEchiquier, TestPieceEnChemin) {
	Echiquier echiquier = Echiquier();
	echiquier.effectuerMouvement(7, 0, 4, 0);

	// test de mouvement impossible si piece dans la trajectoire
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 0, 7, 0)); // saut verticale impossible
	EXPECT_FALSE(echiquier.effectuerMouvement(0, 0, 0, 3)); // saut horizontal impossible

	echiquier.effectuerMouvement(0, 6, 2, 7);
	EXPECT_FALSE(echiquier.effectuerMouvement(7, 7, 1, 7)); // tour ne peut faire un saut verticale

	EXPECT_TRUE(echiquier.effectuerMouvement(7, 7, 3, 7));
	EXPECT_TRUE(echiquier.effectuerMouvement(2, 7, 4, 6));
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

	// On test qu'on ne peut manger une piece de sa couleur
	echiquier.effectuerMouvement(0, 1, 2, 0);
	EXPECT_EQ(blanc, echiquier.getPiece(2, 0)->getCouleur());
	EXPECT_FALSE(echiquier.effectuerMouvement(7, 0, 2, 0));
}

TEST(TestEchiquier, TestMiseEnEchec){
	Echiquier echiquier = Echiquier();
	EXPECT_TRUE(echiquier.effectuerMouvement(0, 0, 2, 0));
	EXPECT_TRUE(echiquier.effectuerMouvement(2, 0, 2, 4)); // echec de la tour blanche

	EXPECT_FALSE(echiquier.effectuerMouvement(7, 7, 6, 7)); // mouvement illegal puisque etat d echec
	EXPECT_EQ(echiquier.getPiece(6,7), nullptr); // on remarque que la tour noir n<est pas aller a la position, car etat echec

	EXPECT_TRUE(echiquier.effectuerMouvement(7, 6, 6, 4)); // mouvemnent possible qui protege l echec
	EXPECT_EQ(echiquier.getPiece(7, 6), nullptr); // le cavalier est bien aller a pos(6,4)

	EXPECT_FALSE(echiquier.effectuerMouvement(6, 4, 5, 2)); // mouvement illegal qui met les noir en echec (en decouvrant le roi)

}

#endif