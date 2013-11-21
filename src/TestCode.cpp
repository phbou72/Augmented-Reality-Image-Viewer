// IN213
// TP  WEBCAM 2010-2011
// Introduction au traitement du flux video temps réel
// Utilise la librairie OpenCV 2.2 pour la lecture et
// la visualisation des flux vidéo d'entrée et sortie
//
/*
#include "stdio.h"
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
# define BLANC 150

// fonction "main"
int _tmain(int argc, char **argv)
{
   // variable pour lire touche clavier pour terminer le programme
  char key ='a';


  //  déclaration des images
  IplImage *img; // utilisée en image d'entrée
  IplImage *bg;  // utilisée en image de sortie
  IplImage *g; // utilisée en image niv gris
  IplImage *ap;  // utilisée en image arriere plan


  // préparation de la Capture vidéo
  CvCapture *capture;

  // déclaration des variables utilisées pour le traitement d'image
  //
  int height,width,step,channels;    // dimensions de l'image
  uchar *data;                        // pointeur vers les données de l'image d'entrée

  uchar *data_g;                    // pointeur vers les données de l'image niveau de gris
  uchar *data_ap;                    // pointeur vers les données de l'image arriere plan


  uchar *data_bg;                    // pointeur vers les données de l'image de sortie
  int i,j,k;
  int R,G,B,Bk,max,min;
  int N =3;
  int h = 30;


  // Capture du flux vidéo
  // Ouvrir le flux vidéo
  capture = cvCreateCameraCapture(CV_CAP_ANY);
  // Vérifier si l'ouverture du flux est ok
  if (!capture) {
    printf("Ouverture du flux vidéo impossible !\n");
    return 1;
  }

  // Définition des fenêtres pour affichage
  cvNamedWindow("GrayLevels", CV_WINDOW_AUTOSIZE); // image de sortie
  cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);   // image d'entrée

   // On récupère la première image
   img = cvQueryFrame(capture);
   bg = cvCloneImage(img); // on crée la même image avec les mêmes dimensions
   g = cvCloneImage(img);
   ap = cvCloneImage(img);


  // ------------------------------------------------------------------------
  // Traitement du flux vidéo
  // Boucle tant que l'utilisateur n'appuie pas sur la touche q (ou Q)

  while(key != 'q' && key != 'Q')
    {
       // On récupère une image de la webcam (avec les paramètres p ar défaut)

      img = cvQueryFrame(capture);
      // On récupère la taille de l'image, le nombre des cannaux de couleurs (RGB)
      height    = img->height;
      width     = img->width;
      step      = img->widthStep; // distance entre deux pixels
      channels  = img->nChannels;
      data      = (uchar *)img->imageData; // initialisation des pointeurs
      data_bg = (uchar *) bg->imageData    ;  // initialisation des pointeurs
      data_g = (uchar *) g->imageData    ;  // initialisation des pointeurs
      data_ap = (uchar *) ap->imageData    ;  // initialisation des pointeurs

//////////////////////////////////////////

    //binariser l'image

      for(i=0;i<height;i++) {
            for(j=0;j<width;j++)
                {
                    B= data[i*step+j*channels];
                    G= data[i*step+j*channels+1];
                    R= data[i*step+j*channels+2];

                    for(k=0;k<channels;k++)
                    {
                        if(R>BLANC && G>BLANC && B>BLANC ) Bk=1;
                        else Bk = 0;
                        data_g[i*step+j*channels +k]   = Bk * 255;
                    }
            }}//for
             j = 0 ;
              while ( j < width )
             {j++ ; // ATTENTION ON IGNORE VOLONTAIREMENT EN TOUTE ETAT DE CAUSE LA PREMIERE LIGNE
                for(i=height;i>0;i--)
                {

					B= data_g[i*step+j*channels];
                    G= data_g[i*step+j*channels+1];
                    R= data_g[i*step+j*channels+2];

                    if ( B < 5 && G < 5 && R < 5 ){

                        data_bg[i*step+j*channels +2]   = 255;
                        data_bg[i*step+j*channels +0]   = 0;
                        data_bg[i*step+j*channels +1]   = 0;

                        i = 0  ;
                    }
                    else {
                        data_bg[i*step+j*channels +2]   = data_g[i*step+j*channels];


                        data_bg[i*step+j*channels +0]   = data_g[i*step+j*channels+1];
                        data_bg[i*step+j*channels +1]   = data_g[i*step+j*channels+2];
                    }




                }//for

              }//while

///////////////////////////////////////////

      // a demander : cvCanny(  img, bg , 20,
        //      60, 3 );


      // On affiche l'image dans une fenêtre
      cvShowImage("GrayLevels", bg);
      cvShowImage("imt", g);

      cvShowImage("Original", img);

      // On attend 10ms
      key = cvWaitKey(10);

    } //while



  // on détruit les fêntres et on ferme l'acquisition du fluw vidéo
  cvReleaseCapture(&capture);
  cvDestroyWindow("GrayLevels");
  cvDestroyWindow("Original");

  return 0;

}*/
