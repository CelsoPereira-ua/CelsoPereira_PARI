/*File generated automatically in slb by celsopereira on Qua Nov 29 11:09:22 WET 2017*/
#ifdef __cplusplus
extern "C" {
#endif
/* main.c */
int main (int argc, char *argv[]);
/* callbacks.c */
void on_drawingarea1_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data);
void on_drawingarea1_motion_notify_event(GtkWidget *widget, GdkEventMotion *event, gpointer user_data);
void p_RedrawText(cairo_t *cr);
void p_RedrawFreeForm(cairo_t * cr);
void on_drawingarea1_scroll_event(GtkWidget *widget, GdkEventScroll *event, gpointer user_data);
void p_InitTimer();
gboolean p_ForceRefreshDA(gpointer user_data);
/* myf.c */
void InterceptCTRL_C (int a);
void ReverseString (char *str);
void on_button1_clicked (GtkWidget * widget, gpointer user_data);
void on_button3_clicked (GtkWidget * widget, gpointer user_data);
gboolean pari_delete_event (GtkWidget * window, GdkEvent * event, gpointer data);
#ifdef __cplusplus
}
#endif
