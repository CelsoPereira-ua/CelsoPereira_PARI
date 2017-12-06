/**
*      @file   myf.h
*      @brief  header file with the function prototypes
*
* Descrição mais detalhada do ficheiro
*
*     @author  CelsoPereira, 83307, celsopereira@ua.pt
*
*   @internal
*     Created  06-Dez-2017
*     Company  University of Aveiro
*   Copyright  Copyright (c) 2017, CelsoPereira
*
***************************************************
 */
 
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <gtk/gtk.h>
#include <cv.h>
#include <highgui.h>
#include <cairo.h>
 
#define MAXFFBUFFER 1000
typedef struct {
  int count;
  double x[MAXFFBUFFER];
  double y[MAXFFBUFFER];
} free_form;

#ifndef _MYF_H
#define _MYF_H

// as variáveis globais sugeridas são:
#if defined (_MAIN_C_)
        GtkBuilder *builderG;
        IplImage *dst_imageG , *src_imageG;
        CvCapture *captureG;
        double xoffG=100;
        double yoffG=150;
        double fontSizeFactorG = 1;
        free_form ffG={0};   //init count to zero. Do not affect x and y.
#else
        extern GtkBuilder *builderG;
        extern IplImage *dst_imageG , *src_imageG;
        extern CvCapture *captureG;
        extern double xoffG;
        extern double yoffG;
        extern double fontSizeFactorG;
        extern free_form ffG;
#endif
#endif

#include "prototypes.h"

