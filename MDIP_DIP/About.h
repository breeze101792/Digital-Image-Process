#pragma once

namespace MDIP_DIP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for About
	/// </summary>
	public ref class About : public System::Windows::Forms::Form
	{
	public:
		About(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Students;
	protected: 
	private: System::Windows::Forms::Label^  Teacher;
	private: System::Windows::Forms::Label^  StudentTitle;
	private: System::Windows::Forms::Label^  MainTitle;
	private: System::Windows::Forms::Label^  Info;

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
			this->Students = (gcnew System::Windows::Forms::Label());
			this->Teacher = (gcnew System::Windows::Forms::Label());
			this->StudentTitle = (gcnew System::Windows::Forms::Label());
			this->MainTitle = (gcnew System::Windows::Forms::Label());
			this->Info = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Students
			// 
			this->Students->AutoSize = true;
			this->Students->Location = System::Drawing::Point(76, 245);
			this->Students->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->Students->Name = L"Students";
			this->Students->Size = System::Drawing::Size(307, 222);
			this->Students->TabIndex = 0;
			this->Students->Text = L"曾紹武\t10003141A\r\n李怡君\t10003075A\r\n方柏舜\t10003123A\r\n黃致凱\t10003054A\r\n張簡嘉慶10003129A\r\n郭弘裕\t10" 
				L"003403A";
			// 
			// Teacher
			// 
			this->Teacher->AutoSize = true;
			this->Teacher->Location = System::Drawing::Point(19, 107);
			this->Teacher->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->Teacher->Name = L"Teacher";
			this->Teacher->Size = System::Drawing::Size(314, 37);
			this->Teacher->TabIndex = 1;
			this->Teacher->Text = L"指導教授:林義隆教授";
			// 
			// StudentTitle
			// 
			this->StudentTitle->AutoSize = true;
			this->StudentTitle->Location = System::Drawing::Point(19, 181);
			this->StudentTitle->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->StudentTitle->Name = L"StudentTitle";
			this->StudentTitle->Size = System::Drawing::Size(154, 37);
			this->StudentTitle->TabIndex = 2;
			this->StudentTitle->Text = L"小組成員:";
			// 
			// MainTitle
			// 
			this->MainTitle->AutoSize = true;
			this->MainTitle->Location = System::Drawing::Point(124, 21);
			this->MainTitle->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->MainTitle->Name = L"MainTitle";
			this->MainTitle->Size = System::Drawing::Size(209, 37);
			this->MainTitle->TabIndex = 3;
			this->MainTitle->Text = L"影像處裡程式";
			// 
			// Info
			// 
			this->Info->AutoSize = true;
			this->Info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Info->Location = System::Drawing::Point(112, 566);
			this->Info->Margin = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->Info->Name = L"Info";
			this->Info->Size = System::Drawing::Size(333, 26);
			this->Info->TabIndex = 4;
			this->Info->Text = L"V0.9.9.2 Release Date:1/14/2014";
			// 
			// About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(19, 37);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 601);
			this->Controls->Add(this->Info);
			this->Controls->Add(this->MainTitle);
			this->Controls->Add(this->StudentTitle);
			this->Controls->Add(this->Teacher);
			this->Controls->Add(this->Students);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(10, 9, 10, 9);
			this->Name = L"About";
			this->Text = L"About";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
