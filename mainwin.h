#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include "dialogs.h"
#include <regex>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <exception>

enum Action
{
    Fill,Discard,Pay
};

class Mainwin : public Gtk::Window
{
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_quit_click();
    void on_view_all_click();
    void on_create_coffee_click();
    void on_create_donut_click();
    void on_new_customer_click();
    void on_list_customers_click();
    void on_about_click();
    void on_view_orders_click();
    void on_create_order_click();
    void on_save_click();
    void on_load_click();
    void on_order_fill_click();
    void on_order_pay_click();
    void on_order_discard_click();
    void process_order(Action x);
    //void update_statusbar();
    


  private:
    Store _store;
    Gtk::Label* msg = new Gtk::Label;
    Gtk::Label* l_cash = new Gtk::Label;
    Gtk::MenuItem* menuitem_new_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee",true));
    Gtk::MenuItem* menuitem_new_donut = Gtk::manage(new Gtk::MenuItem("_Donut",true));
    //std::string _status_bar;

};

#endif
