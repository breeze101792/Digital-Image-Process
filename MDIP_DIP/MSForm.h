#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace MDIP_DIP {

	/// <summary>
	/// SForm 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	//ref class Form1;

	public ref class MSForm : public System::Windows::Forms::Form
	{
	public:
		MSForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//

		}
		MSForm(System::String ^title)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			this->Text = title;
		}

	internal:
		Bitmap^ pBitmap;
	internal:
		ToolStripStatusLabel^ pf1;

	private:
		int w, h;

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MSForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(256, 233);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MSForm::pictureBox1_MouseMove);
			//			this->pictureBox1->Click += gcnew System::EventHandler(this, &MSForm::pictureBox1_Click);
			// 
			// MSForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 233);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MSForm";
			this->Text = L"SForm";
			this->Load += gcnew System::EventHandler(this, &MSForm::SForm_Load);
			//			this->Activated += gcnew System::EventHandler(this, &MSForm::MSForm_Activated);
			//			this->Click += gcnew System::EventHandler(this, &MSForm::MSForm_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void SForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 bmp_dip(pBitmap, pictureBox1);
				 pf1->Text = "(Width,Height)=("+ pBitmap->Width +","+ pBitmap->Height +")";
				 w = pBitmap->Width;
				 h = pBitmap->Height;
			 }

	private:Void bmp_dip(Bitmap^ pBitmap, PictureBox^ pictureBox1)
			{
				this->Width = pBitmap->Width + (this->Width - this->ClientRectangle.Width);
				this->Height = pBitmap->Height + (this->Height - this->ClientRectangle.Height);
				pictureBox1->Image = pBitmap;
				pictureBox1->Width = pBitmap->Width;
				pictureBox1->Height = pBitmap->Height;
			}

	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 int rw = (this->Width - pBitmap->Width) / 2 - 8, rh = (this->Height - pBitmap->Height) / 2 - 20;
				 if(e->X >= rw && e->Y >= rh && e->X < pBitmap->Width + rw && e->Y < pBitmap->Height + rh){
					 Color^ pixel = pBitmap->GetPixel(e->X - rw, e->Y - rh);
					 pf1->Text = "(" + (e->X - rw) + "," + (e->Y - rh) + ")" +
						 "=(" + pixel->R.ToString() + "," + pixel->G.ToString() + "," + pixel->B.ToString() + ")"; 
				 }
				 else{
					 pf1->Text = "(" + e->X + "," + e->Y + ")" + "=(" + 0 + "," + 0 + "," + 0 + ")";
				 }
			 }
			 /*	private: System::Void MSForm_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
			 private: System::Void MSForm_Activated(System::Object^  sender, System::EventArgs^  e) {

			 }
			 private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }*/
	};
}
