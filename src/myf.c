/**
 *      @file   myf.c
 *      @brief  ficheiro que inclui as funções utilizadas na realização dos exercícios da aula 12. Cada função tem um header onde se encontra a devida descrição da funcionalidade da mesma
 *
 *
 *     @author  CelsoPereira, celsopereira@ua.pt
 *
 *   @internal
 *     Created  06-Dez-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, CelsoPereira
 *
 ***************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myf.h"


/**
 * @brief  Callback to catch CTRL-C
 */
void InterceptCTRL_C(int a)
{
  g_print("Sair por CTRL-C\n");
  gtk_main_quit();
}


/**
 * @brief  Função para testar se um número é primo
 * @param  nn - número a testar
 * @return 0 se não for primo, 1 se for primo
 */
gboolean pari_delete_event( GtkWidget *window, GdkEvent *event, gpointer data )
{
	g_print("You shouldn't not use OS in force\n");
	return TRUE;
}


/**
 * @brief  Function to reverse a string
 *
 * @param widget - the one that originated the call
 * @param user_data - Custom data with a widget ID to fetch some info
 * @return void
 */
void ReverseString(char *str)
{
  char c, *t1, *t2;
  for(t1 = str, t2 = str + strlen(str); t1 < t2;) //notice that 3rd param of for is empty
      c = *t1, *t1++ = *--t2, *t2 = c;
}


/**
 * @brief  function description
 * @param  nn - input param.
 * @return return param.
 */
CvCapture *pari_StartImageAcquisition()
{
        CvCapture *capture = cvCaptureFromCAM(0);              //Capture using 1st camera: i.e., no. 0
        IplImage *frame=cvQueryFrame(capture);                 //Update frame. Pointer does not change.
        src_imageG = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);//create image for color (8 bits, 3 channels)
        dst_imageG = cvClone(src_imageG);                       //create clone of source image
        
        return capture;
}

/**
 * @brief  function description
 * @param  nn - input param.
 * @return return param.
 */
void pari_PerformImageAcquisition(CvCapture *capt)
{
        static IplImage *frame;
        frame=cvQueryFrame(capt);               //Update frame pointer.
        cvCopy(frame, src_imageG, NULL);        //copy frame as it is (preserve color)
        cvCopy(src_imageG, dst_imageG, NULL);   //copy src into dst and ready to process (admitt similar image structure)
}

/**
 * @brief  function description
 * @param  nn - input param.
 * @return return param.
 */
// Exemplo de código de uma função que converte
// uma IplImage num pixbuf para inserir numa interface GTK
// e ajusta-a com certas dimensões passadas como argumentos

GdkPixbuf *pari_ConvertOpenCv2Gtk(IplImage * image, int dst_w, int dst_h)
{
    IplImage *gtkMask=image;
    GdkPixbuf *pix, *rpix;
    cvCvtColor(image, gtkMask, CV_BGR2RGB);
    pix = gdk_pixbuf_new_from_data((guchar *) gtkMask->imageData,
                       GDK_COLORSPACE_RGB,
                       FALSE,
                       gtkMask->depth,
                       gtkMask->width,
                       gtkMask->height,
                       gtkMask->widthStep, NULL, NULL);
    rpix = gdk_pixbuf_scale_simple(pix, dst_w, dst_h, GDK_INTERP_BILINEAR); //rescale image
    g_object_unref(pix);  //free the intermediate pixbuf...
    return rpix;
}


/**
 * @brief  function description
 * @param  nn - input param.
 * @return return param.
 */
//copy from IplImage to pixbuf and paint DA
void pari_RefreshDrawingArea( char * widgetName, IplImage *img)
{
        GtkWidget *da=GTK_WIDGET(gtk_builder_get_object (builderG, widgetName));
        if( ! da )
        {
          printf("failed\n");
          return;
        }
        GdkPixbuf *pix=pari_ConvertOpenCv2Gtk(img, da->allocation.width, da->allocation.height );
        cairo_t *cr = gdk_cairo_create (gtk_widget_get_window(da));
        gdk_cairo_set_source_pixbuf(cr, pix, 0, 0);
        cairo_paint(cr);
        cairo_fill(cr);
        cairo_destroy(cr);
        g_object_unref(pix);  //free the pixbuf...
}
