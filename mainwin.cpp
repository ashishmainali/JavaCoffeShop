    #include "mainwin.h"
    Mainwin::~Mainwin() 
    {
      _store.free_products();
     }
    Mainwin::Mainwin()
    {
      set_default_size(700, 400);
      Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
      add(*vbox);
      //CRETING MENU BAR "menubar"
      Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
      vbox->pack_start(*menubar,Gtk::PACK_SHRINK, 0);

      //F I L E       M E N U

      Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
      menubar->append(*menuitem_file);

      Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
      menuitem_file->set_submenu(*filemenu);

      Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
      menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_load_click));
      filemenu->append(*menuitem_load);

      Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
      menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_save_click));
      filemenu->append(*menuitem_save);

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

      Gtk::MenuItem *menuitem_view_all_orders = Gtk::manage(new Gtk::MenuItem("_Orders",true));
      menuitem_view_all_orders->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_orders_click));
      viewmenu->append (*menuitem_view_all_orders);

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

      Gtk::MenuItem *menuitem_new_order = Gtk::manage (new Gtk::MenuItem("_New Order",true));
      createmenu->append(*menuitem_new_order);
      menuitem_new_order->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));





      Gtk::MenuItem *menuitem_process = Gtk::manage (new Gtk::MenuItem("_Process",true));
      menubar->append (*menuitem_process);

      Gtk::Menu *processmenu = Gtk::manage(new Gtk::Menu());
      menuitem_process ->set_submenu (*processmenu);

      //  P   R   O   C   E   S   S           F I L L
      Gtk::MenuItem *menuitem_order_fill = Gtk::manage (new Gtk::MenuItem("_Fill",true));
      processmenu->append(*menuitem_order_fill);
      menuitem_order_fill->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_order_fill_click));
      //  P   R   O   C   E   S   S           P A Y
      Gtk::MenuItem *menuitem_order_pay = Gtk::manage (new Gtk::MenuItem("_Pay",true));
      processmenu->append(*menuitem_order_pay);
      menuitem_order_pay->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_order_pay_click));
          //  P   R   O   C   E   S   S       D I S C A R D 
      Gtk::MenuItem *menuitem_order_discard = Gtk::manage (new Gtk::MenuItem("_Discard",true));
      processmenu->append(*menuitem_order_discard);
      menuitem_order_discard->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_order_discard_click));









      // H E L P
      // Create a Help menu and add to the menu bar
      Gtk::MenuItem *menuitem_help =
      Gtk::manage(new Gtk::MenuItem("_Help", true));
      menubar->append(*menuitem_help);
      Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
      menuitem_help->set_submenu(*helpmenu);
      // A B O U T
      // Append About to the Help menu
      Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
      menuitem_about->signal_activate().connect(
      sigc::mem_fun(*this, &Mainwin::on_about_click));
      helpmenu->append(*menuitem_about);





        // /////////////
        // T O O L B A R
        // Add a toolbar to the vertical box below the menu
        Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
        vbox->add(*toolbar);

        //     Add Donut
        // Add a new icon


        Gtk::Image *create_donut = Gtk::manage(new Gtk::Image{"logo/create_donut.png"});
         create_donut->set_pixel_size(-1);
        Gtk::ToolButton *tb_create_donut = Gtk::manage(new Gtk::ToolButton(*create_donut));
        tb_create_donut->set_tooltip_markup("Create a new Donut");
        tb_create_donut->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
        toolbar->append(*tb_create_donut);

        Gtk::Image *create_coffee = Gtk::manage(new Gtk::Image{"logo/create_coffee.png"});
        create_coffee->set_pixel_size(-1);
        Gtk::ToolButton *tb_create_coffee = Gtk::manage(new Gtk::ToolButton(*create_coffee));
        tb_create_coffee->set_tooltip_markup("Create a new coffee");
        tb_create_coffee->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
        toolbar->append(*tb_create_coffee);

        Gtk::Image *create_order = Gtk::manage(new Gtk::Image{"logo/create_order.png"});
        create_order->set_pixel_size(-1);
        Gtk::ToolButton *tb_create_order = Gtk::manage(new Gtk::ToolButton(*create_order));
        tb_create_order->set_tooltip_markup("Create a new order");
        tb_create_order->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_create_order_click));
        toolbar->append(*tb_create_order);

        Gtk::Image *new_customer = Gtk::manage(new Gtk::Image{"logo/add_customer.png"});
        new_customer->set_pixel_size(-1);
        Gtk::ToolButton *tb_new_customer = Gtk::manage(new Gtk::ToolButton(*new_customer));
        tb_new_customer->set_tooltip_markup("Add Customer");
        tb_new_customer->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));
        toolbar->append(*tb_new_customer);

        Gtk::SeparatorToolItem *sep0 = Gtk::manage(new Gtk::SeparatorToolItem());
        toolbar->append(*sep0);
       


        Gtk::Image *view_all_product = Gtk::manage(new Gtk::Image{"logo/view_all_products.png"});
        Gtk::ToolButton *tb_view_all_product = Gtk::manage(new Gtk::ToolButton(*view_all_product));
        tb_view_all_product->set_tooltip_markup("View All Products");
        tb_view_all_product->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
        toolbar->append(*tb_view_all_product);

        Gtk::Image *list_customers = Gtk::manage(new Gtk::Image{"logo/list_customers.png"});
        Gtk::ToolButton *tb_list_customers = Gtk::manage(new Gtk::ToolButton(*list_customers));
        tb_list_customers->set_tooltip_markup("List All Customers");
        tb_list_customers->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
        toolbar->append(*tb_list_customers);

        Gtk::Image *view_orders = Gtk::manage(new Gtk::Image{"logo/view_orders.png"});
        Gtk::ToolButton *tb_view_orders = Gtk::manage(new Gtk::ToolButton(*view_orders));
        tb_view_orders->set_tooltip_markup("View all Order");
        tb_view_orders->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_view_orders_click));
        toolbar->append(*tb_view_orders);

        Gtk::SeparatorToolItem *sep3 = Gtk::manage(new Gtk::SeparatorToolItem());
        toolbar->append(*sep3);


        Gtk::Image *about = Gtk::manage(new Gtk::Image{"logo/about.png"});
        Gtk::ToolButton *tb_about = Gtk::manage(new Gtk::ToolButton(*about));
        tb_about->set_tooltip_markup("About");
        tb_about->signal_clicked().connect(sigc::mem_fun(*this, &Mainwin::on_about_click));
        toolbar->append(*tb_about);

        
        Gtk::Label* expand = new Gtk::Label();
        expand->set_vexpand(true);
        vbox ->pack_start(*expand);

        Gtk::HBox *hb_statusbar = new Gtk::HBox{};
        Gtk::Label *space = new Gtk::Label{};
        space->set_width_chars(10);
        hb_statusbar->pack_start(*space);

        msg = Gtk::manage(new Gtk::Label());
        msg->set_hexpand(true);
        //msg ->set_text(_status_bar);
        msg ->show();
        msg->set_hexpand(true);

        hb_statusbar ->pack_start(*msg);

        std::stringstream strs;
        strs << std::setprecision(2)<<_store.get_cash();
        l_cash ->set_text("Total Cash: $"+ strs.str());

        l_cash->show();
        hb_statusbar->pack_start(*l_cash);

        vbox->add(*hb_statusbar);
        


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

    void Mainwin::on_view_orders_click()
    {
      if (_store.number_of_orders() == 0)
        Dialogs::message("There are no orders","Empty");
      else
      {  
        std::string order_info = "Select an Order" ;
        int result;
        Gtk::Dialog *dialog = new Gtk::Dialog();
          dialog->set_title("View Order");
          Gtk::HBox *hb_order = new Gtk::HBox{};
      
      
          Gtk::Label *l_order_info = new Gtk::Label{};
          l_order_info -> show();
          dialog->get_vbox() ->pack_start(*l_order_info,Gtk::PACK_SHRINK);
      
      
          Gtk::Label *l_order = new Gtk::Label{"Order:"};
          l_order ->set_width_chars(15);
          l_order -> show();
          hb_order ->pack_start(*l_order,Gtk::PACK_SHRINK);
      
          Gtk::ComboBoxText *cb_orders = new Gtk::ComboBoxText{};
          cb_orders->set_size_request(300);

          for (int i = 1 ; i <= _store.number_of_orders() ; ++i )
            cb_orders->append(std::to_string(i));

          cb_orders ->show();
          hb_order -> pack_start(*cb_orders,Gtk::PACK_SHRINK);
          hb_order->show();
          dialog->get_vbox()->pack_start(*hb_order,Gtk::PACK_SHRINK);
      
          dialog->add_button("Close", 0);
          dialog->add_button("Show", 1);
          do{
          result = dialog->run();
          int order_id= cb_orders->get_active_row_number()+1;
          dialog->close();
          while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          l_order_info ->set_text(_store.order_to_string(order_id));
          
         } while ( result == 1);
      }
    }




    void Mainwin::on_create_order_click()
    {
      int result;
      int display_order_number;
      int productid;
      if ( _store.number_of_products() != 0 && _store.number_of_customers()!= 0)
          {
             std::vector <int> temp_productid;
                 
              
               display_order_number= _store.last_order();
          
              std::string order_text = "Order No: " + std::to_string(display_order_number) + "\n";
              std::string current_order;
          
              Gtk::Dialog *dialog = new Gtk::Dialog();
              dialog->set_title("Create Order");
          
          
              Gtk::VBox *vb_order = new Gtk::VBox{};
          
              Gtk::Label *l_order_number = new Gtk::Label{order_text};
              l_order_number->set_width_chars(15);
              l_order_number -> show();
              vb_order->pack_start(*l_order_number,Gtk::PACK_SHRINK);
          
              Gtk::Label *l_space = new Gtk::Label{};
              vb_order->pack_start(*l_space,Gtk::PACK_SHRINK);
          
              Gtk::Label *l_order_list = new Gtk::Label{};
              l_order_list -> set_text(current_order);
              l_order_list ->show();
              vb_order->pack_start(*l_order_list,Gtk::PACK_SHRINK);
          
          
              Gtk::ComboBoxText *cb_products = new Gtk::ComboBoxText{};
              cb_products->set_size_request(300);
          
              for (int i = 0 ; i < _store.number_of_products() ; ++i )
              cb_products->append((std::to_string(i+1) + ". " + _store.get_product(i)->to_string()));
              cb_products ->show();
          
              dialog->add_button("Cancel", 0);
              dialog->add_button("Add", 1);
              dialog->add_button("Next",2 );
              dialog->set_default_response(2);
          
              vb_order->pack_start(*cb_products, Gtk::PACK_SHRINK);
              vb_order ->show();
              dialog->get_vbox()->pack_start(*vb_order, Gtk::PACK_SHRINK);
              do
            {
              l_order_list -> set_text(current_order);
              result = dialog->run();
              productid= cb_products->get_active_row_number();
              dialog->close();
              while (Gtk::Main::events_pending())  Gtk::Main::iteration();
              if (result)
              {
                temp_productid.push_back(productid);
                current_order += _store.get_product(productid)->to_string() + "\n";
          
              }

          
            }while ( result ==1);

          
            delete dialog;
            delete vb_order;
            delete l_space;
            delete l_order_list;
            delete l_order_number;
            delete cb_products;
            


            if (result == 2 )
            {
              Gtk::Dialog *dialog = new Gtk::Dialog();
              dialog->set_title("Select Customer");
          
              dialog->add_button("Cancel", 0);
              dialog->add_button(("Place Order " + std::to_string(display_order_number)),1 );
          
              Gtk::ComboBoxText *cb_customers = new Gtk::ComboBoxText{};
              cb_customers->set_size_request(180);
              for (int i = 0 ; i <_store.number_of_customers() ; ++i )
              cb_customers->append((i+1 + ". " +_store.customer_to_string(i)));
              cb_customers ->show();
              dialog->get_vbox()->pack_start(*cb_customers, Gtk::PACK_SHRINK);
              result = dialog->run();
              int customer_id= cb_customers->get_active_row_number();
              dialog->close();
              while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          
              if (result == 1)
              {
                //Dialogs::message("Successful","Hurray!!");
                Order *_current_order = new Order();
                for ( int i = 0; i < temp_productid.size(); i++)
                    _current_order->add_product(_store.get_product(temp_productid[i]));
                int order_number = _store.place_order(*_current_order,customer_id);
                Dialogs::message (("Order No" + std::to_string(order_number) + " Placed"),"Successful");
                
              }
              
              }
          
            
          }
          else
              Dialogs::message("No Products or Customers","Error");
    }
    //


    void Mainwin::on_save_click()
    {

      std::ofstream ofs{"data.txt"};
      if (ofs) _store.save(ofs);
        Dialogs::message("save Complete");;



    }

    void Mainwin::on_load_click()
    {
      std::ifstream ifs{"data.txt"};
      if (ifs)
      _store.load(ifs);
      Dialogs::message("Load Complete");
    }


     void Mainwin::on_order_fill_click()
     {
      this->process_order(Action::Fill);
     }
      void Mainwin::on_order_pay_click()
      {
        this->process_order(Action::Pay);
      }
      void Mainwin::on_order_discard_click()
      {
        this->process_order(Action::Discard);
      }

      void Mainwin::process_order(Action x)
      {
        if (_store.number_of_orders() == 0)
        Dialogs::message("There are no orders","Empty");
      else
      {  
        std::string order_info = "Select an Order" ;
        int result,order_id;
        Gtk::Dialog *dialog = new Gtk::Dialog();
          dialog->set_title("View Order");
          Gtk::HBox *hb_order = new Gtk::HBox{};
      
      
          Gtk::Label *l_order_info = new Gtk::Label{};
          l_order_info -> show();
          dialog->get_vbox() ->pack_start(*l_order_info,Gtk::PACK_SHRINK);
      
      
          Gtk::Label *l_order = new Gtk::Label{"Order:"};
          l_order ->set_width_chars(15);
          l_order -> show();
          hb_order ->pack_start(*l_order,Gtk::PACK_SHRINK);
      
          Gtk::ComboBoxText *cb_orders = new Gtk::ComboBoxText{};
          cb_orders->set_size_request(300);

          for (int i = 1 ; i <= _store.number_of_orders() ; ++i )
            cb_orders->append(std::to_string(i));

          cb_orders ->show();
          hb_order -> pack_start(*cb_orders,Gtk::PACK_SHRINK);
          hb_order->show();
          dialog->get_vbox()->pack_start(*hb_order,Gtk::PACK_SHRINK);
      
          dialog->add_button("Close", 0);
          dialog->add_button("Show", 1);
          switch (x)
          {
          case 0: dialog -> add_button("Fill",2);break;
          case 1: dialog -> add_button("Discard",2);break;
          case 2: dialog -> add_button("PAY",2);break;
          }
          do{
          result = dialog->run();
          order_id= cb_orders->get_active_row_number()+1;
          dialog->close();
          while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          l_order_info ->set_text(_store.order_to_string(order_id));
          
         } while ( result == 1);

         if (result == 2)
         {
          try
{
         switch (x)
          {
          case 0: _store.fill_order(order_id);break;
          case 1: _store.discard_order(order_id);break;
          case 2:  std::stringstream strs;
                  strs << std::setprecision(2)<< _store.pay_order(order_id);
                  l_cash ->set_text("Total Cash: $"+ strs.str());

                   break;
          }
          }
          catch (std::exception &e)
            {
              Dialogs::message(e.what(),"Error");
            }
        }
      }

        
      }



