#ifndef __File2Array__
#define __File2Array__

#include "plugin.h"

class File2Array : public IPlugin
{
public:
    File2Array(IManager *manager);
    ~File2Array();

    //--------------------------------------------
    //Abstract methods
    //--------------------------------------------
    virtual clToolBar *CreateToolBar(wxWindow *parent);
    /**
     * @brief Add plugin menu to the "Plugins" menu item in the menu bar
     */
    virtual void CreatePluginMenu(wxMenu *pluginsMenu);
    
    /**
     * @brief Unplug the plugin. Perform here any cleanup needed (e.g. unbind events, destroy allocated windows)
     */
    virtual void UnPlug();
    
    // event handlers
    void OnConvert(wxCommandEvent &e);
};

#endif //File2Array
