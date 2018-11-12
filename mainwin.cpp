#include "mainwin.h"
Mainwin::~Mainwin() { }
Mainwin::Mainwin()
{
  set_default_size(700, 400);
  Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
  add(*vbox);
  //CRETING MENU BAR "menubar"
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

  //F I L E       M E N U

  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar->append(*menuitem_file);

  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);

  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
  filemenu->append(*menuitem_quit);

  //  V I E W       M E N U

  Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
  menubar->append (*menuitem_view);

  Gtk::Menu *viewmenu = Gtk::manage (new Gtk::Menu());
  menuitem_view ->set_submenu (*viewmenu);

  Gtk::MenuItem *menuitem_view_all = Gtk::manage(new Gtk::MenuItem("_All Products",true));
  menuitem_view_all->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
  viewmenu->append (*menuitem_view_all);

  Gtk::MenuItem *menuitem_view_all_customers = Gtk::manage(new Gtk::MenuItem("_Customers",true));
  menuitem_view_all_customers->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
  viewmenu->append (*menuitem_view_all_customers);

  /*
  Gtk::MenuItem *menuitem_view_java = Gtk::manage(new Gtk::MenuItem("_Java",true));
  menuitem_view_all->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_java_click));
  viewmenu->append (*menuitem_view_java);

  Gtk::MenuItem *menuitem_view_donut = Gtk::manage(new Gtk::MenuItem("_Donut",true));
  menuitem_view_all->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_donut_click));
  viewmenu->append (*menuitem_view_donut);

  */





  //  C R E A T E       M E N U
  Gtk::MenuItem *menuitem_create = Gtk::manage (new Gtk::MenuItem("_Create",true));
  menubar->append (*menuitem_create);

  Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
  menuitem_create ->set_submenu (*createmenu);

  createmenu->append(*menuitem_new_coffee);
  menuitem_new_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));


  createmenu->append(*menuitem_new_donut);
  menuitem_new_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));

  //  C R E A T E      C U S T O M E R
  Gtk::MenuItem *menuitem_new_customer = Gtk::manage (new Gtk::MenuItem("_Customer",true));
  createmenu->append(*menuitem_new_customer);
  menuitem_new_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));



  vbox->show_all();
}

void Mainwin::on_quit_click()
{
  _store.free_products();
  hide();
}
void Mainwin::on_view_all_click()
{
  std::ostringstream strs;
  std::string msg;
  std::string title = " All Products";
  for (int i = 0 ; i < _store.number_of_products() ; i++)
  strs <<std::to_string(i+1)<<". " << _store.product_to_string(i) << "\n";
  msg = strs.str();
  Dialogs::message(msg,title);




}
void Mainwin::on_list_customers_click()
{
  std::ostringstream strs;
  std::string msg;
  std::string title = " All Customers";
  for (int i = 0 ; i < _store.number_of_customers(); i++)
  strs <<std::to_string(i+1)<<". " << _store.customer_to_string(i) << std::endl;
  msg = strs.str();
  Dialogs::message(msg,title);
}

void Mainwin::on_create_coffee_click()
{
  Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
  dialog->set_title("Create Coffee");

  //creting name label and entry and putting it in hbox
  Gtk::HBox *hb_name = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_name = Gtk::manage(new Gtk::Label{"Name:"});
  l_name->set_width_chars(15);
  l_name -> show();
  hb_name->pack_start(*l_name,Gtk::PACK_SHRINK);

  Gtk::Entry *e_name = Gtk::manage(new Gtk::Entry{});
  e_name->set_max_length(50);
  e_name->show();
  hb_name->pack_start(*e_name,Gtk::PACK_SHRINK);
  hb_name ->show();
  dialog->get_vbox()->pack_start(*hb_name,Gtk::PACK_SHRINK);

  //creating Price
  Gtk::HBox *hb_price = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_price = Gtk::manage(new Gtk::Label{"Price:"});
  l_price->set_width_chars(15);
  l_price -> show();
  hb_price->pack_start(*l_price,Gtk::PACK_SHRINK);

  Gtk::Entry *e_price = Gtk::manage(new Gtk::Entry{});
  e_price->set_max_length(50);
  e_price->show();
  hb_price->pack_start(*e_price);
  hb_price ->show();
  dialog->get_vbox()->pack_start(*hb_price);

  //creating Cost

  Gtk::HBox *hb_cost = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_cost = Gtk::manage(new Gtk::Label{"Cost:"});
  l_cost->set_width_chars(15);
  l_cost -> show();
  hb_cost->pack_start(*l_cost,Gtk::PACK_SHRINK);

  Gtk::Entry *e_cost = Gtk::manage(new Gtk::Entry{});
  e_cost->set_max_length(50);
  e_cost->show();
  hb_cost->pack_start(*e_cost);
  hb_cost ->show();
  dialog->get_vbox()->pack_start(*hb_cost);

  //creating Darkness ComboBoxText
  Gtk::HBox *hb_darkness = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_darkness = Gtk::manage(new Gtk::Label{"Darkness:"});
  l_darkness->set_width_chars(15);
  l_darkness -> show();
  hb_darkness->pack_start(*l_darkness,Gtk::PACK_SHRINK);

  Gtk::ComboBoxText *c_darkness = Gtk::manage(new Gtk::ComboBoxText{});
  c_darkness->set_size_request(160);
  c_darkness->append("Blonde");
  c_darkness->append("Light");
  c_darkness->append("Medium");
  c_darkness->append("Dark");
  c_darkness->append("Extra Dark");
  c_darkness ->show();
  hb_darkness->pack_start(*c_darkness, Gtk::PACK_SHRINK);
  hb_darkness ->show();
  dialog->get_vbox()->pack_start(*hb_darkness, Gtk::PACK_SHRINK);

  dialog->add_button("Cancel", 0);
  dialog->add_button("Next", 1);
  dialog->set_default_response(1);


  int result = dialog->run();
  std::string t_name = e_name->get_text();
  std::string t_price = e_price->get_text();
  std::string t_cost = e_cost->get_text();
  int darkness= c_darkness->get_active_row_number();
  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();




  try
  {
    std::regex r0 ("\\d\\d*(.\\d\\d*)?");
    std::regex r1 ("\\w( *(\\w)*)*");
    if (result)
    {
      if (std::regex_match(t_name,r1)&& std::regex_match(t_price,r0) && std::regex_match(t_cost,r0))
      {
        Java *j = new Java(t_name,std::stof(t_price),std::stof(t_cost),darkness+1);
        int result = 2;
        while ( result == 2 ){
          Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
          dialog->set_title("Add shot");
          Gtk::HBox *hb_shot = Gtk::manage(new Gtk::HBox{});
          Gtk::Label *l_shot = Gtk::manage(new Gtk::Label{"Shot:"});
          l_shot->set_width_chars(15);
          l_shot -> show();
          hb_shot->pack_start(*l_shot,Gtk::PACK_SHRINK);

          Gtk::ComboBoxText *c_shot = Gtk::manage(new Gtk::ComboBoxText{});

          c_shot->set_size_request(160);
          c_shot->append("None");
          c_shot->append("Choclate");
          c_shot->append("Vanilla");
          c_shot->append("Peppermint");
          c_shot->append("Hazelnut");
          c_shot->append("Irish Creme");
          c_shot->set_active(0);
          c_shot ->show();
          hb_shot->pack_start(*c_shot, Gtk::PACK_SHRINK);
          hb_shot ->show();
          dialog->get_vbox()->pack_start(*hb_shot, Gtk::PACK_SHRINK);

          dialog->add_button("Cancel", 0);
          dialog->add_button("Create", 1);
          dialog->add_button("Add",2 );
          dialog->set_default_response(2);



          result = dialog->run();
          int shot= c_shot->get_active_row_number();
          dialog->close();
          while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          if (result == 2)
            j->add_shot((Shot)shot);
        }
        if(result)
        _store.add_product(j);

      }
      else
      {
        Dialogs::message("Please Try again!!","Invalid Input");
        Mainwin::on_create_donut_click();
      }
    }
  }
  catch (std::exception& e)
  {
    std::string msg;
    msg  = e.what() ;
    msg += "\n Please Try again!!";
    Dialogs::message(msg,"Error");

  }



}
void Mainwin::on_create_donut_click()
{

  Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
  dialog->set_title("Create Donut");

  //creting name label and entry and putting it in hbox
  Gtk::HBox *hb_name = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_name = Gtk::manage(new Gtk::Label{"Name:"});
  l_name->set_width_chars(15);
  l_name -> show();
  hb_name->pack_start(*l_name,Gtk::PACK_SHRINK);

  Gtk::Entry *e_name = Gtk::manage(new Gtk::Entry{});
  e_name->set_max_length(50);
  e_name->show();
  hb_name->pack_start(*e_name,Gtk::PACK_SHRINK);
  hb_name ->show();
  dialog->get_vbox()->pack_start(*hb_name,Gtk::PACK_SHRINK);

  //creating Price
  Gtk::HBox *hb_price = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_price = Gtk::manage(new Gtk::Label{"Price:"});
  l_price->set_width_chars(15);
  l_price -> show();
  hb_price->pack_start(*l_price,Gtk::PACK_SHRINK);

  Gtk::Entry *e_price = Gtk::manage(new Gtk::Entry{});
  e_price->set_max_length(50);
  e_price->show();
  hb_price->pack_start(*e_price);
  hb_price ->show();
  dialog->get_vbox()->pack_start(*hb_price);

  //creating Cost

  Gtk::HBox *hb_cost = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_cost = Gtk::manage(new Gtk::Label{"Cost:"});
  l_cost->set_width_chars(15);
  l_cost -> show();
  hb_cost->pack_start(*l_cost,Gtk::PACK_SHRINK);

  Gtk::Entry *e_cost = Gtk::manage(new Gtk::Entry{});
  e_cost->set_max_length(50);
  e_cost->show();
  hb_cost->pack_start(*e_cost);
  hb_cost ->show();
  dialog->get_vbox()->pack_start(*hb_cost);

  //creating Frosting
  Gtk::HBox *hb_frosting = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_frosting = Gtk::manage(new Gtk::Label{"Frosting:"});
  l_frosting->set_width_chars(15);
  l_frosting -> show();
  hb_frosting->pack_start(*l_frosting,Gtk::PACK_SHRINK);

  Gtk::ComboBoxText *c_frosting = Gtk::manage(new Gtk::ComboBoxText{});
  c_frosting->set_size_request(160);
  c_frosting->append("Unfrosted");
  c_frosting->append("Choclate");
  c_frosting->append("Vanilla");
  c_frosting->append("Pink");
  c_frosting ->show();
  hb_frosting->pack_start(*c_frosting, Gtk::PACK_SHRINK);
  hb_frosting ->show();
  dialog->get_vbox()->pack_start(*hb_frosting, Gtk::PACK_SHRINK);
  //creting topping ComboBoxText
  Gtk::HBox *hb_filling = Gtk::manage(new Gtk::HBox{});
  Gtk::Label *l_filling = Gtk::manage(new Gtk::Label{"Filling:"});
  l_filling->set_width_chars(15);
  l_filling -> show();
  hb_filling->pack_start(*l_filling,Gtk::PACK_SHRINK);

  Gtk::ComboBoxText *c_filling = Gtk::manage(new Gtk::ComboBoxText{});
  c_filling->set_size_request(160);
  c_filling->append("Unfilled");
  c_filling->append("Creme");
  c_filling->append("Bavarian");
  c_filling->append("Strawberry");
  c_filling ->show();
  hb_filling->pack_start(*c_filling, Gtk::PACK_SHRINK);
  hb_filling ->show();
  dialog->get_vbox()->pack_start(*hb_filling, Gtk::PACK_SHRINK);

  Gtk::CheckButton *cb_add_sprinkles = Gtk::manage(new Gtk::CheckButton("Add Sprinkles"));
  cb_add_sprinkles ->show();
  dialog->get_vbox()->pack_start(*cb_add_sprinkles, Gtk::PACK_SHRINK);

  dialog->add_button("Cancel", 0);
  dialog->add_button("OK", 1);
  dialog->set_default_response(1);
  int result = dialog->run();
  std::string t_name = e_name->get_text();
  std::string t_price = e_price->get_text();
  std::string t_cost = e_cost->get_text();
  int frosting= c_frosting->get_active_row_number();
  int filling = c_filling->get_active_row_number();
  bool add_sprinkles = cb_add_sprinkles->get_active();
  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  try
  {
    std::regex r0 ("\\d\\d*(.\\d\\d*)?");
    std::regex r1 ("\\w((\\w)* *)*");
    if (result)
    {
      if (std::regex_match(t_name,r1)&& std::regex_match(t_price,r0) && std::regex_match(t_cost,r0) )
      {
        Donut *p1 = new Donut(t_name,std::stof(t_price),std::stof(t_cost),(Frosting)frosting,add_sprinkles,(Filling)filling);
        _store.add_product(p1);
      }
      else
      {
        Dialogs::message("Please Try again!!","Invalid Input");
        Mainwin::on_create_donut_click();
      }
    }
  }
  catch (std::exception& e)
  {
    std::string msg;
    msg  = e.what() ;
    msg += "\n Please Try again!!";
    Dialogs::message(msg,"Error");

  }
}
void Mainwin::on_new_customer_click()
{
  Gtk::HBox *hb_name = Gtk::manage(new Gtk::HBox{});

  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Create Customer");

  Gtk::Label *label_name = new Gtk::Label{"Name:"};
  label_name->set_width_chars(15);
  label_name -> show();
  hb_name->pack_start(*label_name,Gtk::PACK_SHRINK);

  dialog->add_button("Cancel", 0);
  dialog->add_button("OK", 1);
  dialog->set_default_response(1);

  Gtk::Entry *entry_name = new Gtk::Entry{};
  entry_name->set_max_length(50);
  entry_name->show();
  hb_name->pack_start(*entry_name);
  hb_name ->show();
  dialog->get_vbox()->pack_start(*hb_name);

  Gtk::HBox *hb_phone = new Gtk::HBox{};
  Gtk::Label *label_phone = new Gtk::Label("Phone:");
  label_phone->set_width_chars(15);
  hb_phone->pack_start(*label_phone, Gtk::PACK_SHRINK);
  label_phone->show();

  Gtk::Entry *entry_phone = new Gtk::Entry{};
  entry_phone->set_max_length(15);
  entry_phone->show();
  hb_phone->pack_start(*entry_phone,Gtk::PACK_SHRINK);
  hb_phone ->show();
  dialog->get_vbox()->pack_start(*hb_phone,Gtk::PACK_SHRINK);

  int result = dialog->run();
  std::string text_name = entry_name->get_text();
  std::string text_phone = entry_phone->get_text();
  std::regex r0 ("((\\([[:digit:]]{3}\\))|([[:digit:]]{3}-))?[[:digit:]]{3}-[[:digit:]]{4}");

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  delete entry_phone;
  delete label_phone;
  delete entry_name;
  delete label_name;
  delete dialog;
  Customer *c;
  if (result == 1)

  {
    if (std::regex_match(text_phone,r0))
    {
      try
      {
        c = new Customer(text_name,text_phone);
        _store.add_customer(c);
      }
      catch (std::exception &e)
      {

        Dialogs::message(e.what(), "Error");
      }
    }
    else
    {
      Dialogs::message("Invalid Phone Number", "Error");
      Mainwin::on_new_customer_click();
    }
  }



}
