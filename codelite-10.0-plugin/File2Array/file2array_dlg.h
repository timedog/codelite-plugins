///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __FILE2ARRAY_DLG_H__
#define __FILE2ARRAY_DLG_H__

#include "file2array_base_dlg.h"

///////////////////////////////////////////////////////////////////////////

class IManager;
///////////////////////////////////////////////////////////////////////////////
/// Class File2ArrayDlg
///////////////////////////////////////////////////////////////////////////////
class File2ArrayDlg : public File2ArrayBaseDlg 
{
    IManager* m_mgr;
	private:
        wxFileName  m_Filename;
        wxULongLong_t m_Offset;
        wxULongLong_t m_Size;
        
        int DoFile2Array(void);
        int GetOffsetAndSize(void);
	protected:
    
		void OnButtonOK( wxCommandEvent& event );
		
	
	public:
        //Getters
        const wxFileName& GetInputFileName() const {
            return m_Filename;
        }
        
		File2ArrayDlg( wxWindow* parent,IManager* mgr);
		~File2ArrayDlg();
	
};

#endif //__FILE2ARRAY_BASE_DLG_H__
