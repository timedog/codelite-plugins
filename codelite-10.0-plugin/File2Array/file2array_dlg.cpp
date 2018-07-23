#include "file2array_dlg.h"
#include <wx/msgdlg.h>
#include "imanager.h"


File2ArrayDlg::File2ArrayDlg(wxWindow* parent,IManager* mgr)
        : File2ArrayBaseDlg( parent )
        , m_mgr(mgr)
        , m_Offset(0)
        , m_Size(0)
{
    Centre();
}

void File2ArrayDlg::OnButtonOK(wxCommandEvent& event)
{
    wxUnusedVar( event );
    
    m_Filename = m_filePicker2->GetFileName();
    
    if( wxFileName::FileExists(m_Filename.GetFullPath()) )
    {
        DoFile2Array();
    }
    else
    {
        //wxLogMessage(wxT("INFO : Select file:Not exist"));
    }
    
    EndModal(wxID_OK);
}

File2ArrayDlg::~File2ArrayDlg()
{
}

int File2ArrayDlg::GetOffsetAndSize(void)
{
    long offset, size;
    wxString strOffset, strSize;

    strOffset = m_textCtrl_Offset->GetLineText(0);
    strSize   = m_textCtrl_Size->GetLineText(0);
    
    //wxLogMessage(wxT("INFO : %s,%s"),strOffset,strSize);
    
    if(strOffset.IsEmpty())
        offset = 0;
    else
    {
        strOffset = strOffset.Trim();
        strOffset = strOffset.Trim(false);
        if(!strOffset.ToLong(&offset, 16))
            return -1;
    }
    
    if(strSize.IsEmpty())
    {
        size = 0;
        //wxLogMessage(wxT("EMPTY : %s,%s"),strOffset,strSize);
    }
    else
    {
        strSize = strSize.Trim();
        strSize = strSize.Trim(false);
        //wxLogMessage(wxT("ToLong : %s,%s"),strOffset,strSize);
        if(!strSize.ToLong(&size))
            return -1;
    }
    
    m_Offset = offset;
    m_Size   = size;
    //wxLogMessage(wxT("INFO : 0x%x,%d"),m_Offset,m_Size);
    return 0;
}

int File2ArrayDlg::DoFile2Array(void)
{
    int res = -1;
    wxFile srcFile;
    const ssize_t line_iterms = 16;
    const ssize_t cache_size  = 100 * 1024;
    
    wxByte *cache = new wxByte[cache_size];
    if(!cache)
    {
        wxMessageBox(wxT("No memory for cache"),wxT("CodeLite"),wxICON_WARNING|wxOK);
        goto out;
    }
    
    if(GetOffsetAndSize() < 0)
    {
        wxMessageBox(wxT("Invalid \"Offset\" or \"Size\"."),wxT("CodeLite"),wxICON_WARNING|wxOK);
        goto out;
    }
    
    if(srcFile.Open(m_Filename.GetFullPath(), wxFile::read))
    {
        ssize_t use_bytes  = 0;
        int rate = 0;
        ssize_t file_size = srcFile.Length();
        
        if(!file_size)
        {
            wxMessageBox(wxT("Invalid \"Offset\" or \"Size\"."),wxT("CodeLite"),wxICON_WARNING|wxOK);
            goto out;
        }
        
        if(m_Offset >= file_size)
        {
            wxMessageBox(wxT("Invalid \"Offset\"."),wxT("CodeLite"),wxICON_WARNING|wxOK);
            goto out;
        }
        
        if(!m_Size) m_Size = file_size - m_Offset;
        
        if((m_Offset + m_Size) > file_size)
        {
            wxMessageBox(wxT("\"Offset\" add \"Size\" too large."),wxT("CodeLite"),wxICON_WARNING|wxOK);
            goto out;
        }
        
        srcFile.Seek(m_Offset);
        
        IEditor *editor = m_mgr->NewEditor();
        editor->SetLexerName(wxT("C++"));
        
        wxString strOutput("");

        if(editor)
        {
            strOutput << wxT("unsigned char data[] = {\n");
            
            for(;use_bytes < m_Size;)
            {
                wxByte *p  = cache;
                ssize_t u = srcFile.Read(p,cache_size);
                
                if(u == wxInvalidOffset)
                    break;
                
                for(;u > 0;)
                {
                    ssize_t u1 = (u < line_iterms) ? u : line_iterms;
                    
                    strOutput << wxT("    ");
                    for(ssize_t l = 0;l < u1;l++)
                    {
                        strOutput << wxString::Format(wxT("0x%02X, "),*p++);
                    }
                    strOutput << wxT("\n");
                    
                    u -= u1;
                    use_bytes += u1;
                }
                
                rate = use_bytes * m_gauge1->GetRange() / m_Size;
                m_gauge1->SetValue(rate);
            }
            
            strOutput << wxT("\n};\n");
            editor->AppendText(wxString::Format(wxT("// data from %s, offset 0x%x\n"), m_Filename.GetFullName(), m_Offset));
            editor->AppendText(wxString::Format(wxT("// array size : %d Byte\n"), use_bytes));
            editor->AppendText(strOutput);
        }
    }
    else
    {
        wxMessageBox(wxString::Format(wxT("Couldn't open %s."),m_Filename.GetFullName()),wxT("CodeLite"),wxICON_WARNING|wxOK);
        goto out;
    }
    
out:
    srcFile.Close();
    delete cache;
    return res;
}
