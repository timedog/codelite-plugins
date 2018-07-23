#include "file2array.h"
#include "file2array_dlg.h"
#include <wx/xrc/xmlres.h>
#include <wx/menu.h>

static File2Array* thePlugin = NULL;

// Internal events used by this plugin
const wxEventType CR_file2array_menu      = wxNewEventType();

//Define the plugin entry point
CL_PLUGIN_API IPlugin *CreatePlugin(IManager *manager)
{
    if (thePlugin == 0)
    {
        thePlugin = new File2Array(manager);
    }
    return thePlugin;
}

CL_PLUGIN_API PluginInfo *GetPluginInfo()
{
    static PluginInfo info;
    info.SetAuthor(wxT("jiangyongma"));
    info.SetName(wxT("File2Array"));
    info.SetDescription(wxT("Convert file to c array"));
    info.SetVersion(wxT("v1.0"));
    return &info;
}

CL_PLUGIN_API int GetPluginInterfaceVersion()
{
    return PLUGIN_INTERFACE_VERSION;
}

File2Array::File2Array(IManager *manager)
    : IPlugin(manager)
{
    m_longName = wxT("Convert file to c array");
    m_shortName = wxT("File2Array");
}

File2Array::~File2Array()
{
}

clToolBar *File2Array::CreateToolBar(wxWindow *parent)
{
    // Create the toolbar to be used by the plugin
    clToolBar *tb(NULL);

    return tb;
}

void File2Array::CreatePluginMenu(wxMenu *pluginsMenu)
{
    wxMenuItem *item(NULL);
    item = new wxMenuItem(pluginsMenu, CR_file2array_menu, wxT("File2Array"), wxEmptyString, wxITEM_NORMAL);
    pluginsMenu->Append(item);
    
// connect events
	wxTheApp->Connect(CR_file2array_menu, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(File2Array::OnConvert), NULL, this);
}

void File2Array::UnPlug()
{
    //TODO:: perform the unplug action for this plugin
}

void File2Array::OnConvert(wxCommandEvent& e)
{
	// pop up the options dialog
	File2ArrayDlg *dlg = new File2ArrayDlg(m_mgr->GetTheApp()->GetTopWindow(),m_mgr);
	dlg->ShowModal();
	dlg->Destroy();
}
