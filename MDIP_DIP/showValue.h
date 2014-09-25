#pragma once

namespace MDIP_DIP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for showValue
	/// </summary>
	public ref class showValue : public System::Windows::Forms::Form
	{
	public:
		showValue(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		showValue(int **img,int height,int width)
		{
			InitializeComponent();
			show(img,height,width);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~showValue()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  textAera;
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
			this->textAera = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// textAera
			// 
			this->textAera->Location = System::Drawing::Point(12, 12);
			this->textAera->Name = L"textAera";
			this->textAera->Size = System::Drawing::Size(819, 702);
			this->textAera->TabIndex = 0;
			this->textAera->Text = L"";
			// 
			// showValue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 726);
			this->Controls->Add(this->textAera);
			this->Name = L"showValue";
			this->Text = L"showValue";
			this->ResumeLayout(false);

		}
#pragma endregion
	public:void show(int **img,int height,int width)
		   {
			   for(int i = 0,j;i < 3;i++){
				   for(j = 0;j < width * height;j++){
					   textAera->Text += *(*(img + i) + j);
					   textAera->Text += (j % width == width - 1 ? "\n":",\t");
				   }
				   textAera->Text += '\n';
			   }
		   }
	};
}
