#include "visualizer.h"

#define TAILLE_CASE 10

Visualizer::Visualizer() {}

Visualizer::~Visualizer()
{
    if (carte != NULL)
        delete carte;
}

// Charger depuis une carte
void Visualizer::ChargerCarte(Carte newCarte)
{
    carte = new Mat(newCarte.hauteur*TAILLE_CASE, newCarte.longueur*TAILLE_CASE, CV_8UC3, Scalar(100 ,100, 100));

    for (int i = 0; i < newCarte.hauteur; ++i)
    {
        for (int j = 0; j < newCarte.longueur; ++j)
        {
            if (newCarte.tableau[i][j])
            {
                Rect rect(j * TAILLE_CASE, i * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
                rectangle(*carte, rect, Scalar(0, 0 ,0),  -1);
            }
        }
    }
}
void Visualizer::AfficherChemin(std::vector<Coord> chemin)
{

    for (int i = 0; i < chemin.size(); ++i)
    {
        circle(*carte, Point(chemin[i].x * TAILLE_CASE, chemin[i].y * TAILLE_CASE), TAILLE_CASE/2, Scalar( 255, 0 ,0),  -1);
    }
    
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", *carte);
    waitKey(0);
}