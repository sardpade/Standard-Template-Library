//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tmpnam.h"
#include <iostream>
#include <cstdio>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    using namespace std;
    Edit1->Text = TMP_MAX;
    Edit2->Text = L_tmpnam;
    Timer1->Enabled = true;
    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{      using namespace std;
    char pszName[L_tmpnam] = {'\0'};
    tmpnam(pszName);
     Memo1->Lines->Add(pszName);
}
//---------------------------------------------------------------------------
