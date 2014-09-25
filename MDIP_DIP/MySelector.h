#pragma once

namespace MDIP_DIP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MySelector
	/// </summary>
	public ref class MySelector : public System::Windows::Forms::Form
	{
	public:
		MySelector(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MySelector(String^ explain)
		{
			InitializeComponent();
			this->explain->Text = explain;
		}
		String^ getcolord(){
			return valuein->Text;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MySelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  valuein;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  explain;



	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->valuein = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->explain = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// valuein
			// 
			this->valuein->Location = System::Drawing::Point(21, 101);
			this->valuein->Name = L"valuein";
			this->valuein->Size = System::Drawing::Size(213, 20);
			this->valuein->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(255, 93);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Select";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MySelector::button1_Click);
			// 
			// explain
			// 
			this->explain->AutoSize = true;
			this->explain->Location = System::Drawing::Point(29, 16);
			this->explain->Name = L"explain";
			this->explain->Size = System::Drawing::Size(40, 13);
			this->explain->TabIndex = 2;
			this->explain->Text = L"explain";
			// 
			// MySelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 161);
			this->Controls->Add(this->explain);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->valuein);
			this->Name = L"MySelector";
			this->Text = L"MySelector";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //valuein->Text = "";
				 this->Close();
			 }
	};
}
