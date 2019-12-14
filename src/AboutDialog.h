/**********************************************************************

  Audacity: A Digital Audio Editor

  AboutDialog.h

  Dominic Mazzoni

**********************************************************************/

#ifndef __AUDACITY_ABOUT_DLG__
#define __AUDACITY_ABOUT_DLG__

#include <vector>
#include "widgets/wxPanelWrapper.h" // to inherit

class wxStaticBitmap;

class ShuttleGui;

struct AboutDialogCreditItem {
   AboutDialogCreditItem( TranslatableString str, int r )
      : description{ std::move( str ) }, role{ r }
   {}
   TranslatableString description;
   int role;
};

using AboutDialogCreditItemsList = std::vector<AboutDialogCreditItem>;

class AboutDialog final : public wxDialogWrapper {
   DECLARE_DYNAMIC_CLASS(AboutDialog)

 public:
   AboutDialog(wxWindow * parent);
   virtual ~ AboutDialog();

   static AboutDialog *ActiveIntance();

   void OnOK(wxCommandEvent & event);

   wxStaticBitmap *icon;

   DECLARE_EVENT_TABLE()

 private:
   enum Role {
      roleTeamMember,
      roleEmeritusTeam,
      roleDeceased,
      roleContributor,
      roleGraphics,
      roleLibrary,
      roleThanks
   };

   AboutDialogCreditItemsList creditItems;
   void PopulateAudacityPage( ShuttleGui & S );
   void PopulateLicensePage( ShuttleGui & S );
   void PopulateInformationPage (ShuttleGui & S );

   void CreateCreditsList();
   void AddCredit( const wxString &name, Role role );
   void AddCredit( const wxString &name, TranslatableString format, Role role );
   wxString GetCreditsByRole(AboutDialog::Role role);

   void AddBuildinfoRow( wxString* htmlstring, const wxChar * libname, const wxChar * libdesc, const wxString &status);
   void AddBuildinfoRow( wxString* htmlstring, const wxChar * libname, const wxChar * libdesc);
};

#endif
