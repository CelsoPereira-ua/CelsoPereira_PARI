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
 * @brief  Manage button 3 click with the intention to leave application
 *    Either shows a message or exits
 *
 * @param  w - The Widget ID
 * @param user_data - Custom data with the ID of another widget to check. In this case the switch1
 * @return void
 */
void on_button3_clicked(GtkWidget * widget, gpointer user_data)
{
  gboolean a = gtk_switch_get_active( GTK_SWITCH(user_data) );
  
  if (a == FALSE)
        printf("Must enable the Quit switch before leaving\n");
  else
  	gtk_main_quit();
}

/**
 * @brief  Function to process the text from entry and label
 *
 * @param widget - the one that originated the call
 * @param user_data - Custom data with a widget ID to fetch some info
 * @return void
 */
void on_button1_clicked(GtkWidget *widget, gpointer user_data)
{
  char *aux = malloc(sizeof(char)*50);	
	
  GtkEntry *ts = GTK_ENTRY(user_data);
  GtkLabel *lbl= GTK_LABEL(gtk_builder_get_object(builderG,"label3")); //Get some specific label ID to change it
  if(ts)
  {
        const char* tss = gtk_entry_get_text( ts ); //get the text from entry1 widget
        printf("Text available in entry1: %s\n", tss);
        ReverseString( strcpy(aux,tss) );
        gtk_label_set_text(lbl, aux );   //set entry text in "label2" widget
        gtk_widget_hide( GTK_WIDGET(ts) );
	gtk_widget_show( GTK_WIDGET(ts) );
  }
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


