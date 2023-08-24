#include <gtk/gtk.h>

inline static void activate (GtkApplication* app, gpointer user_data)
{
  //GtkWidget *widget = gtk_application_window_new(app);
  GtkWindow *window =  GTK_WINDOW (gtk_application_window_new(app));
  gtk_window_set_title (window, "Window");
  gtk_window_set_default_size (window,3200, 200);
  gtk_window_present(window);
}

int main (int argc,char **argv)
{
  GtkApplication *app;
  
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  int status;
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
